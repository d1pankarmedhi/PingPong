#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Ball
{
private:
    Vector2f m_Position;
    sf::Texture m_TextureBall;
    sf::Sprite m_SpriteBall;
    float m_Speed = 700.0f;
    float m_DirectionX = .2f;
    float m_DirectionY = .2f;

public:
    Ball(float startX, float startY);
    FloatRect getPosition();
    sf::Sprite init();
    float getXVelocity();
    void reboundSides(); // when collision is detected
    void reboundBatOrTop();
    void reboundBottom();
    void update(Time dt);
};