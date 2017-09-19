//
// Created by jan on 14.09.17.
//

#include "Sim.h"
#include <iostream>

#define INPUT_NEURON_COUNT 4
#define OUTPUT_NEURON_COUNT 2

class Specimen;

Sim::Sim(World& world, int specimen_start_count, int food_count) : world(world)
{
    this->specimen_start_count = specimen_start_count;
    input_neurons.resize(specimen_start_count);
    output_neurons.resize(specimen_start_count);

    for(int i = 0; i<specimen_start_count; i++)
    {
        input_neurons[i].resize(INPUT_NEURON_COUNT);
        output_neurons[i].resize(OUTPUT_NEURON_COUNT);
        output_neurons[i][0] = 1-((float) rand() * 2)/RAND_MAX;
        output_neurons[i][1] = 1-((float) rand() * 2)/RAND_MAX;
        specimen.push_back(Specimen(input_neurons[i], output_neurons[i], world));
    }

    for(int i = 0; i<food_count; i++)
    {
        food.push_back(Food(world));
    }



}

void Sim::simulate_frame()
{
    for(int i = 0; i<specimen.size(); i++)
    {
        if(specimen[i].is_active())
        {
            specimen[i].simulate_frame();
            if(!specimen[i].is_active())
            {
                //netManager.kill(i);
            }
        }
    }
    //std::cout<<specimen[0].get_food_level()<<" "<<specimen[0].get_life_time_equivalent()<<"\n";
    //calculate the nets or some shit here
}

std::vector <Specimen> Sim::get_specimens()
{
    return specimen;
}

std::vector<Food> Sim::get_food() {
    return food;
}

World &Sim::get_world() const {
    return world;
}


