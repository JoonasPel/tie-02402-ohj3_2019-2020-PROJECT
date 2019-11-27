#include "gameeventhandler.h"

namespace Student {


GameEventHandler::GameEventHandler()
{

}

std::map<Course::BasicResource, int> GameEventHandler::getProduction(std::shared_ptr<Course::TileBase> tile)
{

    return tile->BASE_PRODUCTION;











//    ResourceMapDouble worker_efficiency; pitaa hakea workerin tehokkuus
//    ResourceMap total_production;     tiilen production
//    auto m_workers = tile->getWorkers();

//    for( auto work_it = m_workers.begin();
//         work_it != m_workers.end();
//         ++work_it)
//    {
//        ResourceMapDouble current_efficiency = work_it->lock()->tileWorkAction();

//        worker_efficiency = mergeResourceMapDoubles(worker_efficiency, current_efficiency);
//    }

//    total_production = multiplyResourceMap(BASE_PRODUCTION, worker_efficiency);

//    for( auto build_it = m_buildings.begin();
//         build_it != m_buildings.end();
//         ++build_it)
//    {
//        ResourceMap current_production = build_it->lock()->getProduction();

//        total_production = mergeResourceMaps(total_production,
//                                             current_production);
//    }

//    return total_production;
}

bool GameEventHandler::modifyResource(std::shared_ptr<Course::PlayerBase> player, Course::BasicResource resource, int amount)
{

}

bool GameEventHandler::modifyResources(std::shared_ptr<Course::PlayerBase> player, Course::ResourceMap resources)
{

}





















}
