//
// Created by Celeste Tan on 11/30/21.
//

#include "FileWindow.h"


void FileWindow::run() {

    sf::RenderWindow window(sf::VideoMode(2500, 1200), "FileTree");


    tree.push1(" ", " ");
    tree.push1(" ", " ");
    tree.push1(" ", " ");
    tree.push1(" ", " ");
    tree.push1(" ", " ");
    tree.push1(" ", " ");
    tree.push1(" ", " ");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            tree.addEventHandler(window, event);
        }

        window.clear(sf::Color::White);
        window.draw(tree);
        window.display();
    }


}

void FileWindow::save() {
    tree.push1("File", "myDrawing");
}
