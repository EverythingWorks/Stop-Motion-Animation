#include "Animation.h"
#include <experimental/filesystem> 
#include "Parser.h"
#include <iostream>
#include "Font.h"

namespace animation {

namespace fs = std::experimental::filesystem;

Animation::Animation() : _ctrl(new Controller) {
    if (_font.loadFromMemory(&__04B_20__, __04B_20__len))
    {
        _text.setFont(_font); 
        _text.setString("PRESS SPACE \nTO PLAY");
        _text.setCharacterSize(45);
        _text.setFillColor(sf::Color::White);
        _text.setStyle(sf::Text::Bold);
    }
}

void Animation::run() {
    Parser parser {"mySample.txt"};

    for (int i {}; parser.loadNextFrame(); ++i) { /* empty */ }

    _window.create(sf::VideoMode(parser._config._width, parser._config._height),"Animation",sf::Style::Titlebar | sf::Style::Close);
    sf::FloatRect textRect = _text.getLocalBounds();
    _text.setPosition(parser._config._width/2 - textRect.width/2., parser._config._height/2 - textRect.height/2.);

    sf::Event event;
    sf::Clock clock;

    while(_window.isOpen()) {
        while (_window.pollEvent(event)) {
            if(event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
                _window.close();
        if (event.type == sf::Event::KeyPressed)
            if(event.key.code == sf::Keyboard::Space)
                _ctrl->isPlaying() = true;
        }

        if ( _ctrl->isPlaying()){
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
            _ctrl->isPlaying() = false;
        }
        else {
            _window.clear(sf::Color::Blue);
            _window.draw(_text);
            _window.display();
        }



    }

    //if (!fs::is_directory("animation_output") || !fs::exists("animation_output"))  // Check if src folder exists
    //    fs::create_directory("animation_output"); // create src folder
    //int i {};
    //for (const auto & frame : parser._frames) {
    //    frame._image.saveToFile("animation_output/" + std::to_string(i) + ".bmp");
    //    ++i;
    //}

}

}

