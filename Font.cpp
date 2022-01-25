//
// Created by Celeste Tan 9/23/21.
//

#include "Font.h"

sf::Font Font::font;


void Font::loadFont() {
    if (!font.loadFromFile("Raleway-Regular.ttf")) {
        std::cout << "Font::Fail to load font.\n";
    }

}


sf::Font &Font::getFont() {
    loadFont();
    return font;
}



