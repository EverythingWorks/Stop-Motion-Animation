#include "Animation.h"
#include <iterator>


Animation::Animation(std::string path): _window(sf::VideoMode(800, 600), "Animation",sf::Style::Titlebar | sf::Style::Close) {
    //example data - they will be parsed from file
    _w = 800;
    _h = 600;

    _background = sf::Color::Black;

    std::vector<unsigned> interval;
    interval.resize(6); //one more for last frame
    std::fill(interval.begin(), interval.end(), 1000);
    interval[0] = 0;

    sf::Color penColor = sf::Color::Black;
    sf::Color filling_color [5] = {sf::Color(72,12,135), sf::Color(88,15,160), sf::Color(111,19,205), sf::Color(163,85,242), sf::Color(202,157,250)};
    int radius [5] = {100, 80, 60, 40, 20};

    //creating frames
    for (int i{}; i<5; ++i){
        //creating shapes
        sf::CircleShape* c = new sf::CircleShape(radius[i]);

        c->setFillColor(filling_color[i]);
        c->setPosition(_w/2 - radius[i], _h/2 - radius[i]);
        c->setFillColor(filling_color[i]);
        c->setOutlineColor(penColor);

        _shapes.push_back(c);

        //create textures
        sf::RenderTexture renderTexture;
        renderTexture.create(_w, _h);
        renderTexture.clear(_background);
        renderTexture.draw(*_shapes[i]);

        renderTexture.getTexture().copyToImage().saveToFile("img" + std::to_string(i) + ".png");

        _frames.emplace_back(std::make_pair(renderTexture.getTexture(), interval[i]));
    }
}

void Animation::animate (){
    sf::Event event;
    sf::Clock clock;
    std::vector<std::pair<sf::Texture, unsigned >>::iterator frame = _frames.begin();

    while (_window.isOpen()) {
        while (_window.pollEvent(event)) {
            if(event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
                _window.close();
        }

        if (frame == _frames.end()){
            _window.close();
        }

        else if (clock.getElapsedTime().asMilliseconds() > frame->second){
            _window.clear(_background);
            _window.draw(sf::Sprite(frame->first));

            _window.display();
            ++frame;
            clock.restart();
        }
    }
}

Animation::~Animation(){
    for (auto el : _shapes)
        delete el;
}