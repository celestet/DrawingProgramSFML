//
// Created by Celeste Tan on 10/5/21.
//

#ifndef DRAWINGMAIN_GUICOMPONENT_H
#define DRAWINGMAIN_GUICOMPONENT_H
#include <iostream>
#include <string>
#include <cstdlib>
#include "SFML/Graphics.hpp"
#include "EventHandler.h"
#include "Font.h"
#include "States.h"
#include "Image.h"

class GuiComponent : public EventHandler,
                     public Font,
                     public Image,
                     public States,
                     public sf::Drawable,
                     public sf::Transformable {
public:
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const = 0;

    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event) = 0;
    virtual void update() = 0;
};


#endif //LOGOMAKER_GUICOMPONENT_H
