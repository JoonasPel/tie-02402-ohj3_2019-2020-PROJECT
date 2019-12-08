#include "studentoutpost.h"
#include "interfaces/iobjectmanager.h"
#include "tiles/tilebase.h"
#include <iostream>
#include <algorithm>

namespace Student {



StudentOutpost::StudentOutpost(
        const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
        const std::shared_ptr<Course::iObjectManager>& objectmanager,
        const std::shared_ptr<Course::PlayerBase>& owner,
        const int& tilespaces,
        const Course::ResourceMap& buildcost,
        const Course::ResourceMap& production
        ):
    Outpost(eventhandler,
                 objectmanager,
                 owner,
                 tilespaces,
                 buildcost,
                 production)
{
}

//Kaytetaan tarkoituksella Outpost nimea eika StudentOutpost.
std::string StudentOutpost::getType() const
{
    return "Outpost";
}

std::vector<std::shared_ptr<Course::TileBase> > StudentOutpost::ClaimAndConquer()
{
    std::vector< std::shared_ptr<Course::TileBase> > neighbours =
            lockObjectManager()->getTiles(getCoordinatePtr()->neighbours(2));

    std::vector< std::shared_ptr<Course::TileBase> > inside_neighbours =
            lockObjectManager()->getTiles(getCoordinatePtr()->neighbours(1));

    for(auto it = neighbours.begin(); it != neighbours.end(); ++it)
    {
        // If the Tile doesn't have owner, set it's owner to buildings owner.
        if( not (*it)->getOwner() )
        {
            (*it)->setOwner(getOwner());
        }
    }
    lockObjectManager()->getTile(getCoordinate())->setOwner(getOwner());

//    //Kay lapi outpostin naapurit ja poistaa "sisalla" olevat. Jaljelle jatetaan "ulkorinki".
//    for(auto tile : neighbours)
//    {
//        auto it = std::find(inside_neighbours.begin(), inside_neighbours.end(), tile);

//        int index = std::distance(neighbours.begin(), it);

//        if (it != inside_neighbours.end())
//        {
//            neighbours.erase(neighbours.begin() + index);
//        }
//    }

    return neighbours;
}

} //namespace
