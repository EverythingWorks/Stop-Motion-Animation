#include "Controller.h"

namespace animation {
    void Controller::speedUp() {
        if (_speedMultiplier / 2 >= minSpeedMultiplier)
            _speedMultiplier /= 2;
       
    }

    void Controller::speedDown() {
         if  (_speedMultiplier * 2 <= maxSpeedMultiplier)
            _speedMultiplier *= 2;
    }
}