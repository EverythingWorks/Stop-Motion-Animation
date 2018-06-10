#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "Controller.h"
#include <memory>

namespace animation {

class Animation {
public:
    Animation();
    void run();
    virtual ~Animation() {}
private:
    std::shared_ptr<Controller> _ctrl;
    sf::RenderWindow _window;
    sf::Text _text;
    sf::Font _font;
};

}
