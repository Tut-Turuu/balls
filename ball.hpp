#include <SFML/Graphics.hpp>
#include <iostream>
#include "config.hpp"




class Ball {


    sf::Color color;
    sf::Vector2f velocity;
    sf::Vector2f pos;
    sf::CircleShape shape;


public:

    Ball(sf::Color color, sf::Vector2f velocity, sf::Vector2f pos, float radius): color(color), velocity(velocity), pos(pos) {
        shape.setFillColor(color);
        shape.setPosition(pos);
        shape.setRadius(radius);
        shape.setOrigin(sf::Vector2f{radius, radius});

    }

    bool is_coliding() {
        if (velocity.y < 0 && (pos.y + shape.getRadius()) > bottom_border) return false;
        return (pos.y + shape.getRadius()) > bottom_border;
    }

    void move(sf::Time deltaTime) {
        pos += velocity * deltaTime.asSeconds();
        
        if (is_coliding()) {
            bounce();
        }
        velocity += (g - velocity * shape.getRadius() * 0.01f) * deltaTime.asSeconds(); 
        shape.setPosition(pos);
    }

    void bounce() {
        velocity.y = - velocity.y;
    }

    void draw(sf::RenderWindow& window) {
        window.draw(shape);
    }
};
