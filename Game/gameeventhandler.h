#ifndef GAMEEVENTHANDLER_H
#define GAMEEVENTHANDLER_H

#endif // GAMEEVENTHANDLER_H

#include <memory>
#include <vector>
#include "interfaces/igameeventhandler.h"

namespace Student {
class TileBase;
class PlayerBase;
class GameObject;
class Coordinate;

class GameEventHandler : public Course::iGameEventHandler
{
public:


    virtual ~GameEventHandler() = default;





     bool modifyResource(std::shared_ptr<Course::PlayerBase> player,
                                 Course::BasicResource resource,
                                 int amount) = 0;


     bool modifyResources(std::shared_ptr<Course::PlayerBase> player,
                                  Course::ResourceMap resources) = 0;

};
}
