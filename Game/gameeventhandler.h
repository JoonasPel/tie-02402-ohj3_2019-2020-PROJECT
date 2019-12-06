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
#include "player.h"
#include "core/playerbase.h"
#include "desert.h"
#include <iostream>
#include <core/coordinate.h>
#include "interfaces/iobjectmanager.h"

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

    Course::ResourceMap calculate_upkeep(std::vector<std::shared_ptr<Course::WorkerBase>> workers);



     bool modifyResource(std::shared_ptr<Course::PlayerBase> player,
                                 Course::BasicResource resource,
                                 int amount);


     bool modifyResources(std::shared_ptr<Course::PlayerBase> player,
                                  Course::ResourceMap resources);

     //Tarkistaa, etta tilen naapurissa on current_playerin talo.
     bool obj_placement_permission(std::shared_ptr<Course::TileBase> tile,
                                   std::shared_ptr<Course::iObjectManager> objectmanager,
                                   std::shared_ptr<Student::Player> current_player);

};
}
