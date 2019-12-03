#include "gameeventhandler.h"


namespace Student {


GameEventHandler::GameEventHandler()
{

}

std::map<Course::BasicResource, int> GameEventHandler::getProduction(std::shared_ptr<Course::TileBase> tile)
{
    Course::ResourceMapDouble worker_efficiency = {
        {Course::BasicResource::NONE, 0},
        {Course::BasicResource::MONEY, 0},
        {Course::BasicResource::FOOD, 0},
        {Course::BasicResource::WOOD, 0},
        {Course::BasicResource::STONE, 0},
        {Course::BasicResource::ORE, 0}
    };

    Course::ResourceMap total_production = tile->BASE_PRODUCTION;
    auto m_workers = tile->getWorkers();
    auto m_buildings = tile->getBuildings();

    //Olettaa etta workerit ovat tyytyvaisia. "satisfied".
    for( auto worker : m_workers)
    {
        Course::ResourceMapDouble efficiency = worker->WORKER_EFFICIENCY;
        efficiency = multiplyResourceMapDoubles
                (efficiency,ConstResourceMaps::worker_satisfactioner);


        worker_efficiency = mergeResourceMapDoubles(worker_efficiency, efficiency);
    }

    total_production = multiplyResourceMap(tile->BASE_PRODUCTION, worker_efficiency);
    if(m_workers.size() != 0)
    {
        for( auto building : m_buildings)
        {
            Course::ResourceMap production = building->PRODUCTION_EFFECT;

            total_production = mergeResourceMaps(total_production,
                                                 production);
        }
    }

   return total_production;
}

bool GameEventHandler::modifyResource(std::shared_ptr<Course::PlayerBase> player, Course::BasicResource resource, int amount)
{

    std::shared_ptr<Student::Player> pl = std::dynamic_pointer_cast<Student::Player>(player);

    Course::ResourceMap player_resources = pl->get_player_resources();

    player_resources[resource] += amount;

    pl->save_player_resources(player_resources);

    return true;

}

bool GameEventHandler::modifyResources(std::shared_ptr<Course::PlayerBase> player, Course::ResourceMap resources)
{
    if(player == nullptr) //Jos tilella ei ole omistajaa, player on nullptr.
    {
        return false;
    }
    std::shared_ptr<Student::Player> pl = std::dynamic_pointer_cast<Student::Player>(player);

    Course::ResourceMap new_resources = mergeResourceMaps(pl->get_player_resources(),resources);

    pl->save_player_resources(new_resources);

    return true;
}





















}
