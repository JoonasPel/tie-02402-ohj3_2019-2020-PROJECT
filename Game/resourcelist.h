#ifndef RESOURCELIST_H
#define RESOURCELIST_H

#include "core/basicresources.h"

namespace Student {

namespace ConstResourceMaps {

const Course::ResourceMap EMPTY = {};


//Tile-Desert Basic Production
const Course::ResourceMap DESERT_BP = {
    {Course::BasicResource::MONEY, 1},
    {Course::BasicResource::FOOD, 1},
    {Course::BasicResource::WOOD, 1},
    {Course::BasicResource::STONE, 10},
    {Course::BasicResource::ORE, 2}
};




}
}
#endif // RESOURCELIST_H
