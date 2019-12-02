#include "mapwindow.hh"
#include "ui_mapwindow.h"
#include <iostream>
#include <string>

#include "graphics/simplemapitem.h"
#include "core/worldgenerator.h"
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <math.h>



MapWindow::MapWindow(QWidget *parent,
                     std::shared_ptr<Course::iGameEventHandler> handler):
    QMainWindow(parent),
    m_ui(new Ui::MapWindow),
    m_GEHandler(handler),
    m_gamescene(new Student::GameScene(this)),
    gameEventHandler(std::make_shared<Student::GameEventHandler>()),
    objectManager(std::make_shared<Student::ObjectManager>()),
    player1(std::make_shared<Student::Player>("Player 1")),
    player2(std::make_shared<Student::Player>("Player 2")),
    last_clicked_tile(Course::Coordinate(0,0))
{
    m_ui->setupUi(this);

    Student::GameScene* sgs_rawptr = m_gamescene.get();

    m_ui->graphicsView->setScene(dynamic_cast<QGraphicsScene*>(sgs_rawptr));


    connect(m_gamescene.get(), &Student::GameScene::sendtileid,
                this, &MapWindow::print_tile_info);

    connect(m_gamescene.get(), &Student::GameScene::sendtileid,
                this, &MapWindow::save_activate_tile);




    Course::WorldGenerator& worldGen = Course::WorldGenerator::getInstance();
    worldGen.addConstructor<Course::Forest>(1);
    worldGen.addConstructor<Course::Grassland>(1);
    worldGen.addConstructor<Student::Desert>(1);
    worldGen.generateMap(20,15,312, objectManager, gameEventHandler);

    current_player = player1; //Kumpi pelaajista aloittaa.

    update_player_resources(); //Resurssit nakyviin heti pelin alkaessa.
}

MapWindow::~MapWindow()
{
    delete m_ui;
}

void MapWindow::setGEHandler(
        std::shared_ptr<Course::iGameEventHandler> nHandler)
{
    m_GEHandler = nHandler;
}

void MapWindow::setSize(int width, int height)
{
    m_gamescene->setSize(width, height);
}

void MapWindow::setScale(int scale)
{
    m_gamescene->setScale(scale);
}

void MapWindow::resize()
{
    m_gamescene->resize();
}

void MapWindow::updateItem(std::shared_ptr<Course::GameObject> obj)
{
    m_gamescene->updateItem(obj);
}

void MapWindow::update_player_resources()
{
    Course::ResourceMap resources = current_player->get_player_resources();

    m_ui->MoneyPlayerLabel->setText
            (QString::number(resources[Course::BasicResource::MONEY]));

    m_ui->FoodPlayerLabel->setText
            (QString::number(resources[Course::BasicResource::FOOD]));

    m_ui->WoodPlayerLabel->setText
            (QString::number(resources[Course::BasicResource::WOOD]));

    m_ui->StonePlayerLabel->setText
            (QString::number(resources[Course::BasicResource::STONE]));

    m_ui->OrePlayerLabel->setText
            (QString::number(resources[Course::BasicResource::ORE]));
}

void MapWindow::add_new_worker(std::shared_ptr<Course::WorkerBase> worker, Course::ResourceMap cost)
{
    std::shared_ptr<Course::TileBase> tile = objectManager->getTile(last_clicked_tile);

    try {
        //(Pelaajalla on varaa workeriin) JA (pelaaja omistaa tilen TAI kukaan ei omista).
        if(current_player->does_have_enough_resources(cost) &&
                (tile->getOwner() == current_player || tile->getOwner() == nullptr))
        {
            tile->setOwner(current_player);
            tile->addWorker(worker);

            //Maksu workerista, vahennetaan pelaajalta resursseja.
            for (auto resource : cost)
            {
                gameEventHandler->modifyResource
                        (current_player,resource.first,-resource.second);
            }

            update_player_resources();
            drawItem(worker);
            print_tile_info(last_clicked_tile); //Tilen inffot ajantasalle.
            m_ui->graphicsView->viewport()->update();
        }
    } catch (Course::IllegalAction) {
        m_ui->statusLabel->setText("There is no space for more workers!");
    }
}

void MapWindow::add_new_building(std::shared_ptr<Course::BuildingBase> building, Course::ResourceMap cost)
{
    std::shared_ptr<Course::TileBase> tile = objectManager->getTile(last_clicked_tile);

    try {
        //(Pelaajalla on varaa rakennukseen) JA (pelaaja omistaa tilen TAI kukaan ei omista).
        if(current_player->does_have_enough_resources(cost) &&
                (tile->getOwner() == current_player || tile->getOwner() == nullptr))
        {
            tile->setOwner(current_player);
            tile->addBuilding(building);
            //Maksu rakennuksesta, vahennetaan pelaajalta resursseja.
            for (auto resource : cost)
            {
                gameEventHandler->modifyResource
                        (current_player,resource.first,-resource.second);
            }
            update_player_resources();
            drawItem(building);
            print_tile_info(last_clicked_tile); //Tilen inffot ajantasalle.
            m_ui->graphicsView->viewport()->update();
        }

    } catch (Course::IllegalAction) {
        m_ui->statusLabel->setText("There is no space for more buildings!");
    }
}

void MapWindow::draw_tiles(int tile_count)
{

    for(unsigned int i = 0; i < tile_count; i++)
    {
           auto item = objectManager->getTile(i);
           drawItem(item);
    }
}

void MapWindow::print_tile_info(Course::Coordinate coordinates)
{

    auto tile = objectManager->getTile(coordinates);

    std::string tile_type = (tile->getType());
    QString q_tile_type = QString::fromStdString(tile_type);
    int y_coord = tile->getCoordinate().y();
    int x_coord = tile->getCoordinate().x();

    std::vector<std::shared_ptr<Course::BuildingBase>> buildings =
            tile->getBuildings();
    std::vector<std::shared_ptr<Course::WorkerBase>> workers =
            tile->getWorkers();

    m_ui->InfoText->setText("Owner: ");

    m_ui->TileTypeLabel->setText(q_tile_type + "  ("+QString::number(x_coord)+
                                 "," + QString::number(y_coord)+")");

    if (tile->getOwner() == nullptr)
    {
       QString q_owner = "No owner";
       m_ui->InfoText->append(q_owner);
    } else
    {
        std::string owner = tile->getOwner()->getName();
        QString q_owner = QString::fromStdString(owner);
        m_ui->InfoText->append(q_owner);
    }




    unsigned int build_count = tile->getBuildingCount();
    unsigned int max_build = tile->MAX_BUILDINGS;
    m_ui->InfoText->append("\nBuildings:     ( "
                           + QString::number(build_count) + "/"
                           + QString::number(max_build)+ " )");

    for(unsigned int i = 0; i < buildings.size(); ++i)
    {
        QString building_type = QString::fromStdString(buildings.at(i)->getType());
        m_ui->InfoText->append(building_type);
    }




    unsigned int worker_count = tile->getWorkerCount();
    unsigned int max_workers = tile->MAX_WORKERS;
    m_ui->InfoText->append("\nWorkers:     ( "
                           + QString::number(worker_count) + "/"
                           + QString::number(max_workers)+ " )");

    for(unsigned int i = 0; i < workers.size(); ++i)
    {
        QString worker_type = QString::fromStdString(workers.at(i)->getType());
        m_ui->InfoText->append(worker_type);
    }


    std::map<Course::BasicResource, int> tile_production = gameEventHandler->getProduction(tile);


    m_ui->MoneyLabel->setNum(tile_production[Course::BasicResource::MONEY]);
    m_ui->OreLabel->setNum(tile_production[Course::BasicResource::ORE]);
    m_ui->StoneLabel->setNum(tile_production[Course::BasicResource::STONE]);
    m_ui->FoodLabel->setNum(tile_production[Course::BasicResource::FOOD]);
    m_ui->WoodLabel->setNum(tile_production[Course::BasicResource::WOOD]);

}

void MapWindow::save_activate_tile(Course::Coordinate coordinates)
{
    last_clicked_tile = coordinates;
}

void MapWindow::on_pushButton_4_clicked()
{
    std::shared_ptr<Course::Farm> farmi =
            std::make_shared<Course::Farm>(gameEventHandler,objectManager,current_player);

   add_new_building(farmi, Course::ConstResourceMaps::FARM_BUILD_COST);





//    m_gamescene->addRect(QRectF(0, 0, 100, 200), QPen(Qt::black), QBrush(Qt::green));
//    QPixmap pixmap;
//    QPainter painter(&pixmap);
//    painter.setRenderHint(QPainter::Antialiasing);
//    m_gamescene->render(&painter);
//    painter.end();

//    m_gamescene->addPixmap
//            (QPixmap("C:/Users/zingo/ohj3/master/harjoitus/tiimi-kuusi-6/Game/farm_image.png"));

//    Course::SimpleMapItem::paint(painter, m_gamescene);
//    QPixmap farm("G:/farm_image.png");
//   QPainter painter(this);
//      QPoint location;
//     location = farmi->getCoordinatePtr()->asQpoint();

//      painter.drawPixmap(location,
//                         (QPixmap("C:/Users/zingo/ohj3/master/harjoitus/tiimi-kuusi-6/Game/farm_image.png")));
//    painter.drawImage(farm);
//     m_gamescene->updateItem(farmi);
//     m_gamescene->updateItem(tile);
//     m_gamescene->update();
//     m_ui->graphicsView->update();
    //   //  m_gamescene->resize();

   //QPixmap farm1(":/farm_image.png");
   //QPixmap farm = farm1.scaled(QSize(40,40));
   //QGraphicsPixmapItem* item = m_gamescene->addPixmap(farm);
   //item->setPos(51,51);
   // m_ui->graphicsView->viewport()->update();
}

void MapWindow::on_addBWButton_clicked()
{
    std::shared_ptr<Course::BasicWorker> basicworker =
            std::make_shared<Course::BasicWorker>(gameEventHandler,objectManager,current_player);

    add_new_worker(basicworker, Course::ConstResourceMaps::BW_RECRUITMENT_COST);

}

void MapWindow::removeItem(std::shared_ptr<Course::GameObject> obj)
{
    m_gamescene->removeItem(obj);
}

void MapWindow::drawItem( std::shared_ptr<Course::GameObject> obj)
{
    m_gamescene->drawItem(obj);
}

void MapWindow::on_TurnButton_clicked()
{   
    //Generoidaan resurssit pelaajalle, joka lopetti vuoronsa.
    for(unsigned int i = 0; i < 300; i++)
    {
        auto tile = objectManager->getTile(i);
        if(tile->getOwner() == current_player)
        {
            tile->generateResources();
        }
    }

    //Vuoro vaihtuu
    if(current_player == player2)
    {
        current_player = player1;
    } else
    {
        current_player = player2;
    }

    update_player_resources();
    m_ui->CurrentPlayerLabel->setText("Current player: "+
                                      QString::fromStdString(current_player->getName()));

}

void MapWindow::on_pushButton_6_clicked()
{
    std::shared_ptr<Course::HeadQuarters> hq =
            std::make_shared<Course::HeadQuarters>(gameEventHandler,objectManager,current_player);

   add_new_building(hq, Course::ConstResourceMaps::HQ_BUILD_COST);
}

void MapWindow::on_pushButton_5_clicked()
{
    std::shared_ptr<Course::Outpost> outpost =
            std::make_shared<Course::Outpost>(gameEventHandler,objectManager,current_player);

   add_new_building(outpost, Course::ConstResourceMaps::OUTPOST_BUILD_COST);
}

void MapWindow::on_addAWButton_clicked()
{
    std::shared_ptr<Student::AdvancedWorker> advancedworker =
            std::make_shared<Student::AdvancedWorker>(gameEventHandler,objectManager,current_player);

    add_new_worker(advancedworker, Student::ConstResourceMaps::AW_RECRUITMENT_COST);
}
