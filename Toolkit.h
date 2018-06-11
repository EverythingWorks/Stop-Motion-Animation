#pragma once 
#include <SFML/Graphics.hpp>

namespace animation {
    struct Toolkit {
        Toolkit() : _backgroundColor { sf::Color::Black }, _outlineColor { sf::Color::White }, _fillColor { sf::Color::White}, _outlineThickness{0.} {}
        sf::Color _backgroundColor;
        sf::Color _outlineColor;
        sf::Color _fillColor;
        float _outlineThickness;
    };
}