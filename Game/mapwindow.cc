#include "mapwindow.hh"
#include "ui_mapwindow.h"
#include <iostream>

#include "graphics/simplemapitem.h"

#include "gameeventhandler.h"
#include "objectmanager.h"

#include "core/worldgenerator.h"

#include <math.h>
#include <tiles/forest.h>
#include <tiles/grassland.h>

MapWindow::MapWindow(QWidget *parent,
                     std::shared_ptr<Course::iGameEventHandler> handler):
    QMainWindow(parent),
    m_ui(new Ui::MapWindow),
    m_GEHandler(handler),
    m_simplescene(new Course::SimpleGameScene(this))
{
    m_ui->setupUi(this);

    Course::SimpleGameScene* sgs_rawptr = m_simplescene.get();

    m_ui->graphicsView->setScene(dynamic_cast<QGraphicsScene*>(sgs_rawptr));





     Student::ObjectManager* manager = new Student::ObjectManager(); //1


     Student::GameEventHandler* gamehandler = new Student::GameEventHandler; //2



     std::shared_ptr<Student::GameEventHandler> gameEventHandler
            = std::make_shared<Student::GameEventHandler>(*gamehandler); //3

     std::shared_ptr<Student::ObjectManager> objectManager
            = std::make_shared<Student::ObjectManager>(*manager);         //4



    Course::WorldGenerator& worldGen = Course::WorldGenerator::getInstance();
    worldGen.addConstructor<Course::Forest>(1);
    worldGen.addConstructor<Course::Grassland>(1);

    worldGen.generateMap(11,11,1, objectManager, gameEventHandler);


    m_simplescene->drawItem(objectManager->getTile(99));




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

void MapWindow::removeItem(std::shared_ptr<Course::GameObject> obj)
{
    m_simplescene->removeItem(obj);
}

void MapWindow::drawItem( std::shared_ptr<Course::GameObject> obj)
{
    m_simplescene->drawItem(obj);
}
