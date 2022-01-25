//
// Created by Celeste Tan 10/19/21.
//

#ifndef DRAWINGMAIN_ITEMLIST_H
#define DRAWINGMAIN_ITEMLIST_H

#include <list>
#include "GuiComponent.h"
#include "Item.h"

class ItemList : public GuiComponent {
private:
    std::vector<Item> itemList;
    float itemPosY = 3.0;

public:
    ItemList();

    ItemList(const std::vector<std::string>& itemVec, sf::Vector2f itemPos);

    void insert(const std::string& itemStr, sf::Vector2f itemPos);


    void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
};


#endif //DRAWINGMAIN_ITEMLIST_H
