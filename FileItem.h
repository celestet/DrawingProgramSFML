//
// Created by Celeste Tan on 11/3/21.
//

#ifndef DRAWINGMAIN_FILEITEM_H
#define DRAWINGMAIN_FILEITEM_H

#include "Image.h"
#include <string>
#include "Font.h"
#include "MouseEventsFile.h"
#include "SFML/Graphics.hpp"

class FileItem : public sf::Drawable {
public:
    FileItem();

    FileItem(Image::icons icon, std::string text);

    virtual void draw(sf::RenderTarget &window, sf::RenderStates states) const;


    virtual void addEventHandler(sf::RenderWindow &window, sf::Event event);


    sf::FloatRect getGlobalBounds() const;

    sf::Vector2f getBoxSize() const;

    sf::Vector2f getBoxPosition() const;


    void setPosition(sf::Vector2f pos);

    void setIcon(Image::icons icon);

    sf::Vector2f getTextpos() const;

    std::string getItemText() const;

    void setItemText(std::string text);

    float getThickness() const;

    void setIconScale(Image::icons icon1);

    void centerItem();


private:
    sf::Sprite icon;
    sf::Text itemText;

    sf::RectangleShape itemBox;

};


#endif //DRAWINGMAIN_FILEITEM_H
