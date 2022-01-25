//
// Created by Celeste Tan on 11/3/21.
//

#ifndef DRAWINGMAIN_FILENODE_H
#define DRAWINGMAIN_FILENODE_H

#include "GuiComponent.h"
#include "FileItem.h"
#include "MouseEventsFile.h"
#include <iterator>

class FileNode : public GuiComponent {
private:

    FileNode *root;
    bool showChildren = false;

    FileItem data;

    std::vector<FileNode *> childrenVector;


    void toggleChlidren();


    void reposition() const;

public:
    typedef typename std::map<std::string, FileNode *>::iterator iterator;

    FileNode();

    FileNode(Image::icons icon, std::string text, sf::Vector2f size, sf::Vector2f position);


    virtual void draw(sf::RenderTarget &window, sf::RenderStates states) const;


    virtual void addEventHandler(sf::RenderWindow &window, sf::Event event);

    virtual void update();


    sf::FloatRect getGlobalBounds();

    bool isLeaf() const;

    FileItem &getData();

    void setData(const FileItem &data);

    void setDataText(std::string data);


    std::vector<FileNode *> &getChildrenVec();

    iterator begin();

    iterator end();

};

#endif //DRAWINGMAIN_FILENODE_H
