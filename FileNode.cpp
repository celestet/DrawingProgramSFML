//
// Created by Celeste Tan on 11/3/21.
//

#include "FileNode.h"

void FileNode::toggleChlidren() {
    if (showChildren) {
        showChildren = false;
    } else {
        showChildren = true;
    }

}

void FileNode::reposition() const {

    float x = data.getTextpos().x;
    float y = data.getBoxPosition().y + data.getBoxSize().y + data.getThickness();

    std::vector<FileNode *>::const_iterator iter;
    iter = childrenVector.begin();

    int space = 0;
    while (iter != childrenVector.end()) {
        (*iter)->getData().setPosition({x, y + space});
        space += (data.getBoxSize().y + data.getThickness());
        ++iter;
    }

}

FileNode::FileNode() {

}

FileNode::FileNode(Image::icons icon, std::string text, sf::Vector2f size, sf::Vector2f position) {

    data.setItemText(text);
    data.setIcon(icon);

}

void FileNode::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    data.addEventHandler(window, event);


    if (MouseEventsFile<FileItem>::mouseClicked1(data, window)) {
        toggleChlidren();
    }
}

void FileNode::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(data);

    std::vector<FileNode *>::const_iterator iter;
    iter = childrenVector.begin();
    if (showChildren) {
        while (iter != childrenVector.end()) {
            reposition();
            (*iter)->draw(window, states);
            ++iter;
        }

    }
}

bool FileNode::isLeaf() const {

    if (childrenVector.size() == 0) {

        return true;
    } else {

        return false;
    }

}

FileItem &FileNode::getData() {
    return this->data;
}

std::vector<FileNode *> &FileNode::getChildrenVec() {

    return childrenVector;
}

void FileNode::setData(const FileItem &data) {
    this->data = data;
}


void FileNode::setDataText(std::string text) {

    data.setItemText(text);
}


void FileNode::update() {

}


sf::FloatRect FileNode::getGlobalBounds() {
//nothing
}


typename FileNode::iterator FileNode::begin() {

}

typename FileNode::iterator FileNode::end() {


}


