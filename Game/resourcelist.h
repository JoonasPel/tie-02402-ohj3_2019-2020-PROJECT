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

const Course::ResourceMap Player_starting_resources = {
    {Course::BasicResource::MONEY, 1000},
    {Course::BasicResource::FOOD, 1000},
    {Course::BasicResource::WOOD, 1000},
    {Course::BasicResource::STONE, 1000},
    {Course::BasicResource::ORE, 1000}
};

const Course::ResourceMapDouble worker_satisfactioner = {
    {Course::BasicResource::MONEY, 1},
    {Course::BasicResource::FOOD, 1},
    {Course::BasicResource::WOOD, 1},
    {Course::BasicResource::STONE, 1},
    {Course::BasicResource::ORE, 1}
};




}
}
#endif // RESOURCELIST_H
