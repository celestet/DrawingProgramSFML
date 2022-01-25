//
//Created by Celeste Tan 10/19/21.
//

#include "InputBox.h"


InputBox::InputBox() {
    box.setSize({200, 80});
    box.setFillColor(sf::Color::Transparent);
    box.setOutlineThickness(2);
    box.setOutlineColor(sf::Color::Transparent);

    menuText.setFont(Font::getFont());
    menuText.setCharacterSize(box.getSize().y * 0.4);
    menuText.setFillColor(sf::Color::White);
    menuText.setString("Test");
    centerText();
    ifOptionClicked = false;
}

InputBox::InputBox(std::string name, sf::Vector2f pos) {
    box.setSize({200, 80});
    box.setFillColor(sf::Color::Transparent);
    box.setOutlineThickness(2);
    box.setOutlineColor(sf::Color::Transparent);
    box.setPosition(pos.x, pos.y);

    menuText.setFont(Font::getFont());
    menuText.setCharacterSize(box.getSize().y * 0.4);
    menuText.setFillColor(sf::Color::White);
    menuText.setString(name);
    centerText();
    ifOptionClicked = false;
}

void InputBox::centerText() {
    float x = box.getPosition().x + (box.getSize().x - menuText.getGlobalBounds().width) / 2;
    float y = box.getPosition().y + (box.getSize().y - menuText.getCharacterSize()) / 2;
    menuText.setPosition(x, y);
}

sf::FloatRect InputBox::getGlobalBounds() {
    return box.getGlobalBounds();

}

void InputBox::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(box);
    window.draw(menuText);
}

void InputBox::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if (MouseEvents<sf::RectangleShape>::objectClicked(box, window)) {
        ifOptionClicked = true;
    } else if (MouseEvents<sf::Window>::windowClicked(window, event)) {
        ifOptionClicked = false;
    }
}

void InputBox::update() {
    if (ifOptionClicked) {
        box.setFillColor(clickColor);
    } else {
        box.setFillColor(sf::Color::Transparent);
    }
}
