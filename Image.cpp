//
// Created by Celeste Tan on 11/3/21.
//

#include "Image.h"
#include <iostream>


std::map<Image::icons, sf::Texture> Image::iconMap;
std::string Image::path;


sf::Texture &Image::getImg(Image::icons icon) {
    loadImg(icon);
    return iconMap[icon];
}

void Image::loadImg(Image::icons icon) {
    setPath(icon);
    iconMap[icon].loadFromFile(path);
    if (!iconMap[icon].loadFromFile(path)) {
        std::cout << "Fail to load " << icon << std::endl;
    }
}

void Image::setPath(Image::icons icon) {
    if (icon == Image::FILE) {
        path = "fileimg.png";
    } else if (icon == Image::DIRECTORY) {
        path = "Directimg.png";
    }
}
