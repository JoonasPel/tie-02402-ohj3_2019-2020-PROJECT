#include "objectmanager.h"
#include <iostream>

namespace Student {

const unsigned int COLUMN_SIZE = 15;

ObjectManager::ObjectManager()
{

}

void ObjectManager::addTiles(const std::vector<std::shared_ptr<Course::TileBase> > &tiles)
{
    tiles_ = tiles;

}

std::shared_ptr<Course::TileBase> ObjectManager::getTile(const Course::Coordinate &coordinate)
{
    return tiles_.at(coordinate.x()*COLUMN_SIZE + coordinate.y());
}

std::shared_ptr<Course::TileBase> ObjectManager::getTile(const Course::ObjectId &id)
{
    return tiles_.at(id);
}

std::vector<std::shared_ptr<Course::TileBase> > ObjectManager::getTiles(const std::vector<Course::Coordinate> &coordinates)
{

}
}
