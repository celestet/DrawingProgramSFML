//
// Created by Celeste Tan 10/19/21.
//

#include "ItemList.h"

ItemList::ItemList() {
    itemPosY = 0.0;
}

ItemList::ItemList(const std::vector<std::string> &itemVec, sf::Vector2f itemPos) {
    for (int i = 0; i < itemVec.size(); ++i) {
        insert(itemVec.at(i), itemPos);
    }
}

void ItemList::insert(const std::string &itemStr, sf::Vector2f itemPos) {
    Item itemInserted;

    itemInserted.setItemPos(itemPos.x, itemPos.y);

    itemInserted.setItemTxtStr(itemStr);

    itemPosY += itemInserted.getItemBoxSize().y;
    itemInserted.setItemPos(itemPos.x, itemPosY);
    itemList.push_back(itemInserted);
}

void ItemList::draw(sf::RenderTarget &window, sf::RenderStates states) const {

    for (int i = 0; i < itemList.size(); i++) {
        window.draw(itemList[i]);
    }
}

void ItemList::addEventHandler(sf::RenderWindow &window, sf::Event event) {


    std::vector<Item>::iterator itemListIter = itemList.begin();

    while (itemListIter != itemList.end()) {
        (*itemListIter).addEventHandler(window, event);
        ++itemListIter;
    }
}

void ItemList::update() {

}
