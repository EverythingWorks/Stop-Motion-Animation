#pragma once 
#include <SFML/Graphics.hpp>

namespace animation {
    struct Frame {
        Frame(const sf::Image & image, const unsigned timeInterval) : _image{image}, _timeInterval{timeInterval}  {}
        Frame() = default;
        virtual ~Frame() {}
        sf::Image _image;
        unsigned _timeInterval;
    };
}