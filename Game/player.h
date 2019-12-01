#ifndef PLAYER_H
#define PLAYER_H

#include "core/playerbase.h"
#include "core/basicresources.h"
#include "resourcelist.h"

namespace Student {




class Player : public Course::PlayerBase
{
public:
    Player(const std::string& name,
           const std::vector<std::shared_ptr<Course::GameObject>> objects = {});

    virtual ~Player() = default;

    Course::ResourceMap get_player_resources();
    void save_player_resources(Course::ResourceMap resources); //Tallentaa muuttuneet resurssit.




private:
    std::string m_name;
    std::vector<std::weak_ptr<Course::GameObject>> m_objects;
    Course::ResourceMap player_resources;



};

}
#endif // PLAYER_H
