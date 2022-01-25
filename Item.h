//
// Created by Celeste Tan 10/19/21.
//

#ifndef DRAWINGMAIN_ITEM_H
#define DRAWINGMAIN_ITEM_H

#include "GuiComponent.h"
#include "MouseEvents.h"
#include "Typing.h"
#include "FileWindow.h"
#include "FileTree.h"
#include "DrawingSpace.h"

class Item : public GuiComponent {
private:
    sf::RectangleShape itemBox;
    sf::Text itemTxt;
    sf::Color itemOutlineColor = sf::Color(100, 100, 100);
    sf::Color itemBgColor = sf::Color(71, 71, 71);
    static std::string strClicked;


    FileWindow f;

public:
    Item();

    void setItemPos(float x, float y);

    void setItemTxtStr(const std::string &itemStr);

    void centerItemTxt();

    sf::Vector2f getItemBoxSize();

    static std::string getStrClicked();

    void draw(sf::RenderTarget &window, sf::RenderStates states) const;

    void addEventHandler(sf::RenderWindow &window, sf::Event event);

    void update();
};


#endif //DRAWINGMAIN_ITEM_H
