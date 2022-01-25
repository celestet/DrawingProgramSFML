//
// Created by Celeste Tan on 9/21/21.
//

#include "Typing.h"


Typing::Typing() {

}

void Typing::setText() {

    typedText.setFont(Font::getFont());


    typedText.setFillColor(sf::Color::White);

    typedText.setPosition({300, 120});


    typedText.setCharacterSize(100);


}

void Typing::setFont(sf::Font font) {
    typedText.setFont(font);
}

void Typing::setColor(sf::Color color) {
    typedText.setFillColor(color);
}


void Typing::setSize(int size) {
    typedText.setCharacterSize(size);
}


void Typing::addEventHandler(sf::RenderWindow &window, sf::Event event) {


    if (event.type == sf::Event::TextEntered) {
        input += event.text.unicode;
        typedText.setString(input);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {

        input.erase(input.end() - 1);
    }


}

void Typing::update() {

}


void Typing::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(typedText);
}

sf::Text Typing::getText() {
    return typedText;
}

std::string Typing::getSText() {
    return input;
}











