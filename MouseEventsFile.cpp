//
// Created by Celeste Tan on 11/30/21.
//

#ifndef DRAWINGMAIN_MOUSEEVENTSFILE_CPP
#define DRAWINGMAIN_MOUSEEVENTSFILE_CPP

#include "MouseEventsFile.h"
#include <iostream>

template<class S>
int MouseEventsFile<S>::click;
template<class S>
sf::Time MouseEventsFile<S>::elapse;
template<class S>
sf::Clock MouseEventsFile<S>::clock;


template<class T>
MouseEventsFile<T>::MouseEventsFile() {

}

template<class T>
bool MouseEventsFile<T>::mouseClicked1(T &object, sf::RenderWindow &window) {
    States states;
    toggleState(sf::Mouse::Left, HIDDEN, states);

    return true;

}


template<class T>
bool MouseEventsFile<T>::mouseClicked(sf::RenderWindow &window, sf::Event event) {

    if ((sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Mouse::isButtonPressed(sf::Mouse::Right))) {

        if (countClicks(event) == 1) {
            return true;
        }
    }
}

template<class T>
bool MouseEventsFile<T>::mouseDoubleClicked() {
    sf::Event event;
    if ((sf::Mouse::isButtonPressed(sf::Mouse::Left))) {

        if (countClicks(event) == 2) {
            return true;
        }
    }


}

template<class T>
bool MouseEventsFile<T>::mouseTripleClicked() {

    sf::Event event;
    if ((sf::Mouse::isButtonPressed(sf::Mouse::Left))) {

        if (countClicks(event) == 3) {
            return true;
        }
    }
}

template<class T>
bool MouseEventsFile<T>::draggedOver(T &object, sf::RenderWindow &window, sf::Event event) {
    States states;
    toggleState(sf::Mouse::Left, DRAG, states);
    return true;
}

template<class T>
bool MouseEventsFile<T>::hovered(T &object, sf::RenderWindow &window) {
    sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);
    return object.getGlobalBounds().contains(mpos);


}


template<class T>
int MouseEventsFile<T>::countClicks(sf::Event event) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (click == 0)
            clock.restart();
        click++;
        elapse = clock.getElapsedTime();
        return click;
    }
}

template<class T>
void MouseEventsFile<T>::toggleState(sf::Mouse::Button button, ObjectStates state, States &states) {
    if (sf::Mouse::isButtonPressed(button)) {
        if (!states.checkState(static_cast<States::ObjectState>(state))) {
            states.enableState(static_cast<States::ObjectState>(state));
        } else {
            states.disableState(static_cast<States::ObjectState>(state));
        }
    }
}


#endif //DRAWINGMAIN_MOUSEEVENTSFILE_CPP
