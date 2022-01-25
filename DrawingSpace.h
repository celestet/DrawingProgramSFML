//
// Created by Celeste Tan on 10/19/21.
//

#ifndef DRAWINGMAIN_DRAWINGSPACE_H
#define DRAWINGMAIN_DRAWINGSPACE_H
#include "SFML/Graphics.hpp"
#include "GuiComponent.h"

class DrawingSpace: public GuiComponent{
public:
    DrawingSpace();
    void setSize(sf::Vector2f size);
    void setPosition(sf::Vector2f pos);
    void setColor(sf::Color c);
    void setOutlineColor();
    void setOutlineThickness();

    sf::FloatRect getGlobalBounds();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual  void update();


private:
    sf::RectangleShape box;
    float bx, by;
    sf::Vector2f size;
};


#endif //DRAWINGMAIN_DRAWINGSPACE_H
