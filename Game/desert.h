#ifndef DESERT_H
#define DESERT_H

#include "tiles/tilebase.h"

namespace Student {



class Desert : public Course::TileBase
{
public:

    Desert() = delete;


    Desert(const Course::Coordinate& location,
           const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
           const std::shared_ptr<Course::iObjectManager>& objectmanager,
           const unsigned int& max_build = 2,
           const unsigned int& max_work = 3,
           const Course::ResourceMap& production = Course::ConstResourceMaps::FOREST_BP);



    virtual ~Desert() = default;


    virtual std::string getType() const override;

    void addBuilding(const std::shared_ptr<Course::BuildingBase> &building) override;


};















}


#endif // DESERT_H
