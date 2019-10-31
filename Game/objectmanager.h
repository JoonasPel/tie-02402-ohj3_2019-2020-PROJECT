#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#endif // OBJECTMANAGER_H

#include <memory>
#include <vector>
#include "interfaces/iobjectmanager.h"

namespace Student {

class TileBase;
class Coordinate;

class ObjectManager : public Course::iObjectManager
{
public:
    ObjectManager();
    /**
     * @brief Default destructor.
     */
    virtual ~ObjectManager() = default;


    virtual void addTiles(
            const std::vector<std::shared_ptr<TileBase>>& tiles) = 0;


    std::shared_ptr<Course::TileBase> getTile(
            const Course::Coordinate& coordinate) = 0;


     std::shared_ptr<Course::TileBase> getTile(const Course::ObjectId& id) = 0;


     std::vector<std::shared_ptr<Course::TileBase>> getTiles(
            const std::vector<Course::Coordinate>& coordinates) = 0;


};

}

