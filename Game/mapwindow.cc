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
    this->setWindowTitle("Pirkanmaan valloitus");

    Student::GameScene* sgs_rawptr = m_gamescene.get();

    m_ui->graphicsView->setScene(dynamic_cast<QGraphicsScene*>(sgs_rawptr));



    connect(m_gamescene.get(), &Student::GameScene::sendtileid,
                this, &MapWindow::print_tile_info);

    connect(m_gamescene.get(), &Student::GameScene::sendtileid,
                this, &MapWindow::save_activate_tile);
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

QPixmap MapWindow::getImageByString(std::string building_name)
{
    if(building_name == "Farm")
    {
        QPixmap building_image(":/farmimage.png");
        QPixmap building = building_image.scaled(QSize(25,25));
        return building;
    } else if (building_name == "HeadQuarters")
    {
        QPixmap building_image(":/building_image.png");
        QPixmap building = building_image.scaled(QSize(25,25));
        return building;

    } else if (building_name == "Mine")
    {
        QPixmap building_image(":/mineimage.png");
        QPixmap building = building_image.scaled(QSize(25,25));
        return building;
    } else if(building_name == "Outpost")
    {
        QPixmap building_image(":/outpostimage.png");
        QPixmap building = building_image.scaled(QSize(25,25));
        return building;
    }


}

void MapWindow::paintWorker(std::shared_ptr<Course::TileBase> tile)
{
    int x = tile->getCoordinate().x();
    int y = tile->getCoordinate().y();
    int worker_count = tile->getWorkerCount();

    QPixmap image(":/worker_image.png");
    QGraphicsPixmapItem* worker_image = m_gamescene->addPixmap(image);


    switch (worker_count) {

    case 1: worker_image->setPos(x*70+24,y*70+32); break;

    case 2: worker_image->setPos(x*70+30,y*70+32); break;

    case 3: worker_image->setPos(x*70+36,y*70+32); break;

    case 4: worker_image->setPos(x*70+42,y*70+32); break;


    default: break;

    }

    m_ui->graphicsView->viewport()->update();
}



void MapWindow::paintBuilding(std::shared_ptr<Course::TileBase> tile,QPixmap building)
{
    int x = tile->getCoordinate().x();
    int y = tile->getCoordinate().y();





    QGraphicsPixmapItem* item = m_gamescene->addPixmap(building);

    switch (tile->getBuildingCount()) {

    case 1: item->setPos(x*70+6,y*70+6); break;

    case 2: item->setPos(x*70+39,y*70+6); break;

    case 3: item->setPos(x*70+6,y*70+39); break;

    case 4: item->setPos(x*70+39,y*70+39); break;

    default: break;

    }

     m_ui->graphicsView->viewport()->update();
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

    if(!gameEventHandler->obj_placement_permission(tile, objectManager, current_player))
    {
        m_ui->statusLabel->setText("Can't add worker here! No building in neighbour.");
        return;
    }

    try {
        //(Pelaajalla on varaa workeriin) JA (pelaaja omistaa tilen TAI kukaan ei omista).
        if(current_player->does_have_enough_resources(cost) &&
                (tile->getOwner() == current_player || tile->getOwner() == nullptr))
        {
            if (!current_player->already_owned(tile)){
                current_player->addtile(tile);
            }
            tile->setOwner(current_player);
            tile->addWorker(worker);

            //Maksu workerista, vahennetaan pelaajalta resursseja.
            for (auto resource : cost)
            {
                gameEventHandler->modifyResource
                        (current_player,resource.first,-resource.second);
            }

            update_player_resources();
            print_total_production();
            drawItem(worker);
            print_tile_info(last_clicked_tile); //Tilen inffot ajantasalle.
            paintWorker(tile);
            m_ui->graphicsView->viewport()->update();

        }
    } catch (Course::IllegalAction) {
        m_ui->statusLabel->setText("There is no space for more workers!");
    }
}

void MapWindow::add_new_building(std::shared_ptr<Course::BuildingBase> building, Course::ResourceMap cost)
{
    std::shared_ptr<Course::TileBase> tile = objectManager->getTile(last_clicked_tile);

    if(!gameEventHandler->obj_placement_permission(tile, objectManager, current_player))
    {
        m_ui->statusLabel->setText("Can't build here! No building in neighbour.");
        return;
    }

    try {
        //(Pelaajalla on varaa rakennukseen) JA (pelaaja omistaa tilen TAI kukaan ei omista).
        if(current_player->does_have_enough_resources(cost) &&
                (tile->getOwner() == current_player || tile->getOwner() == nullptr))
        {
            //---------- tarkistetaan halutaanko listata tiili pelaajan tiilivektoriin.
            if (!current_player->already_owned(tile)){
                current_player->addtile(tile);
            }
            tile->setOwner(current_player);
            tile->addBuilding(building);
            //Maksu rakennuksesta, vahennetaan pelaajalta resursseja.
            for (auto resource : cost)
            {
                gameEventHandler->modifyResource
                        (current_player,resource.first,-resource.second);
            }
            update_player_resources();
            print_total_production();
            drawItem(building);
            print_tile_info(last_clicked_tile); //Tilen inffot ajantasalle.
            std::string building_type = building->getType();
            QPixmap building_image = MapWindow::getImageByString(building_type);
            paintBuilding(tile,building_image);

            m_ui->graphicsView->viewport()->update();
        }

    } catch (Course::IllegalAction) {
        m_ui->statusLabel->setText("There is no space for more buildings!");
    }
}

void MapWindow::draw_tiles()
{

    for(unsigned int i = 0; i < 165; i++)
    {
           auto item = objectManager->getTile(i);
           drawItem(item);
    }
}



void MapWindow::print_total_production()
{
    Course::ResourceMap total_production;
    std::vector<std::shared_ptr<Course::TileBase>> player_tiles = current_player->get_tiles();
    for(auto tile : player_tiles)
    {
       total_production =
               Course::mergeResourceMaps(total_production,gameEventHandler->getProduction(tile));
    }
    m_ui->MoneyPlayerLabel_2->setNum(total_production[Course::BasicResource::MONEY]);
    m_ui->FoodPlayerLabel_2->setNum(total_production[Course::BasicResource::FOOD]);
    m_ui->WoodPlayerLabel_2->setNum(total_production[Course::BasicResource::WOOD]);
    m_ui->StonePlayerLabel_2->setNum(total_production[Course::BasicResource::STONE]);
    m_ui->OrePlayerLabel_2->setNum(total_production[Course::BasicResource::ORE]);
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

void MapWindow::init_game(std::string name1, std::string name2)
{
    if(name1 == ""){
        player1->setName("Player 1");
    } else
    {
    player1->setName(name1);
    }
    if(name2=="")
    {
    player2->setName("Player 2");
    }else
    {
    player2->setName(name2);
    }

    Course::WorldGenerator& worldGen = Course::WorldGenerator::getInstance();
    worldGen.addConstructor<Course::Forest>(20);
    worldGen.addConstructor<Course::Grassland>(35);
    worldGen.addConstructor<Student::Desert>(25);
    worldGen.addConstructor<Student::Water>(7);
    worldGen.generateMap(15,11,time(NULL), objectManager, gameEventHandler);

    draw_tiles();

    current_player = player1; //Kumpi pelaajista aloittaa.

    //Pelaajien aloitustiilet.
    auto tile = objectManager->getTile(152);
    auto tile2 = objectManager->getTile(12);

    //Aloitus hq:t pelaajille.
    std::shared_ptr<Course::HeadQuarters> hq =
            std::make_shared<Course::HeadQuarters>(gameEventHandler,objectManager,player1);
    std::shared_ptr<Course::HeadQuarters> hq2 =
            std::make_shared<Course::HeadQuarters>(gameEventHandler,objectManager,player2);
    tile->setOwner(player1);
    tile2->setOwner(player2);
    tile->addBuilding(hq);
    tile2->addBuilding(hq2);
    drawItem(hq);
    drawItem(hq2);

    paintBuilding(tile,MapWindow::getImageByString("HeadQuarters"));
    paintBuilding(tile2,MapWindow::getImageByString("HeadQuarters"));


    m_ui->graphicsView->viewport()->update();

    m_ui->CurrentPlayerLabel->setText("Current player: "+
                                      QString::fromStdString(current_player->getName()));
}

void MapWindow::on_pushButton_4_clicked()
{
    std::shared_ptr<Course::Farm> farmi =
            std::make_shared<Course::Farm>(gameEventHandler,objectManager,current_player);

   add_new_building(farmi, Course::ConstResourceMaps::FARM_BUILD_COST);


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
    for(unsigned int i = 0; i < 165; i++)
    {
        auto tile = objectManager->getTile(i);
        if(tile->getOwner() == current_player and tile->getWorkerCount()!=0)
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

    print_total_production();
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

void MapWindow::on_pushButton_7_clicked()
{
    std::shared_ptr<Student::Mine> mine =
            std::make_shared<Student::Mine>(gameEventHandler,objectManager,current_player);

   add_new_building(mine, Student::ConstResourceMaps::MINE_BUILD_COST);
}

void MapWindow::on_addSoldierButton_clicked()
{
    std::shared_ptr<Student::AdvancedWorker> soldier =
            std::make_shared<Student::AdvancedWorker>(gameEventHandler,objectManager,current_player);

    add_new_worker(soldier, Student::ConstResourceMaps::SOLDIER_RECRUITMENT_COST);
}
