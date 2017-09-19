//
// Created by jan on 18.09.17.
//

#ifndef SIMPLEEVOLUTION_FOOD_H
#define SIMPLEEVOLUTION_FOOD_H


#include "World.h"

class Food {
public:
    Food(World& world);
    Food(float size, float pos_x, float pos_y,  World& world);

    float bite(float bite_size);

    float get_size() const;
    float get_pos_x() const;
    float get_pos_y() const;
    float get_radius() const;

private:
    float size, pos_x, pos_y, radius;
    World& world;
};


#endif //SIMPLEEVOLUTION_FOOD_H
