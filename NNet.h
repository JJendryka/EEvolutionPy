#pragma once

#include <array>
#include <vector>

class NNet
{
public:
    NNet(unsigned int num_of_layers, unsigned int num_of_neurons, unsigned int num_of_inputs,
             unsigned int num_of_outputs);

    std::vector<float> feed_forward(std::vector<float> input);
private:
    float feed_neuron(std::vector<float>::const_iterator weights_begin, std::vector<float> inputs);
    std::vector<float> feed_layer(std::vector<float>::const_iterator weights_begin, std::vector<float> inputs);

    float sigmoid(float x);

    unsigned int num_of_layers;
    unsigned int num_of_neurons;

    std::vector<float> input_layer;
    std::vector<float> output_layer;
    std::vector<float> weights;
};