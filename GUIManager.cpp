#ifndef GUIMANAGER_H
#define GUIMANAGER_H

#include <SFML/Graphics.hpp>
#include "Heap.h"
#include "BST.h"
#include "AVL.h"
#include "PriorityQueue.h"
#include "StackQueue.h"

class GUIManager {
public:
    GUIManager(sf::RenderWindow& window, sf::Font& font);
    void run();

private:
    sf::RenderWindow& window;
    sf::Font& font;

    void handleEvents();
    void render();
    void update();

    void visualizeHeap();
    void visualizeBST();
    void visualizeAVL();
};

#endif

