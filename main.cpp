#include <thread>
#include <iostream>
#include "NNet.h"

int main(int argc, char** argv)
{
    std::chrono::time_point<std::chrono::system_clock> start, end;
    NNet nNet(4, 5, 3, 3);
    start = std::chrono::system_clock::now();

    for (int i=0; i < 1000000; i++)
    nNet.feed_forward({0.1, 0.1, 0.1, 0.1});

    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout<<elapsed_seconds.count();
    return 0;
}