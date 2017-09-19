#include <thread>
#include <mutex>
#include <iostream>
#include "NetManager.h"

NetManager::NetManager(unsigned int num_of_layers, unsigned int num_of_neurons, unsigned int num_of_inputs,
                       unsigned int num_of_outputs, unsigned int num_of_creatures)
{
    //networks.reserve(num_of_creatures);
    for (int i=0; i < num_of_creatures; i++) {
        networks.push_back(NNet(num_of_layers, num_of_neurons, num_of_inputs, num_of_outputs));
        outputs.push_back(std::vector<float>(num_of_outputs));
    }
}

std::vector<std::vector<float>> NetManager::calculate(std::vector<std::vector<float>> &inputs)
{
    this->inputs = inputs;
    std::vector<std::thread> threads;
    int num_of_threads = std::thread::hardware_concurrency();
    threads.resize(num_of_threads);
    counter = networks.size() - 1;
    for (int i=0; i < num_of_threads; i++){
        threads[i] = std::thread(&worker_func, this);
    }
    for (int i=0; i < num_of_threads; i++){
        threads[i].join();
    }
    return this->outputs;
}

void NetManager::worker_func(NetManager* netManager)
{
    while(true)
    {
        netManager->mutex.lock();
        if (netManager->counter <= 0)
        {
            netManager->mutex.unlock();
            return;
        }
        int index = netManager->counter;
        netManager->counter--;
        netManager->mutex.unlock();

        netManager->outputs[index] = netManager->networks[index].feed_forward(netManager->inputs[index]);
    }
}