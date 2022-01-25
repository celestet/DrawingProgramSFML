//
// Created by Celeste Tan 11/22/21.
//

#include "MenuBar.h"

MenuBar::MenuBar() {
    menuBar.setSize({2800, 80});
    menuBar.setFillColor(menuBarColor);
}

void MenuBar::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(menuBar);
    window.draw(Open);
    window.draw(Save);
    window.draw(Quit);
}

void MenuBar::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    Open.addEventHandler(window, event);
    Save.addEventHandler(window, event);
    Quit.addEventHandler(window, event);
}

void MenuBar::update() {
    Open.update();
    Save.update();
    Quit.update();
}
