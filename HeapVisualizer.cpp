//
// Created by Jayden Keaton on 12/10/24.
//
#include "HeapVisualizer.h"

HeapVisualizer::HeapVisualizer(sf::RenderWindow& window, sf::Font& font, const Heap& heap)
    : window(window), font(font), heap(heap) {}

void HeapVisualizer::draw() {
    const std::vector<int>& data = heap.getHeap();
    int x = 400, y = 50; // Start at the top center
    int xOffset = 200;

    for (size_t i = 0; i < data.size(); ++i) {
        drawNode(data[i], x, y);

        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;

        if (leftChild < data.size())
            drawEdge(x, y, x - xOffset, y + 100);
        if (rightChild < data.size())
            drawEdge(x, y, x + xOffset, y + 100);

        xOffset /= 2;
    }
}

void HeapVisualizer::drawNode(int value, int x, int y) {
    sf::CircleShape node(20);
    node.setFillColor(sf::Color::Blue);
    node.setPosition(x - 20, y - 20);
    window.draw(node);

    sf::Text text;
    text.setFont(font);
    text.setString(std::to_string(value));
    text.setCharacterSize(15);
    text.setFillColor(sf::Color::White);
    text.setPosition(x - 10, y - 15);
    window.draw(text);
}

void HeapVisualizer::drawEdge(int x1, int y1, int x2, int y2) {
    sf::Vertex line[] = {
        sf::Vertex(sf::Vector2f(x1, y1), sf::Color::White),
        sf::Vertex(sf::Vector2f(x2, y2), sf::Color::White)
    };
    window.draw(line, 2, sf::Lines);
}
