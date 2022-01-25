//
// Created by Celeste Tan on 10/19/21.
//

#include "DrawingSpace.h"


void DrawingSpace::setSize(sf::Vector2f size) {
    box.setSize(size);
}

void DrawingSpace::setPosition(sf::Vector2f pos) {
    box.setPosition(pos);
}

void DrawingSpace::setColor(sf::Color c) {
    box.setFillColor(c);

}

void DrawingSpace::setOutlineColor() {
    box.setOutlineColor(sf::Color::Black);

}

void DrawingSpace::setOutlineThickness() {
    box.setOutlineThickness(10);

}

void DrawingSpace::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(box);
}

DrawingSpace::DrawingSpace() {
    setSize({1900, 1100});
    setPosition({bx, by});
    setColor(sf::Color::White);
    setOutlineColor();
    setOutlineThickness();
}

sf::FloatRect DrawingSpace::getGlobalBounds() {
    return box.getGlobalBounds();
}

void DrawingSpace::addEventHandler(sf::RenderWindow &window, sf::Event event) {

}

void DrawingSpace::update() {

}


