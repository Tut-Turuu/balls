
#include "ball.hpp"



int main() {

    sf::RenderWindow window(sf::VideoMode(800,700), "shary");

    window.setVerticalSyncEnabled(true);

    Ball ball1(sf::Color::Green, sf::Vector2f(0.f, 0.f), sf::Vector2f(200.f, 200.f), 20.f);
    Ball ball2(sf::Color::Red, sf::Vector2f(0.f, 0.f), sf::Vector2f(300.f, 200.f), 70.f);
    Ball ball3(sf::Color::Blue, sf::Vector2f(0.f, 100.f), sf::Vector2f(450.f, 200.f), 30.f);
    Ball ball4(sf::Color::Yellow, sf::Vector2f(0.f, 100.f), sf::Vector2f(100.f, 200.f), 10.f);


    std::vector<Ball*> balls;
    balls.push_back(&ball1);
    balls.push_back(&ball2);
    balls.push_back(&ball3);
    balls.push_back(&ball4);



    sf::Clock myClock;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) {

            switch (event.type) {

                case sf::Event::Closed:
                    window.close();
                    break;

            }  
        }
        sf::Time delta = myClock.restart();
        for (auto ball : balls) {
            ball->move(delta);
            ball->draw(window);
        }
        window.display();
        window.clear();
    
    } 
}
