//
// Created by Celeste Tan on 11/18/21.
//

#ifndef DRAWINGMAIN_MOUSEEVENTS_H
#define DRAWINGMAIN_MOUSEEVENTS_H

#include "SFML/Graphics.hpp"
#include <iostream>

template<class T>
class MouseEvents {
public:
    static bool objectClicked(T &object, sf::RenderWindow &window);

    static bool windowClicked(sf::RenderWindow &window, sf::Event event);


    static bool hovered(T &object, sf::RenderWindow &window);

};


#include "MouseEvents.cpp"

#endif //DRAWINGMAIN_MOUSEEVENTS_H
