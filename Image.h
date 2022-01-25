//
// Created by Celeste Tan on 11/3/21.
//

#ifndef FILETREE_IMAGE_H
#define FILETREE_IMAGE_H

#include "SFML/Graphics.hpp"
#include <map>

static class Image {

public:
    enum icons {
        DIRECTORY, FILE
    };

    static sf::Texture &getImg(icons icon);

    static void loadImg(icons icon);

    static void setPath(icons icon);

private:

    static std::map<icons, sf::Texture> iconMap;
    static std::string path;


};


#endif //FILETREE_IMAGE_H
