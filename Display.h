//
// Created by jan on 14.09.17.
//

#ifndef SIMPLEEVOLUTION_DISPLAY_H
#define SIMPLEEVOLUTION_DISPLAY_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Sim.h"

class Display {
public:
    Display(unsigned int resolution_x, unsigned int resolution_y);
    void render(Sim sim, int fps);
    bool window_open();
private:
    sf::RenderWindow window;
    float resolution_x, resolution_y;
    char increm;
    std::vector <float> color_to_hsl(sf::Color color);
    sf::Color hsl_to_color(std::vector <float> hsl);
    sf::Color hsl_to_color(float H, float S, float L);
    float hue_to_rgb(float v1, float v2, float vH);


};


#endif //SIMPLEEVOLUTION_DISPLAY_H
