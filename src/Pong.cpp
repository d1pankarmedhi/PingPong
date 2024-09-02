#include "Bat.h"
#include "Ball.h"
#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1080, 720), "Pong");

    int score = 0;
    int lives = 3;
    bool gameOver = false;

    // create bat at bottom of the screen
    Bat bat(1080 / 2, 720 - 20);

    // create a ball
    Ball ball(1080 / 2, 0);

    // fonts
    sf::Font font;

    // hud settings
    sf::Text hud;
    font.loadFromFile("fonts/KillerTech.ttf");
    hud.setFont(font);
    hud.setCharacterSize(75);
    hud.setFillColor(sf::Color::White);
    hud.setPosition(20, 20);

    // menu settings
    sf::Text menu;
    menu.setFont(font);
    menu.setFillColor(sf::Color::Yellow);
    menu.setCharacterSize(75);
    menu.setPosition(1920 / 2, 1080 / 2);
    std::stringstream menuss;
    menuss << "Game Over";
    menu.setString(menuss.str());

    sf::Clock clock;

    while (window.isOpen())
    {
        // Player input
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        // Handle the player quitting
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window.close();
        }
        // Handle the pressing and releasing of the arrow keys
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            bat.moveLeft();
        }
        else
        {
            bat.stopLeft();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            bat.moveRight();
        }
        else
        {
            bat.stopRight();
        }

        // update delta time
        sf::Time dt = clock.restart();
        bat.update(dt);
        ball.update(dt);

        // update HUD text
        std::stringstream ss;
        ss << "Score: " << score << " Lives: " << lives;
        hud.setString(ss.str());

        // handle collision
        // ball hitting the bottom
        if (ball.getPosition().top > window.getSize().y)
        {
            // reverse ball direction
            ball.reboundBottom();
            // remove a life
            lives--;
            // check for zero lives
            if (lives < 1)
            {
                // reset score and lives
                score = 0;
                lives = 3;
            }
        }
        // ball hitting top of screen
        if (ball.getPosition().top < 0)
        {
            ball.reboundBatOrTop();
            score++; // add point
        }
        // ball hitting sides
        if (ball.getPosition().left < 0 || ball.getPosition().left + ball.getPosition().width > window.getSize().x)
        {
            ball.reboundSides();
        }
        // ball hitting the bat
        if (ball.getPosition().intersects(bat.getPosition()))
        {
            // reverse the ball and score a point
            ball.reboundBatOrTop();
        }

        // draw on screen
        window.clear();
        window.draw(hud);
        window.draw(bat.getShape());
        window.draw(ball.init());
        window.display();
    }
    return 0;
}