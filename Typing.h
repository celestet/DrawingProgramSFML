//
// Created by Celeste Tan on 9/21/21.
//

#ifndef SFMLTYPING_TYPING_H
#define SFMLTYPING_TYPING_H

#include "SFML/Graphics.hpp"
#include <iostream>
#include "Font.h"
#include <string>

class Typing : public sf::Drawable {
private:
    std::string input;
    sf::Text typedText;


public:

    Typing();

    void setText();

    sf::Text getText();

    std::string getSText();

    void addEventHandler(sf::RenderWindow &window, sf::Event event);

    void update();


    virtual void draw(sf::RenderTarget &window, sf::RenderStates states) const;

    void setFont(sf::Font font);

    void setColor(sf::Color color);


    void setSize(int size);
};


#endif //SFMLTYPING_TYPING_H
