//
// Created by Celeste Tan 10/19/21.
//

#include "DropDownMenu.h"

DropDownMenu::DropDownMenu() {

}

DropDownMenu::DropDownMenu(const std::string &inputBoxName, const std::vector<std::string> &dropDownListVec,
                           sf::Vector2f dropDownListPos) {
    dropDownInputBox = InputBox(inputBoxName, dropDownListPos);
    dropDownList = ItemList(dropDownListVec, dropDownListPos);
}

void DropDownMenu::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(dropDownInputBox);
    if (showList) {
        window.draw(dropDownList);
    }
}

void DropDownMenu::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    dropDownInputBox.addEventHandler(window, event);
    dropDownList.addEventHandler(window, event);

    if (MouseEvents<InputBox>::objectClicked(dropDownInputBox, window)) {
        showList = true;
    } else if (MouseEvents<sf::Window>::windowClicked(window, event)) {
        showList = false;
    }
}

void DropDownMenu::update() {
    dropDownInputBox.update();
}
