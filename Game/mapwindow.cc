#include "mapwindow.hh"
#include "ui_mapwindow.h"
#include <iostream>

#include "graphics/simplemapitem.h"
#include "core/worldgenerator.h"

#include <math.h>
#include <tiles/forest.h>
#include <tiles/grassland.h>

MapWindow::MapWindow(QWidget *parent,
                     std::shared_ptr<Course::iGameEventHandler> handler):
    QMainWindow(parent),
    m_ui(new Ui::MapWindow),
    m_GEHandler(handler),
    m_simplescene(new Course::SimpleGameScene(this)),
    manager(new Student::ObjectManager()),
    gamehandler(new Student::GameEventHandler()),
    gameEventHandler(std::make_shared<Student::GameEventHandler>(*gamehandler)),
    objectManager(std::make_shared<Student::ObjectManager>(*manager))
{
    m_ui->setupUi(this);

    Course::SimpleGameScene* sgs_rawptr = m_simplescene.get();

    m_ui->graphicsView->setScene(dynamic_cast<QGraphicsScene*>(sgs_rawptr));

    Course::WorldGenerator& worldGen = Course::WorldGenerator::getInstance();
    worldGen.addConstructor<Course::Forest>(1);
    worldGen.addConstructor<Course::Grassland>(1);

    worldGen.generateMap(10,10,3, objectManager, gameEventHandler);
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
    m_simplescene->setSize(width, height);
}

void MapWindow::setScale(int scale)
{
    m_simplescene->setScale(scale);
}

void MapWindow::resize()
{
    m_simplescene->resize();
}

void MapWindow::updateItem(std::shared_ptr<Course::GameObject> obj)
{
    m_simplescene->updateItem(obj);
}

void MapWindow::draw_tiles(int tile_count)
{

    std::cout << tile_count << std::endl;
    for(unsigned int i = 0; i < tile_count; i++)
    {
           auto item = objectManager->getTile(i);
           drawItem(item);
    }
}

void MapWindow::removeItem(std::shared_ptr<Course::GameObject> obj)
{
    m_simplescene->removeItem(obj);
}

void MapWindow::drawItem( std::shared_ptr<Course::GameObject> obj)
{
    m_simplescene->drawItem(obj);
}
