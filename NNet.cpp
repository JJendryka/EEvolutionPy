#include <cmath>
#include <iostream>
#include "NNet.h"

NNet::NNet(unsigned int num_of_layers, unsigned int num_of_neurons, unsigned int num_of_inputs,
           unsigned int num_of_outputs)
{
    this->num_of_layers = num_of_layers;
    this->num_of_neurons = num_of_neurons;

    weights.resize(num_of_layers * num_of_neurons * num_of_neurons);
    for(unsigned int i=0; i<weights.size(); i++) {
        weights[i] = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/2)) - 1;
    }
    input_layer.resize(num_of_neurons * num_of_inputs);
    for(unsigned int i=0; i<input_layer.size(); i++) {
        input_layer[i] = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/2)) - 1;
    }
    output_layer.resize(num_of_neurons * num_of_outputs);
    for(unsigned int i=0; i<output_layer.size(); i++) {
        output_layer[i] = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/2)) - 1;
    }
}

std::vector<float> NNet::feed_forward(std::vector<float> input)
{
    std::vector<float> output = feed_layer(input_layer.begin(), input);
    for (int i=0; i<num_of_layers; i++) {
        output = feed_layer(weights.begin() + (i * num_of_neurons * num_of_neurons), output);
    }
    output = feed_layer(output_layer.begin(), output);
    return output;
}

float NNet::feed_neuron(std::vector<float>::const_iterator weights_begin,
                        std::vector<float> inputs)
{
    float sum = 0;
    for (int i=0; i<inputs.size(); i++) {
        sum += *(weights_begin + i) * inputs[i];
    }
    return sigmoid(sum);

}

std::vector<float> NNet::feed_layer(std::vector<float>::const_iterator weights_begin,
                                    std::vector<float> inputs)
{
    std::vector<float> outputs;
    outputs.resize(num_of_neurons);
    for (int i=0; i<num_of_neurons; i++) {
        outputs[i] = feed_neuron(weights_begin + (i * inputs.size()), inputs);
    }
    return outputs;
}

float NNet::sigmoid(float x)
{
    return (float)(1 / (1 + exp(-x)));
}
