cmake_minimum_required(VERSION 3.17)
project(DrawingMain)

set(CMAKE_CXX_STANDARD 14)

add_executable(DrawingMain main.cpp DropDownMenu.cpp DropDownMenu.h EventHandler.h Font.h Font.cpp GuiComponent.h InputBox.h InputBox.cpp Item.h Item.cpp ItemList.h ItemList.cpp MouseEvents.cpp MouseEvents.h States.cpp States.h MenuBar.cpp MenuBar.h
        DrawingSpace.cpp DrawingSpace.h FileItem.cpp FileItem.h FileNode.cpp FileNode.h FileTree.h FileTree.cpp Image.h Image.cpp
        ObjectStates.h Typing.h Typing.cpp FileWindow.cpp FileWindow.h MouseEventsFile.cpp MouseEventsFile.h)


target_link_libraries(DrawingMain sfml-graphics sfml-audio)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)