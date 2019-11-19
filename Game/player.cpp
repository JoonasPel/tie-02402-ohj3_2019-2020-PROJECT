#include "player.h"


namespace Student {


Player::Player(const std::string& name,
               const std::vector<std::shared_ptr<Course::GameObject> > objects):
    Course::PlayerBase(name,objects),
    m_name(name),
    m_objects()
{
    for( auto it = objects.begin(); it != objects.end(); ++it)
    {
        m_objects.push_back(std::weak_ptr<Course::GameObject>(*it));
    }

}
}
