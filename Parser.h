#pragma once

#include <vector>
#include <fstream>

#include "Config.h"
#include "Frame.h"
#include "Toolkit.h"

namespace animation {
class Parser {
public:
    Parser() = delete;
    Parser(std::string filePath);
    bool loadNextFrame();

    Config _config;
    Toolkit _colors;
    std::vector<Frame> _frames;
    std::ifstream _input;

};

}