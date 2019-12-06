#ifndef RESOURCELIST_H
#define RESOURCELIST_H

#include "core/basicresources.h"

namespace Student {

namespace ConstResourceMaps {

const Course::ResourceMap EMPTY = {};




const Course::ResourceMap WATER_BP = {
    {Course::BasicResource::MONEY, 5},
    {Course::BasicResource::FOOD, 10},
    {Course::BasicResource::WOOD, 0},
    {Course::BasicResource::STONE, 0},
    {Course::BasicResource::ORE, 0}
};


//Tile-Desert Basic Production
const Course::ResourceMap DESERT_BP = {
    {Course::BasicResource::MONEY, 0},
    {Course::BasicResource::FOOD, -5},
    {Course::BasicResource::WOOD, 0},
    {Course::BasicResource::STONE, 1},
    {Course::BasicResource::ORE, 0}
};

const Course::ResourceMap Player_starting_resources = {
    {Course::BasicResource::MONEY, 10000},
    {Course::BasicResource::FOOD, 10000},
    {Course::BasicResource::WOOD, 10000},
    {Course::BasicResource::STONE, 10000},
    {Course::BasicResource::ORE, 10000}
};

const Course::ResourceMapDouble worker_satisfactioner = {
    {Course::BasicResource::MONEY, 1},
    {Course::BasicResource::FOOD, 1},
    {Course::BasicResource::WOOD, 1},
    {Course::BasicResource::STONE, 1},
    {Course::BasicResource::ORE, 1}
};

const Course::ResourceMapDouble AW_WORKER_EFFICIENCY = {
    {Course::MONEY, 0.25},
    {Course::FOOD, 1.15},
    {Course::WOOD, 1.00},
    {Course::STONE, 0.75},
    {Course::ORE, 0.75}
};

const Course::ResourceMap AW_RECRUITMENT_COST = {
    {Course::MONEY, 50},
    {Course::FOOD, 75}
};

const Course::ResourceMap MINE_BUILD_COST = {
    {Course::BasicResource::MONEY, 150},
    {Course::BasicResource::FOOD, 190},
    {Course::BasicResource::WOOD, 80},
    {Course::BasicResource::STONE, 200}
};
const Course::ResourceMap MINE_PRODUCTION = {
    {Course::BasicResource::MONEY, -1},
    {Course::BasicResource::FOOD, -2},
    {Course::BasicResource::ORE, 12}
};




}
}
#endif // RESOURCELIST_H
