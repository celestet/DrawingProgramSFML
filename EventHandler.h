//
// Created by Celeste Tan 10/4/21.
//

#ifndef DRAWINGMAIN_EVENTHANDLER_H
#define DRAWINGMAIN_EVENTHANDLER_H
#include "SFML/Graphics.hpp"

class EventHandler {
public:
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event) = 0;
    virtual void update() = 0;
};


#endif //DRAWINGMAIN_EVENTHANDLER_H
