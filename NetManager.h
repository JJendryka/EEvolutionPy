#pragma once

#include <mutex>

#include "NNet.h"

class NetManager
{
public:
    NetManager(unsigned int num_of_layers, unsigned int num_of_neurons, unsigned int num_of_inputs,
                   unsigned int num_of_outputs, unsigned int num_of_creatures);
    std::vector<std::vector<float>> calculate(std::vector<std::vector<float>> &inputs);

    std::vector<NNet> networks;
    int counter;
    std::vector<std::vector<float>> inputs;
    std::vector<std::vector<float>> outputs;
    std::mutex mutex;
private:
    static void worker_func(NetManager* netManager);
};
