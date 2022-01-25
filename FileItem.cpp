//
// Created by Celeste Tan on 11/3/21.
//

#include "FileItem.h"
#include <iostream>

FileItem::FileItem() : FileItem(Image::icons::FILE, "Directory 1") {

}

FileItem::FileItem(Image::icons icon, std::string text) {

    setIcon(icon);

    itemText.setCharacterSize(30);
    itemText.setFont(Font::getFont());
    itemText.setFillColor(sf::Color::Black);
    itemText.setString(text);

    itemBox.setSize({40, 40});
    itemBox.setFillColor(sf::Color::Transparent);
    itemBox.setPosition(10, 10);

    centerItem();
}

void FileItem::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(icon);
    window.draw(itemBox);
    window.draw(itemText);
}

void FileItem::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        itemText.setFillColor(sf::Color::Blue);
    }
}


sf::Vector2f FileItem::getBoxSize() const {
    return itemBox.getSize();
}


sf::Vector2f FileItem::getBoxPosition() const {
    return itemBox.getPosition();
}

sf::Vector2f FileItem::getTextpos() const {
    return itemText.getPosition();
}

float FileItem::getThickness() const {
    itemBox.getOutlineThickness();
}

std::string FileItem::getItemText() const {

    return itemText.getString();
}

void FileItem::setPosition(sf::Vector2f pos) {
    icon.setPosition(pos);
}

void FileItem::setIcon(Image::icons icon1) {


    icon.setTexture(Image::getImg(icon1));
    setIconScale(icon1);


}

void FileItem::setIconScale(Image::icons icon1) {
    if (icon1 == Image::icons::DIRECTORY) {
        icon.setScale(0.55, 0.55);
    } else if (icon1 == Image::icons::FILE) {
        icon.setScale(0.52, 0.52);
    }
}


void FileItem::setItemText(std::string text) {
    itemText.setString(text);

}


void FileItem::centerItem() {
    float iconX = itemBox.getPosition().x + 15;

    float iconY = itemBox.getGlobalBounds().height / 2 - icon.getGlobalBounds().height / 2 + itemBox.getPosition().y;

    float textX = itemBox.getPosition().x + 125;

    float textY =
            itemBox.getGlobalBounds().height / 2 - itemText.getGlobalBounds().height / 2 + itemBox.getPosition().y;

    icon.setPosition(iconX, iconY);
    itemText.setPosition(textX, textY);
}

sf::FloatRect FileItem::getGlobalBounds() const {
    itemBox.getGlobalBounds();
    itemText.getGlobalBounds();
}
