#include "Parser.h"
#include <sstream>
#include <algorithm>
#include <iostream>


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

        }
        if (instruction== "elipsa" || instruction== "el") {

        }
        if (instruction== "linia" || instruction == "ln") {
            
        }
        if (instruction == "rozmiar_piora" || instruction == "rp" ) {

        }

    }


    _frames.emplace_back(renderTexture.getTexture().copyToImage(), timeInterval);

    return true;
}

}