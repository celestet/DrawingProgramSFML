//
// Created by Celeste Tan on 11/30/21.
//

#ifndef DRAWINGMAIN_FILEWINDOW_H
#define DRAWINGMAIN_FILEWINDOW_H


#include <iostream>
#include "SFML/Graphics.hpp"
#include "FileTree.h"

class FileWindow {
private:
    FileTree tree;
public:
    void run();

    void save();
};


#endif //DRAWINGMAIN_FILEWINDOW_H
