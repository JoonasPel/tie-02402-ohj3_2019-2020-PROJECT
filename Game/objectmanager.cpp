#include "objectmanager.h"

namespace Student {



ObjectManager::ObjectManager()
{

}

std::shared_ptr<Course::TileBase> ObjectManager::getTile(const Course::Coordinate &coordinate)
{

}

std::shared_ptr<Course::TileBase> ObjectManager::getTile(const Course::ObjectId &id)
{

}

std::vector<std::shared_ptr<Course::TileBase> > ObjectManager::getTiles(const std::vector<Course::Coordinate> &coordinates)
{

}

void ObjectManager::addTiles(const std::vector<std::shared_ptr<TileBase> > &tiles)
{
}

}
