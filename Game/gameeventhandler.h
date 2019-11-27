#ifndef GAMEEVENTHANDLER_H
#define GAMEEVENTHANDLER_H

#endif // GAMEEVENTHANDLER_H

#include <memory>
#include <vector>
#include "interfaces/igameeventhandler.h"
#include <map>
#include "resourcelist.h"
#include "core/basicresources.h"
#include "tiles/tilebase.h"

namespace Student {
class TileBase;
class PlayerBase;
class GameObject;
class Coordinate;

class GameEventHandler : public Course::iGameEventHandler
{
public:
    GameEventHandler();

    virtual ~GameEventHandler() = default;




    std::map<Course::BasicResource, int> getProduction(std::shared_ptr<Course::TileBase> tile);





     bool modifyResource(std::shared_ptr<Course::PlayerBase> player,
                                 Course::BasicResource resource,
                                 int amount);


     bool modifyResources(std::shared_ptr<Course::PlayerBase> player,
                                  Course::ResourceMap resources);

};
}
