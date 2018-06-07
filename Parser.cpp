#include "Parser.h"
#include <sstream>
#include <algorithm>
#include <iostream>
#include <cmath>


namespace animation {
Parser::Parser(std::string filePath) : _config{filePath}, _input{filePath}  {
    std::string line;
    std::getline(_input, line);
    std::istringstream iss {line};
    (iss >> _config._width).ignore(256, ' ') >> _config._height;
}

bool Parser::loadNextFrame() {
    std::string line, instruction;
    if (!std::getline(_input, line))
        return false;

    std::istringstream iss {line};
    unsigned frameNumber;
    unsigned timeInterval;
    
    (iss >> frameNumber).ignore(256, ' ') >> timeInterval;


    
    sf::RenderTexture renderTexture;
    renderTexture.create(_config._width, _config._height);
    renderTexture.clear(_colors._backgroundColor);

    std::cout << frameNumber << " " << timeInterval << std::endl;

    while(true) {
        if (!std::getline(_input, line))
            return false;
        
        std::istringstream ss {line};
        ss >> instruction;
        std::transform(instruction.begin(), instruction.end(), instruction.begin(), ::tolower); // to lower case
        
        std::cout << instruction << "." << std::endl;
        if (instruction == "stop" || instruction == "st") {
            break;
        }
        if (instruction == "prostokat" || instruction == "pr") {
            float x1, x2, y1, y2;
            int flag;
            (((ss.ignore(256, ' ') >> x1).ignore(256, ' ') >> y1).ignore(256, ' ') >> x2).ignore(256, ' ') >> y2;
            ss.ignore(256, ' ') >> flag;
            sf::RectangleShape rectangle(sf::Vector2f(x2 - x1, y2 - y1)) ;
            rectangle.setPosition(x1, y1);
            rectangle.setOutlineColor(_colors._outlineColor);
            rectangle.setOutlineThickness(_colors._outlineThickness);
            if (flag)
                rectangle.setFillColor(_colors._fillColor);
            renderTexture.draw(rectangle);
        }
        if (instruction == "kolor_piora" || instruction == "kp" || instruction == "kolor_wypelnienia" || instruction == "kw") {
            int r, g, b;
            ((ss.ignore(256, ' ') >> r).ignore(256, ' ') >> g).ignore(256, ' ') >> b;
            sf::Color newColor(r, g, b);
            if (instruction == "kolor_wypelnienia" || instruction == "kw") 
                _colors._fillColor = newColor;
            else    
                _colors._outlineColor = newColor;            
        }
        if (instruction == "punkt" || instruction == "pt") {
            float x, y;
            (ss.ignore(256, ' ') >> x).ignore(256, ' ') >> y;
            sf::Vertex point[] = {sf::Vertex(sf::Vector2f(x, y), _colors._outlineColor)};
            renderTexture.draw(point, 1, sf::Points);
        }
        if (instruction== "elipsa" || instruction== "el") {
            float x1, x2, y1, y2;
            int flag;
            (((ss.ignore(256, ' ') >> x1).ignore(256, ' ') >> y1).ignore(256, ' ') >> x2).ignore(256, ' ') >> y2;
            ss.ignore(256, ' ') >> flag;

            float radius_x = (x2 - x1)/2;
            float radius_y = (y2 - y1)/2;
            unsigned short quality = 70;

            sf::ConvexShape ellipse;
            ellipse.setPointCount(quality);

            for(unsigned i=0; i<quality; ++i){
                float rad = (360/quality*i)/(360/M_PI/2);
                float x = cos(rad)*radius_x;
                float y = sin(rad)*radius_y;

                ellipse.setPoint(i,sf::Vector2f(x,y));
            };

            ellipse.setOutlineColor(_colors._outlineColor);

            if(flag)
                ellipse.setFillColor(_colors._fillColor);

            ellipse.setPosition(x1 + radius_x, y1 + radius_y);
            renderTexture.draw(ellipse);

        }
        if (instruction== "linia" || instruction == "ln") {
            float x1, x2, y1, y2;
            (((ss.ignore(256, ' ') >> x1).ignore(256, ' ') >> y1).ignore(256, ' ') >> x2).ignore(256, ' ') >> y2;
            sf::Vertex line[] = {
                    sf::Vertex(sf::Vector2f(x1, y1), _colors._outlineColor),
                    sf::Vertex(sf::Vector2f(x2, y2), _colors._outlineColor)
            };
            renderTexture.draw(line, 2, sf::Lines);
        }
        if (instruction == "rozmiar_piora" || instruction == "rp" ) {
            float s;
            ss.ignore(256, ' ') >> s;
            _colors._outlineThickness = s;
        }
        if (instruction == "kolo" || instruction == "kl" ) {
            float x, y, radius;
            int flag;
            ((ss.ignore(256, ' ') >> x).ignore(256, ' ') >> y).ignore(256, ' ') >> radius;
            ss.ignore(256, ' ') >> flag;
            sf::CircleShape circle (radius);
            circle.setPosition(x, y);
            circle.setOutlineColor(_colors._outlineColor);
            circle.setOutlineThickness(_colors._outlineThickness);
            if (flag)
                circle.setFillColor(_colors._fillColor);
            renderTexture.draw(circle);
        }

    }


    _frames.emplace_back(renderTexture.getTexture().copyToImage(), timeInterval);

    return true;
}

}