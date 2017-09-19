#include <thread>
#include <iostream>
#include "NNet.h"
#include "Display.h"
#include "Sim.h"
#include "World.h"
#include "Specimen.h"
#include <SFML/Window.hpp>



int main(int argc, char** argv)
{
    std::chrono::time_point<std::chrono::system_clock> start, end;
    Display display(1000, 1000);
    NNet nNet(4, 5, 3, 3);
    World world(1000.0, 1000.0);
    Sim sim(world, 1000, 100);

    start = std::chrono::system_clock::now();

    //for (int i=0; i < 1000000; i++)
    //nNet.feed_forward({0.1, 0.1, 0.1, 0.1});
    while(display.window_open())
    {
        sim.simulate_frame();
        display.render(sim, 60);
    }
    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout<<elapsed_seconds.count();
    return 0;
}