#ifndef PLAYER_H
#define PLAYER_H

#include "core/playerbase.h"
#include "core/basicresources.h"
#include "resourcelist.h"
#include "tiles/tilebase.h"
#include <vector>

namespace Student {



/*!
 * \brief The Player class
 */
class Player : public Course::PlayerBase
{
public:
    Player(const std::string& name,
           const std::vector<std::shared_ptr<Course::GameObject>> objects = {});

    virtual ~Player() = default;

    Course::ResourceMap get_player_resources();
    void save_player_resources(Course::ResourceMap resources); //Tallentaa muuttuneet resurssit.
    bool does_have_enough_resources(Course::ResourceMap cost);
    bool already_owned(std::shared_ptr<Course::TileBase> tile);
    void addtile(std::shared_ptr<Course::TileBase> tile);
    std::vector<std::shared_ptr<Course::TileBase>> get_tiles();
    void player_built_outpost();
    bool does_player_have_outpost();



private:
    std::vector<std::shared_ptr<Course::TileBase>> m_tiles;
    std::string m_name;
    std::vector<std::weak_ptr<Course::GameObject>> m_objects;
    Course::ResourceMap player_resources;
    bool has_outpost; //Pelaajalla voi olla vain yksi Outpost!



};

}
#endif // PLAYER_H
