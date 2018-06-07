#pragma once
#include <map> 
#include <string>
#include <SFML/Graphics.hpp>

namespace animation {
    class Config {
    public:
        Config() = default;
        explicit Config(std::string inputFile) : _inputFile{inputFile} {}
    
        unsigned _width;
        unsigned _height;
        std::string _inputFile;
        std::string _outputDir;
        std::map<std::string, sf::Color> _definedColors;
    };

}