//
// Created by Celeste Tan 10/19/21.
//

#ifndef DRAWINGMAIN_INPUTBOX_H
#define DRAWINGMAIN_INPUTBOX_H
#include "GuiComponent.h"
#include "MouseEvents.h"


class InputBox : public sf::Drawable {
public:
    InputBox();
    InputBox(std::string name, sf::Vector2f pos);
    void centerText();
    sf::FloatRect getGlobalBounds();
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();

private:
    sf::RectangleShape box;
    sf::Text menuText;
    sf::Color clickColor= sf::Color(71,71,71);
    bool ifOptionClicked;



};


#endif //DRAWINGMAIN_INPUTBOX_H
