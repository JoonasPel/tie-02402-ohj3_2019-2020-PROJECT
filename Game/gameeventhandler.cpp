#include "gameeventhandler.h"


namespace Student {


GameEventHandler::GameEventHandler()
{

}

std::map<Course::BasicResource, int> GameEventHandler::getProduction(std::shared_ptr<Course::TileBase> tile)
{
    Course::ResourceMapDouble worker_efficiency;

    Course::ResourceMap total_production = tile->BASE_PRODUCTION;
    auto m_workers = tile->getWorkers();
    auto m_buildings = tile->getBuildings();

    //Olettaa etta workerit ovat tyytyvaisia. "satisfied".
    for( auto worker : m_workers)
    {
        Course::ResourceMapDouble efficiency = worker->WORKER_EFFICIENCY;
        efficiency = mergeResourceMapDoubles
                (efficiency,ConstResourceMaps::worker_satisfactioner);


        worker_efficiency = mergeResourceMapDoubles(worker_efficiency, efficiency);
    }
    //Jos ei workereita, niin ei kerrota, jotta valtetaan nollalla kertominen.
    if(m_workers.size() != 0)
    {
        total_production = multiplyResourceMap(tile->BASE_PRODUCTION, worker_efficiency);
    }

    for( auto building : m_buildings)
    {
        Course::ResourceMap production = building->PRODUCTION_EFFECT;

        total_production = mergeResourceMaps(total_production,
                                             production);
    }

   return total_production;
}

bool GameEventHandler::modifyResource(std::shared_ptr<Course::PlayerBase> player, Course::BasicResource resource, int amount)
{

    std::shared_ptr<Student::Player> pl = std::dynamic_pointer_cast<Student::Player>(player);

    Course::ResourceMap player_resources = pl->get_player_resources();

    player_resources[resource] += amount;

    pl->save_player_resources(player_resources);



}

bool GameEventHandler::modifyResources(std::shared_ptr<Course::PlayerBase> player, Course::ResourceMap resources)
{

}





















}
