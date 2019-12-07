#include "objectmanager.h"
#include "exceptions/baseexception.h"

namespace Student {

const unsigned int COLUMN_SIZE = 11;
const unsigned int ROW_SIZE = 15;

ObjectManager::ObjectManager()
{

}

void ObjectManager::addTiles(const std::vector<std::shared_ptr<Course::TileBase> > &tiles)
{
    tiles_ = tiles;

}

std::shared_ptr<Course::TileBase> ObjectManager::getTile(const Course::Coordinate &coordinate)
{

    int tile_id = coordinate.x()*COLUMN_SIZE + coordinate.y();

    int map_size = COLUMN_SIZE*ROW_SIZE;

    if(tile_id < map_size && tile_id >= 0)
    {
        return tiles_.at(coordinate.x()*COLUMN_SIZE + coordinate.y());

    } else
    {
        throw Course::BaseException("Given coordinates for tile are out of map!");
    }

}

std::shared_ptr<Course::TileBase> ObjectManager::getTile(const Course::ObjectId &id)
{
    return tiles_.at(id);
}

std::vector<std::shared_ptr<Course::TileBase> > ObjectManager::getTiles(const std::vector<Course::Coordinate> &coordinates)
{
    std::vector<std::shared_ptr<Course::TileBase>> tiles;

    for(auto coordinate : coordinates)
    {
        try {
            tiles.push_back(getTile(coordinate));

        } catch (Course::BaseException) {
            //Ei tarvetta toimenpiteille. Jatketaan looppia.
        }

    }
    return tiles;
}

std::vector<std::shared_ptr<Course::TileBase> > ObjectManager::getTiles()
{
    return tiles_;
}

}
