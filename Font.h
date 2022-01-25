//
// Created by Celeste Tan 9/23/21.
//

#ifndef DRAWINGMAIN_FONT_H
#define DRAWINGMAIN_FONT_H

#include <iostream>
#include "SFML/Graphics.hpp"

class Font {
private:
    static sf::Font font;

public:
    static void loadFont();

    static sf::Font &getFont();
};


#endif //DRAWINGMAIN_FONT_H
