//
// Created by jan on 14.09.17.
//
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Display.h"
#include "Specimen.h"
#include "Sim.h"
#include <iostream>

Display::Display(unsigned int resolution_x, unsigned int resolution_y)
{
    this->resolution_x = resolution_x;
    this->resolution_y = resolution_y;
    window.create(sf::VideoMode(resolution_x, resolution_y), "My window");
    //window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);
    std::cout<<"window";
}

void Display::render(Sim sim, int fps) {
    //window.setFramerateLimit(fps);
    sf::Event event;
    while (window.pollEvent(event))
    {
        // "close requested" event: we close the window
        if (event.type == sf::Event::Closed)
            window.close();
    }
    // clear the window with black color
    window.clear(sf::Color::Black);

    World world = sim.get_world();
    std::vector <Specimen> specimen = sim.get_specimens();
    std::vector <Food> food = sim.get_food();

    for(int i = 0; i<food.size(); i++)
    {
        sf::CircleShape shape(food[i].get_radius());
        shape.setFillColor(hsl_to_color(0, 0, 0.7));
        shape.setPosition(sf::Vector2f(food[i].get_pos_x()/world.get_size_x()*resolution_x, food[i].get_pos_y()/world.get_size_y()*resolution_y));
        window.draw(shape);
        std::cout<<food[i].get_pos_x()/world.get_size_x()*resolution_x<<" "<<food[i].get_pos_y()/world.get_size_y()*resolution_y<<"\n";
    }

    for(int i = 0; i<specimen.size(); i++)
    {
        sf::CircleShape shape(5);
        shape.setFillColor(hsl_to_color(specimen[i].get_species(), 0.3*specimen[i].is_active(), 0.5));
        shape.setPosition(sf::Vector2f(specimen[i].get_x_pos()/world.get_size_x()*resolution_x, specimen[i].get_y_pos()/world.get_size_y()*resolution_y));
        window.draw(shape);
    }

/*    sf::Color test_color = sf::Color(100+100*sin((double)(increm)/255*3.14*2), 100+100*cos((double)(increm)/255*3.14*2), 50);

    sf::CircleShape shape(50);
    shape.setFillColor(test_color);
    shape.setPosition(sf::Vector2f(100+100*cos((double)(increm++)/255*3.14*2), 100+100*sin((double)(increm)/255*3.14*2)));
    window.draw(shape);

    shape.setFillColor(hsl_to_color(0.5, 0.5, 0.5));
    shape.setPosition(sf::Vector2f(100+100*cos((double)(increm+128)/255*3.14*2), 100+100*sin((double)(increm+128)/255*3.14*2)));
    window.draw(shape);*/

    // end the current frame
    window.display();
}

bool Display::window_open() {
    return window.isOpen();
}

std::vector <float> Display::color_to_hsl(sf::Color color) {
    //R, G and B input range = 0 ÷ 255
//H, S and L output range = 0 ÷ 1.0
    float R, G, B, var_R, var_G, var_B, var_Min, var_Max, del_Max, H, S, L, del_R, del_G, del_B;
    R = color.r;
    G = color.g;
    B = color.b;
    var_R = ( R / 255.0 );
    var_G = ( G / 255.0 );
    var_B = ( B / 255.0 );

    var_Min = std::min(std::min( var_R, var_G), var_B );   //Min. value of RGB
    var_Max = std::max(std::max( var_R, var_G), var_B );    //Max. value of RGB
    del_Max = var_Max - var_Min;             //Delta RGB value

    L = ( var_Max + var_Min )/ 2.0;

    if ( del_Max == 0.0 )                     //This is a gray, no chroma...
    {
        H = 0.0;
        S = 0.0;
    }
    else                                    //Chromatic data...
    {
        if ( L < 0.5 ) S = del_Max / ( var_Max + var_Min );
        else           S = del_Max / ( 2.0 - var_Max - var_Min );

        del_R = ( ( ( var_Max - var_R ) / 6.0 ) + ( del_Max / 2.0 ) ) / del_Max;
        del_G = ( ( ( var_Max - var_G ) / 6.0 ) + ( del_Max / 2.0 ) ) / del_Max;
        del_B = ( ( ( var_Max - var_B ) / 6.0 ) + ( del_Max / 2.0 ) ) / del_Max;

        if      ( var_R == var_Max ) H = del_B - del_G;
        else if ( var_G == var_Max ) H = ( 1.0 / 3.0 ) + del_R - del_B;
        else if ( var_B == var_Max ) H = ( 2.0 / 3.0 ) + del_G - del_R;

        if ( H < 0.0 ) H += 1.0;
        if ( H > 1.0 ) H -= 1.0;
    }
    return std::vector <float> {H, S, L};
}

sf::Color Display::hsl_to_color(std::vector<float> hsl)
{
    return hsl_to_color(hsl[0], hsl[1], hsl[2]);
}

sf::Color Display::hsl_to_color(float H, float S, float L) {
    //H, S and L input range = 0 ÷ 1.0
//R, G and B output range = 0 ÷ 255
    float R, G, B, var_1, var_2;
    if ( S == 0 )
    {

        R = L * 255.0;
        G = L * 255.0;
        B = L * 255.0;
    }
    else
    {
        if ( L < 0.5 ) var_2 = L * ( 1 + S );
        else           var_2 = ( L + S ) - ( S * L );

        var_1 = 2.0 * L - var_2;

        R = 255.0 * hue_to_rgb(var_1, var_2, H + (1.0 / 3.0));
        G = 255.0 * hue_to_rgb(var_1, var_2, H);
        B = 255.0 * hue_to_rgb(var_1, var_2, H - (1.0 / 3.0));
    }
    return sf::Color(R, G, B);
}

float Display::hue_to_rgb(float v1, float v2, float vH)             //Function hue_to_rgb
{
    if ( vH < 0.0 ) vH += 1.0;
    if( vH > 1.0 ) vH -= 1.0;
    if ( ( 6.0 * vH ) < 1.0 ) return ( v1 + ( v2 - v1 ) * 6.0 * vH );
    if ( ( 2.0 * vH ) < 1.0 ) return ( v2 );
    if ( ( 3.0 * vH ) < 2.0 ) return ( v1 + ( v2 - v1 ) * ( ( 2.0 / 3.0 ) - vH ) * 6.0 );
    return ( v1 );
}