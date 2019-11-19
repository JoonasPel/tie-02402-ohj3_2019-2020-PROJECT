#ifndef PLAYER_H
#define PLAYER_H

#include "core/playerbase.h"

namespace Student {




class Player : public Course::PlayerBase
{
public:
    Player(const std::string& name,
           const std::vector<std::shared_ptr<Course::GameObject>> objects = {});

    virtual ~Player() = default;

private:
    std::string m_name;
    std::vector<std::weak_ptr<Course::GameObject>> m_objects;


};

}
#endif // PLAYER_H
