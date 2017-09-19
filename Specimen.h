//
// Created by jan on 15.09.17.
//

#ifndef SIMPLEEVOLUTION_SPECIMEN_H
#define SIMPLEEVOLUTION_SPECIMEN_H


#include <vector>
#include "World.h"


class Specimen {
public:
    Specimen(std::vector<float>& input_neuron, std::vector<float>& output_neuron, World& world);

    void random_initialise();
    void simulate_frame();
    void die();

    float get_x_pos() const;
    float get_y_pos() const;
    float get_orientation() const;
    float get_species() const;
    float get_food_feeler_angle() const;
    float get_specimen_feeler_angle() const;
    float get_food_level() const;
    float get_life_time_equivalent() const;
    bool is_active() const;


private:
    float x_pos, y_pos, orientation, species;
    float food_feeler_angle, specimen_feeler_angle, energy, life_time_equivalent;
    float world_size_x, world_size_y;
    bool active;
    World& world;
    std::vector <float> input_neuron;
    std::vector <float> output_neuron;


};


#endif //SIMPLEEVOLUTION_SPECIMEN_H
