#pragma once

#include <iostream>
#include <string>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Animation{
public:
    //constructor with path to data which will be displayed
    Animation (std::string path = "/data.dat");

    //function that starts the frame
    void animate ();

    //destructor
    ~Animation();

private:
    //vector of intervals between frames
    std::vector<unsigned> _interval;

    //vector of shapes in order to display
    std::vector <sf::Drawable*> _shapes;

    //window that will be displayed
    sf::RenderWindow _window;

    //backgroung color od window
    sf::Color _background;

    //size of window
    unsigned _w, _h;
};
