#include "Animation.h"

int main() {

    Animation a;
    a.animate();
    /*
    //part will be read from file
    int w = 800, h = 650;
    int interval[5] = {100, 1000, 10000, 10, 100};
    sf::Color background_color = sf::Color::Black;
    sf::Color pen_color = sf::Color::Black;
    sf::Color filling_color [5] = {sf::Color(72,12,135), sf::Color(88,15,160), sf::Color(111,19,205), sf::Color(163,85,242), sf::Color(202,157,250)};
    int radius [5] = {100, 80, 60, 40, 20};

    //loading the shapes into vector - parser
    std::vector <sf::CircleShape*> shapes;

    for (int i{}; i<5; ++i){
        shapes.push_back(new sf::CircleShape(radius[i]));
        shapes[i]->setFillColor(filling_color[i]);

        shapes[i]->setPosition(w/2 - radius[i], h/2 - radius[i]);

        shapes[i]->setFillColor(filling_color[i]);
        shapes[i]->setOutlineColor(pen_color);
    }


    //app
    sf::RenderWindow window(sf::VideoMode(w, h), "Animation",sf::Style::Titlebar | sf::Style::Close);
    sf::Event event;
    sf::Clock clock;
    unsigned iter {};

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if(event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
                window.close();
        }

        if (clock.getElapsedTime().asMilliseconds() > interval[iter]){
            window.clear(sf::Color::Black);
            window.draw(*shapes[iter]);
            iter = (iter+1)%5;
            clock.restart();
        }

        window.display();
    }

    for (int i{}; i<5; ++i){
        delete shapes[i];
    }
*/
    return 0;
}
