#pragma once 


namespace animation
{
    class Controller {
    public:
        Controller() : _isPlaying{false}, _speedMultiplier{1.0} {}
        virtual ~Controller() {}
        bool & isPlaying()  { return _isPlaying; }
        double getRealTimeInterval(const int timeInterval) { return timeInterval * _speedMultiplier; }
        void speedUp();
        void speedDown();

    private:
        static constexpr double maxSpeedMultiplier {8.0};
        static constexpr double minSpeedMultiplier {1.0/8.0};
        bool _isPlaying;
        double _speedMultiplier; 

    };
} // animation
