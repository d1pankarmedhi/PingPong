#pragma once // prevent compiler from processing the file more than once.
#include <SFML/Graphics.hpp>

class Bat
{
private:
    sf::Vector2f m_Position;    // hold horizontal and vertical position of bat
    sf::RectangleShape m_Shape; // Bat shape
    float m_Speed = 1000.0f;    // speed
    bool m_MovingRight = false; // movement direction
    bool m_MovingLeft = false;

public:
    Bat(float startX, float startY); // constructor -> init bat position on screen
    sf::FloatRect getPosition();
    sf::RectangleShape getShape();
    void moveRight();
    void moveLeft();
    void stopLeft();
    void stopRight();
    void update(sf::Time dt);
};