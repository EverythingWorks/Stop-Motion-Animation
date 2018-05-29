#include "Animation.h"


Animation::Animation(std::string path): _window(sf::VideoMode(800, 600), "Animation",sf::Style::Titlebar | sf::Style::Close) {
    //part to parse - all be read from file
    _w = 800;
    _h = 600;

    _background = sf::Color::Black;

    _interval.resize(5);
    std::fill(_interval.begin(), _interval.end(), 100);
    _interval[0] = 0;

    sf::Color penColor = sf::Color::Black;
    sf::Color filling_color [5] = {sf::Color(72,12,135), sf::Color(88,15,160), sf::Color(111,19,205), sf::Color(163,85,242), sf::Color(202,157,250)};
    int radius [5] = {100, 80, 60, 40, 20};

    for (int i{}; i<5; ++i){
        sf::CircleShape *c = new sf::CircleShape(radius[i]);

        c->setFillColor(filling_color[i]);

        c->setPosition(_w/2 - radius[i], _h/2 - radius[i]);

        c->setFillColor(filling_color[i]);
        c->setOutlineColor(penColor);

        _shapes.push_back(c);
    }

}

void Animation::animate (){
    sf::Event event;
    sf::Clock clock;
    unsigned iter {};

    while (_window.isOpen()) {
        while (_window.pollEvent(event)) {
            if(event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
                _window.close();
        }

        if (iter == _shapes.size()){
            _window.close();
        }

        else if (clock.getElapsedTime().asMilliseconds() > _interval[iter]){
            _window.clear(_background);
            _window.draw(*_shapes[iter]);
            _window.display();

            iter++;
            clock.restart();
        }
    }
}

Animation::~Animation(){
    for (auto el : _shapes)
        delete el;
}