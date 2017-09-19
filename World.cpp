//
// Created by jan on 16.09.17.
//

#include "World.h"

World::World(float size_x, float size_y)
{
    this->size_x = size_x;
    this->size_y = size_y;
}

float World::get_size_y() {
    return size_y;
}

float World::get_size_x() {
    return size_x;
}
