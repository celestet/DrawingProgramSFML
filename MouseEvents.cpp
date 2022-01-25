//
// Created by Celeste Tan on 11/18/21.
//

#ifndef DRAWINGMAIN_MOUSEEVENTS_CPP
#define DRAWINGMAIN_MOUSEEVENTS_CPP

#include "MouseEvents.h"

template<class T>
bool MouseEvents<T>::objectClicked(T &object, sf::RenderWindow &window) {
    return sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && hovered(object, window);
}

template<class T>
bool MouseEvents<T>::windowClicked(sf::RenderWindow &window, sf::Event event) {
    if (event.type == event.MouseButtonPressed && event.mouseButton.button == sf::Mouse::Button::Left) {
        return true;
    }
    return false;
}


template<class T>
bool MouseEvents<T>::hovered(T &object, sf::RenderWindow &window) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    if (object.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
        return true;
    }
    return false;
}


#endif //DRAWINGMAIN_MOUSEEVENTS_CPP