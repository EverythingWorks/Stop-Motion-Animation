#include "Animation.h"
#include <experimental/filesystem> 
#include "Parser.h"
#include <iostream>

namespace animation {

namespace fs = std::experimental::filesystem;

Animation::Animation() {
    if (_font.loadFromFile("04B_20__.TTF"))
    {
        _text.setFont(_font);
        _text.setString("PRESS SPACE \nTO PLAY");
        _text.setCharacterSize(45);
        _text.setFillColor(sf::Color::White);
        _text.setStyle(sf::Text::Bold);
    }
}

void Animation::run() {
    Parser parser {"InputSample2.txt"};

    for (int i {}; parser.loadNextFrame(); ++i) { 
        std::cout << "line " << i << std::endl;
    }

    _window.create(sf::VideoMode(parser._config._width, parser._config._height),"Animation",sf::Style::Titlebar | sf::Style::Close);
    sf::FloatRect textRect = _text.getLocalBounds();
    _text.setPosition(parser._config._width/2 - textRect.width/2., parser._config._height/2 - textRect.height/2.);

    sf::Event event;
    sf::Clock clock;
    bool play = false;


    while(_window.isOpen()) {
        while (_window.pollEvent(event)) {
            if(event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
                _window.close();

            if(event.key.code == sf::Keyboard::Space)
                play = true;
        }

        if (play){
            for (unsigned i {}; i < parser._frames.size(); ) {
                if (clock.getElapsedTime().asMilliseconds() > parser._frames[i]._timeInterval) {
                    _window.clear(sf::Color::Black);
                    sf::Texture text;
                    text.create(parser._config._width, parser._config._height);
                    text.update(parser._frames[i]._image);
                    _window.draw(sf::Sprite(text));
                    _window.display();
                    ++i;
                    clock.restart();
                }
            }
            play = false;
        }
        else {
            _window.clear(sf::Color::Blue);
            _window.draw(_text);
            _window.display();
        }



    }

    if (!fs::is_directory("animation_output") || !fs::exists("animation_output")) { // Check if src folder exists
        fs::create_directory("animation_output"); // create src folder
    }
    int i {};
    for (const auto & frame : parser._frames) {
        frame._image.saveToFile("animation_output/" + std::to_string(i) + ".bmp");
        ++i;
    }

}

}

