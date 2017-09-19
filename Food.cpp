//
// Created by jan on 18.09.17.
//

#include <cmath>
#include <cstdlib>
#include <algorithm>
#include "Food.h"

Food::Food(World& world) : world(world) {
    this->size = (float) rand() / RAND_MAX * 1000;
    this->pos_x = (float) rand() / RAND_MAX * world.get_size_x();
    this->pos_y = (float) rand() / RAND_MAX * world.get_size_y();
    radius = sqrt(size);
}

Food::Food(float size, float pos_x, float pos_y,  World& world) : world(world) {
    this->size = size;
    this->pos_x = pos_x;
    this->pos_y = pos_y;
    radius = sqrt(size);
}

float Food::bite(float bite_size) {
    float consumed = std::min(size, bite_size);
    size -= consumed;
    radius = sqrt(size);
    return consumed;
}

float Food::get_size() const {
    return size;
}

float Food::get_pos_x() const {
    return pos_x;
}

float Food::get_pos_y() const {
    return pos_y;
}

float Food::get_radius() const {
    return radius;
}


