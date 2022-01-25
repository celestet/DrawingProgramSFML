#include <iostream>

#include "SFML/Graphics.hpp"

#include "MenuBar.h"
#include "DrawingSpace.h"
#include "Typing.h"

std::list<sf::CircleShape> circles;
std::list<sf::CircleShape>::iterator iter;
float x, y;

int main() {
    sf::RenderWindow win(sf::VideoMode(2800, 1650), "Drawing Program");
    win.setPosition({50, 50});

    sf::Text title;
    title.setFont(Font::getFont());
    title.setString("Title:");
    title.setPosition(20, 120);
    title.setColor(sf::Color::White);
    title.setCharacterSize(100);


    MenuBar menuBar;

    DrawingSpace d;
    d.setPosition({400, 400});


    Typing typing;

    typing.setText();


    while (win.isOpen()) {
        sf::Event mainWinEvent{};
        while (win.pollEvent(mainWinEvent)) {
            if (mainWinEvent.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                win.close();
            }

            menuBar.addEventHandler(win, mainWinEvent);
            typing.addEventHandler(win, mainWinEvent);

        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Middle)) {
            x = (float) sf::Mouse::getPosition((win)).x;
            y = (float) sf::Mouse::getPosition(win).y;


            sf::CircleShape point(10);
            point.setPosition(x, y);
            point.setFillColor(sf::Color::Black);

            circles.push_back(point);
        }
//
        if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
            x = (float) sf::Mouse::getPosition((win)).x;
            y = (float) sf::Mouse::getPosition(win).y;


            sf::CircleShape point(25);
            point.setPosition(x, y);
            point.setFillColor(sf::Color::White);
            circles.push_back(point);
        }

        win.clear(sf::Color::Black);

        win.draw(d);
        win.draw(menuBar);
        win.draw(typing);
        win.draw(title);


        iter = circles.begin();

        while (iter != circles.end()) {
            win.draw(*iter);
            iter++;
        }

        menuBar.update();


        win.display();
    }
    return 0;
}









