//
// Created by jan on 15.09.17.
//

#include "Specimen.h"
#include <stdlib.h>
#include <math.h>
#include <iostream>

class Sim;

Specimen::Specimen(std::vector<float>& input_neuron, std::vector<float>& output_neuron,  World& world) : world(world)
{
    this->input_neuron = input_neuron;
    this->output_neuron = output_neuron;
    random_initialise();
}

void Specimen::random_initialise()
{
    x_pos = ((float) rand() * world.get_size_x())/RAND_MAX;
    y_pos = ((float) rand() * world.get_size_y())/RAND_MAX;
    orientation = ((float) rand() * 2 * M_PI)/RAND_MAX;
    species = ((float) rand())/RAND_MAX;
    energy = 1;
    life_time_equivalent = 0;
    active = true;
}

void Specimen::simulate_frame() {
    //output neurons: 0 - forward speed, 1 - angular speed, 2 - eating speed (negative means no eating)
    //input neurons: 0 - food kind feeler
    if (active)
    {
        float forward_speed, angular_speed, eating_speed;
        forward_speed = std::min(output_neuron[0] + 1, energy);
        angular_speed =
                output_neuron[1] >= 0 ? std::min(output_neuron[1], energy) : std::max(output_neuron[1], -energy);
        eating_speed = output_neuron[2];
        orientation += angular_speed * 0.2;
        x_pos += forward_speed * cos(orientation);
        y_pos += forward_speed * sin(orientation);
        energy -= forward_speed / 1000;
        life_time_equivalent += 1 / energy;
        if (life_time_equivalent >= 20000)
        {
            die();
        }
    }
}

void Specimen::die()
{
    active = false;
}

float Specimen::get_x_pos() const {
    return x_pos;
}

float Specimen::get_y_pos() const {
    return y_pos;
}

float Specimen::get_orientation() const {
    return orientation;
}


float Specimen::get_species() const {
    return species;
}

float Specimen::get_food_feeler_angle() const {
    return food_feeler_angle;
}

float Specimen::get_specimen_feeler_angle() const {
    return specimen_feeler_angle;
}

float Specimen::get_food_level() const {
    return energy;
}

float Specimen::get_life_time_equivalent() const {
    return life_time_equivalent;
}

bool Specimen::is_active() const {
    return active;
}



