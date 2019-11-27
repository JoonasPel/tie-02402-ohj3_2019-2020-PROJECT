#include "mapwindow.hh"
#include "ui_mapwindow.h"
#include <iostream>
#include <string>

#include "graphics/simplemapitem.h"
#include "core/worldgenerator.h"

#include <math.h>



MapWindow::MapWindow(QWidget *parent,
                     std::shared_ptr<Course::iGameEventHandler> handler):
    QMainWindow(parent),
    m_ui(new Ui::MapWindow),
    m_GEHandler(handler),
    m_gamescene(new Student::GameScene(this)),
    gameEventHandler(std::make_shared<Student::GameEventHandler>()),
    objectManager(std::make_shared<Student::ObjectManager>()),
    player1(std::make_shared<Student::Player>("Player 1"))
{
    m_ui->setupUi(this);

    Student::GameScene* sgs_rawptr = m_gamescene.get();

    m_ui->graphicsView->setScene(dynamic_cast<QGraphicsScene*>(sgs_rawptr));


    connect(m_gamescene.get(), &Student::GameScene::sendtileid,
                this, &MapWindow::print_tile_info);






    Course::WorldGenerator& worldGen = Course::WorldGenerator::getInstance();
    worldGen.addConstructor<Course::Forest>(1);
    worldGen.addConstructor<Course::Grassland>(1);
    worldGen.addConstructor<Student::Desert>(1);
    worldGen.generateMap(20,15,312, objectManager, gameEventHandler);



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

void MapWindow::draw_tiles(int tile_count)
{

    for(unsigned int i = 0; i < tile_count; i++)
    {
           auto item = objectManager->getTile(i);
           drawItem(item);
    }

//    farmin lisays testausta, ja sen piirtoa


    std::shared_ptr<Course::Farm> farmi =
            std::make_shared<Course::Farm>(gameEventHandler,objectManager,player1);


    auto tile1 = objectManager->getTile(0);


    tile1->addBuilding(farmi);
    tile1->addBuilding(farmi);


    drawItem(farmi);

    // Lisataan worker tileen.

    std::shared_ptr<Course::BasicWorker> basicworker =
            std::make_shared<Course::BasicWorker>(gameEventHandler,objectManager,player1);

    tile1->setOwner(player1);

    tile1->addWorker(basicworker);

    drawItem(basicworker);



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

    m_ui->InfoText->setText(q_tile_type+"    ( " +QString::number(x_coord)+
                            "," + QString::number(y_coord) + " )\n\nOwner: ");


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



}

void MapWindow::removeItem(std::shared_ptr<Course::GameObject> obj)
{
    m_gamescene->removeItem(obj);
}

void MapWindow::drawItem( std::shared_ptr<Course::GameObject> obj)
{
    m_gamescene->drawItem(obj);
}
