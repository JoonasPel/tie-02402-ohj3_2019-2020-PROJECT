#ifndef STUDENTOUTPOST_H
#define STUDENTOUTPOST_H

#include "buildings/outpost.h"
#include "resourcelist.h"

namespace Student {



class StudentOutpost : public Course::Outpost
{

public:

    StudentOutpost();

    explicit StudentOutpost(
            const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
            const std::shared_ptr<Course::iObjectManager>& objectmanager,
            const std::shared_ptr<Course::PlayerBase>& owner,
            const int& tilespaces = 1,
            const Course::ResourceMap& buildcost = ConstResourceMaps::SOP_BUILD_COST,
            const Course::ResourceMap& production = ConstResourceMaps::SOP_PRODUCTION
            );

    virtual ~StudentOutpost() = default;

    virtual std::string getType() const override;

    virtual void onBuildAction() override;


}; //class

} //namespace

#endif // STUDENTOUTPOST_H
