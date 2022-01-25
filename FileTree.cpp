//
// Created by Celeste Tan on 11/3/21.
//

#include "FileTree.h"
#include <iostream>


void FileTree::push(FileNode *&root, std::string parent, std::string item) {

    if (root == nullptr) {

        root = new FileNode;

        root->setDataText(parent);
        root->getData().setIcon(Image::icons::DIRECTORY);

        FileNode *child = new FileNode;
        root->getChildrenVec().push_back(child);
        return;
    }


    if (root->getData().getItemText() == parent) {

        FileNode *child = new FileNode;

        child->setDataText(item);


        if ((child)->isLeaf()) {

            child->getData().setIcon(Image::icons::FILE);
            child->getData().setIconScale(Image::FILE);

        } else {

            (child)->getData().setIcon(Image::icons::DIRECTORY);
            child->getData().setIconScale(Image::DIRECTORY);


        }


        root->getChildrenVec().push_back(child);
        return;
    }


    std::vector<FileNode *>::iterator iter;
    iter = root->getChildrenVec().begin();
    while (iter != root->getChildrenVec().end()) {
        push(*iter, parent, item);

        if ((*iter)->isLeaf()) {

            (*iter)->getData().setIcon(Image::icons::FILE);
            (*iter)->getData().setIconScale(Image::icons::FILE);


        } else {

            (*iter)->getData().setIcon(Image::icons::DIRECTORY);
            (*iter)->getData().setIconScale(Image::icons::DIRECTORY);


        }

        ++iter;
    }


}

void FileTree::traverse(FileNode *&root, sf::RenderWindow &window, sf::Event event) {

    if (root == nullptr) {

        return;
    }


    std::vector<FileNode *>::iterator iter;
    iter = root->getChildrenVec().begin();

    root->addEventHandler(window, event);


    while (iter != root->getChildrenVec().end()) {
        traverse(*iter, window, event);
        ++iter;
    }

}

FileTree::FileTree() {

}

void FileTree::push1(std::string parent, std::string item) {

    push(root, parent, item);

}

void FileTree::draw(sf::RenderTarget &window, sf::RenderStates states) const {

    window.draw(*root);
}


void FileTree::addEventHandler(sf::RenderWindow &window, sf::Event event) {

    traverse(root, window, event);


    std::vector<FileNode *>::const_iterator iter = root->getChildrenVec().begin();
    while (iter != root->getChildrenVec().end()) {
        ++iter;
    }
}

void FileTree::update() {
//nothing
}


sf::FloatRect FileTree::getGlobalBounds() {
//nothing
}
