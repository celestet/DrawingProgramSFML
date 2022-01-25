//
// Created by Celeste Tan 10/19/21.
//

#include "Item.h"

std::string Item::strClicked;

Item::Item() {
    itemBox.setSize({500, 80});
    itemBox.setOutlineColor(itemOutlineColor);
    itemBox.setOutlineThickness(2);
    itemBox.setPosition(500, 500);

    itemTxt.setFont(Font::getFont());
    itemTxt.setCharacterSize(itemBox.getSize().y * 0.35);
    itemTxt.setFillColor(sf::Color::White);
    itemTxt.setString("item test");
    centerItemTxt();
}

void Item::setItemPos(float x, float y) {
    itemBox.setPosition(x + itemBox.getOutlineThickness(), y);
    centerItemTxt();
}

void Item::centerItemTxt() {
    float x = itemBox.getPosition().x + (itemBox.getSize().x - itemTxt.getGlobalBounds().width) / 2;
    float y = itemBox.getPosition().y + (itemBox.getSize().y - itemTxt.getCharacterSize()) / 2;
    itemTxt.setPosition(x, y);
}

void Item::setItemTxtStr(const std::string &itemStr) {
    itemTxt.setString(itemStr);
}

sf::Vector2f Item::getItemBoxSize() {
    return itemBox.getSize();
}

std::string Item::getStrClicked() {
    return strClicked;
}

void Item::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(itemBox);
    window.draw(itemTxt);
}

void Item::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if (MouseEvents<sf::RectangleShape>::hovered(itemBox, window)) {
        itemBox.setFillColor(sf::Color::Blue);
    } else {
        itemBox.setFillColor(itemBgColor);
    }


    if (MouseEvents<sf::RectangleShape>::objectClicked(itemBox, window)) {
        strClicked = itemTxt.getString();
        std::cout << "Item string clicked: " << getStrClicked() << std::endl;
    }

    if (strClicked == "Open Project") {
        f.run();
    }
    if (strClicked == "Save Project") {
        f.save();
    } else if (strClicked == "Quit") {
        window.close();
    }


}

void Item::update() {

}
