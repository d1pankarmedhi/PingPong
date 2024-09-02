#include "Ball.h"
#include <SFML/Graphics.hpp>

Ball::Ball(float startX, float startY) : m_Position(startX, startY)
{
    // m_Shape.setSize(sf::Vector2f(10, 10));
    m_TextureBall.loadFromFile("images/ball.png");
    m_SpriteBall.setTexture(m_TextureBall);
    m_SpriteBall.setScale(0.5, 0.5);
    m_SpriteBall.setOrigin(50, 0);
    m_SpriteBall.setPosition(m_Position);
}

FloatRect Ball::getPosition()
{
    return m_SpriteBall.getGlobalBounds();
}

sf::Sprite Ball::init()
{
    return m_SpriteBall;
}
// RectangleShape Ball::getShape()
// {
//     return m_SpriteBall;
// }

// get direction of ball
float Ball::getXVelocity()
{
    return m_DirectionX;
}

// reversing the horizontal direction when it hits sides
void Ball::reboundSides()
{
    m_DirectionX = -m_DirectionX;
}
// reverse ball vertically when hits the top
void Ball::reboundBatOrTop()
{
    m_DirectionY = -m_DirectionY;
    m_Speed += m_Speed * 0.1f;
}

// resets the ball when player misses. Sets the postion to top center
void Ball::reboundBottom()
{
    m_Position.y = 0;
    m_Position.x = 500;
    m_DirectionY = -m_DirectionY;
}

// update ball movement
void Ball::update(Time dt)
{
    // Update the ball's position
    m_Position.y += m_DirectionY * m_Speed * dt.asSeconds();
    m_Position.x += m_DirectionX * m_Speed * dt.asSeconds();
    // Move the ball
    m_SpriteBall.setPosition(m_Position);
}