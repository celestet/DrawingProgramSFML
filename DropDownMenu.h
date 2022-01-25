//
// Created by Celeste Tan 10/19/21.
//

#ifndef DRAWINGMAIN_DROPDOWNMENU_H
#define DRAWINGMAIN_DROPDOWNMENU_H

#include "GuiComponent.h"
#include "ItemList.h"
#include "InputBox.h"

class DropDownMenu : public GuiComponent {
private:
    ItemList dropDownList;
    InputBox dropDownInputBox;
    bool showList = false;

public:
    DropDownMenu();

    DropDownMenu(const std::string &inputBoxName, const std::vector<std::string> &dropDownListVec,
                 sf::Vector2f dropDownListPos);


    void draw(sf::RenderTarget &window, sf::RenderStates states) const;


    void addEventHandler(sf::RenderWindow &window, sf::Event event);

    void update();
};


#endif //DRAWINGMAIN_DROPDOWNMENU_H
