#pragma 

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

namespace animation {

class Animation {
public:
    Animation();
    void run();
    virtual ~Animation() {}
private:
    sf::RenderWindow _window;
    sf::Text _text;
    sf::Font _font;
};

}
