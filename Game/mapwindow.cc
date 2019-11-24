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

    //connect(m_gamescene.get(), SIGNAL (sendtileid(unsigned int)),
           // this, SLOT (print_tile_info(unsigned int)));





    Course::WorldGenerator& worldGen = Course::WorldGenerator::getInstance();
    worldGen.addConstructor<Course::Forest>(1);
    worldGen.addConstructor<Course::Grassland>(1);
    worldGen.addConstructor<Student::Desert>(1);
    worldGen.generateMap(10,10,312, objectManager, gameEventHandler);



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

    drawItem(farmi);

    // Lisataan worker tileen.

    std::shared_ptr<Course::BasicWorker> basicworker =
            std::make_shared<Course::BasicWorker>(gameEventHandler,objectManager,player1);

    tile1->setOwner(player1);

    tile1->addWorker(basicworker);

    drawItem(basicworker);




}

void MapWindow::print_tile_info(unsigned int tile_id)
{
    auto tile = objectManager->getTile(tile_id);
    std::string tile_type = tile->getType();
    std::cout << tile_type << std::endl;

}

void MapWindow::removeItem(std::shared_ptr<Course::GameObject> obj)
{
    m_gamescene->removeItem(obj);
}

void MapWindow::drawItem( std::shared_ptr<Course::GameObject> obj)
{
    m_gamescene->drawItem(obj);
}
