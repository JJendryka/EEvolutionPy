//
// Created by jan on 16.09.17.
//

#ifndef SIMPLEEVOLUTION_WORLD_H
#define SIMPLEEVOLUTION_WORLD_H


class World {
public:
    World(float size_x, float size_y);
    float get_size_x();
    float get_size_y();
//private:
    float size_x, size_y;
};


#endif //SIMPLEEVOLUTION_WORLD_H
