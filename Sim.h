//
// Created by jan on 14.09.17.
//

#ifndef SIMPLEEVOLUTION_SIM_H
#define SIMPLEEVOLUTION_SIM_H

#include <vector>
#include "World.h"
#include "Specimen.h"
#include "Food.h"

class Sim {
public:
    Sim(World& world, int specimen_start_count, int food_count);

    void simulate_frame();
    std::vector <Specimen> get_specimens();
    std::vector <Food> get_food();

    World &get_world() const;


private:
    World& world;
    int specimen_start_count;
    std::vector <std::vector <float>> input_neurons, output_neurons;
    std::vector <Specimen> specimen;
    std::vector <Food> food;
};


#endif //SIMPLEEVOLUTION_SIM_H
