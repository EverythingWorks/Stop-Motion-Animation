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
        _text.setString("PRESS SPACE \n\tTO PLAY\n\nPRESS S TO \n\tSAVE");
        _text.setCharacterSize(45);
        _text.setFillColor(sf::Color::White);
        _text.setStyle(sf::Text::Bold);

        _window.setVerticalSyncEnabled(false);
    }
}

void Animation::run() {
    Parser parser {"mySample.txt"};

    parser._config._width > parser._config._height ? _text.setCharacterSize(0.07 * parser._config._height) : _text.setCharacterSize(0.05 * parser._config._width);

    //while(parser.loadNextFrame()){}
    _window.create(sf::VideoMode(parser._config._width, parser._config._height),"Animation",sf::Style::Titlebar | sf::Style::Close);
    sf::FloatRect textRect = _text.getLocalBounds();

    _text.setPosition(parser._config._width/2 - textRect.width/2., parser._config._height/2 - textRect.height/2.);

    sf::Event event;
    sf::Clock clock;
    auto it = parser._frames.begin();
    bool is_loaded{false};

    while(_window.isOpen()) {
        if (!is_loaded){
            int i{};

            sf::Text text;
            text.setFont(_font);
            text.setCharacterSize(45);
            parser._config._width > parser._config._height ? text.setCharacterSize(0.07 * parser._config._height) : text.setCharacterSize(0.05 * parser._config._width);
            text.setPosition(parser._config._width/2 - textRect.width/2., parser._config._height/2 - textRect.height/2.);
            text.setFillColor(sf::Color::White);
            text.setStyle(sf::Text::Bold);

            sf::RectangleShape strip;
            sf::RectangleShape loading_strip;
            strip.setPosition(parser._config._width*0.1, parser._config._height*0.7);
            strip.setFillColor(sf::Color(15, 16, 17));
            strip.setSize(sf::Vector2f(parser._config._width*0.8, 50));

            loading_strip.setPosition(parser._config._width*0.1 + 2, parser._config._height*0.7 + 2);
            loading_strip.setFillColor(sf::Color(90, 255, 20));

            while(parser.loadNextFrame()) {
                _window.clear(sf::Color::Blue);
                if (i%36 == 0)
                    text.setString("LOADING.");
                else if (i%36 == 12)
                    text.setString("LOADING..");
                else if (i%36 == 24)
                    text.setString("LOADING...");

                _window.draw(text);
                _window.draw(strip);

                loading_strip.setSize(sf::Vector2f(parser._config._width*0.79 * i / parser._config._framesAmount, 46));
                _window.draw(loading_strip);

                _window.display();
                ++i;
            }

            is_loaded = true;
            it = parser._frames.begin();
        }

        while (_window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                _window.close();
            
            if (event.type == sf::Event::KeyPressed) {
                if(event.key.code == sf::Keyboard::Space) {
                    _ctrl->isPlaying() = true;
                    clock.restart();
                }

                if (event.key.code == sf::Keyboard::Escape)
                    _window.close();
                if (event.key.code == sf::Keyboard::Left)
                    _ctrl->speedDown();
                if (event.key.code == sf::Keyboard::Right)
                    _ctrl->speedUp();
                if(event.key.code == sf::Keyboard::S) {
                    _window.clear(sf::Color::Blue);
                    sf::Text text;
                    text.setFont(_font);
                    text.setString("SAVING");
                    text.setCharacterSize(45);
                    parser._config._width > parser._config._height ? text.setCharacterSize(0.07 * parser._config._height) : text.setCharacterSize(0.05 * parser._config._width);
                    text.setPosition(parser._config._width/2 - textRect.width/2., parser._config._height/2 - textRect.height/2.);
                    text.setFillColor(sf::Color::White);
                    text.setStyle(sf::Text::Bold);
                    _window.draw(text);
                    _window.display();

                    if (!fs::is_directory("animation_output") || !fs::exists("animation_output"))  // Check if src folder exists
                        fs::create_directory("animation_output"); // create src folder
                    int i {};
                    for (const auto & frame : parser._frames) {
                        frame._image.saveToFile("animation_output/" + std::to_string(i) + ".bmp");
                        ++i;
                    }
                    text.setString("SAVED!");
                    _window.draw(text);
                    _window.display();
                }
            }
        }

        if (_ctrl->isPlaying()) {
            if (it == parser._frames.end()) {
                it = parser._frames.begin();
                _ctrl->isPlaying() = false;
                _ctrl->resetMultiplier();
                clock.restart();
            }
            else {
                    _window.clear(sf::Color::Black);
                    sf::Texture text;
                    text.create(parser._config._width, parser._config._height);
                    text.update(it->_image);
                    _window.draw(sf::Sprite(text));
                    _window.display();
                if (clock.getElapsedTime().asMilliseconds() >= _ctrl->getRealTimeInterval(it->_timeInterval)) {
                    ++it;
                    clock.restart(); 
                }

            }
        }

    
        else {
            _window.clear(sf::Color::Blue);
            _window.draw(_text);
            _window.display();
        }



    }

}

}

