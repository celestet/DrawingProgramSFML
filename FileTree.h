//
// Created by Celeste Tan on 11/3/21.
//

#ifndef DRAWINGMAIN_FILETREE_H
#define DRAWINGMAIN_FILETREE_H

#include "GuiComponent.h"
#include "FileNode.h"


class FileTree : public GuiComponent {
private:
    FileNode *root = nullptr;


    void push(FileNode *&root, std::string parent, std::string item);


    void traverse(FileNode *&root, sf::RenderWindow &window, sf::Event event);

public:
    FileTree();

    void push1(std::string parent, std::string item = "NULL");

    virtual void draw(sf::RenderTarget &window, sf::RenderStates states) const;


    virtual void addEventHandler(sf::RenderWindow &window, sf::Event event);

    virtual void update();


    virtual sf::FloatRect getGlobalBounds();
};


#endif //DRAWINGMAIN_FILETREE_H
