//
// Created by Celeste Tan 11/22/21.
//

#ifndef DRAWINGMAIN_MENUBAR_H
#define DRAWINGMAIN_MENUBAR_H

#include "GuiComponent.h"
#include "DropDownMenu.h"

class MenuBar : public GuiComponent {
private:
    sf::RectangleShape menuBar;
    sf::Color menuBarColor = sf::Color(71, 71, 71, 100);
    std::vector<std::string> open{"Open Project"};
    std::vector<std::string> save{"Save Project"};
    std::vector<std::string> quit{"Quit"};

    DropDownMenu Open = DropDownMenu("Open", open, {0, 0});
    DropDownMenu Save = DropDownMenu("Save", save, {400, 0});
    DropDownMenu Quit = DropDownMenu("Close", quit, {800, 0});

public:
    MenuBar();

    void draw(sf::RenderTarget &window, sf::RenderStates states) const;

    void addEventHandler(sf::RenderWindow &window, sf::Event event);

    void update();
};


#endif //DRAWINGMAIN_MENUBAR_H
