//
// Created by Celeste Tan on 11/30/21.
//

#ifndef DRAWINGMAIN_MOUSEEVENTSFILE_H
#define DRAWINGMAIN_MOUSEEVENTSFILE_H
#include "SFML/Graphics.hpp"
#include "ObjectStates.h"
#include "States.h"
template<class T>
class MouseEventsFile {
public:
    static bool mouseClicked1(T &object, sf::RenderWindow &window);

    static bool mouseClicked(sf::RenderWindow &window, sf::Event event);

    static bool mouseDoubleClicked();

    static bool mouseTripleClicked();

    static bool draggedOver(T &object, sf::RenderWindow &window, sf::Event event);

    static bool hovered(T &object, sf::RenderWindow &window);

    static void toggleState(sf::Mouse::Button button, ObjectStates state, States &states);


    MouseEventsFile();

private:
    static int click;
    static sf::Clock clock;
    static sf::Time elapse;

    static int countClicks(sf::Event event);
};

#include "MouseEventsFile.cpp"

#endif //DRAWINGMAIN_MOUSEEVENTSFILE_H
