#include <thread>
#include <iostream>
#include "NNet.h"
#include "NetManager.h"

int main(int argc, char** argv)
{
    std::chrono::time_point<std::chrono::system_clock> start, end;
    NetManager netManager(4, 5, 3, 3, 1000);
    std::vector<std::vector<float>> input;
    for (int i=0; i<1000; i++) {
        input.push_back({0.1, 0.1, 0.1, 0.1});
    }
    std::vector<NNet> nNets;
    for (int i=0; i<1000; i++) {
        nNets.push_back(NNet(4, 5, 3, 3));
    }
    start = std::chrono::system_clock::now();

    for (int i=0; i < 10000; i++) std::vector<std::vector<float>> out = netManager.calculate(input);

    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout<<elapsed_seconds.count()<<"\n";

    start = std::chrono::system_clock::now();
    for (int j=0; j<10000; j++)
    {
        for (int i = 0; i < 1000; i++)
        {
            nNets[i].feed_forward({0.1, 0.1, 0.1, 0.1});
        }
    }
    end = std::chrono::system_clock::now();
    elapsed_seconds = end-start;
    std::cout<<elapsed_seconds.count();

    return 0;
}