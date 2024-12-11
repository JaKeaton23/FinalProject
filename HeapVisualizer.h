#ifndef HEAPVISUALIZER_H
#define HEAPVISUALIZER_H

#include <SFML/Graphics.hpp>
#include "Heap.h"

class HeapVisualizer {
public:
    HeapVisualizer(sf::RenderWindow& window, sf::Font& font, const Heap& heap);
    void draw();

private:
    sf::RenderWindow& window;
    sf::Font& font;
    const Heap& heap;

    void drawNode(int value, int x, int y);
    void drawEdge(int x1, int y1, int x2, int y2);
};

#endif

