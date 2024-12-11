#include <iostream>
#include <SFML/Graphics.hpp>
#include "GUIManager.h"

int main() {
    // Create an SFML window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Data Structure Visualization");

    // Load font for displaying text
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Error loading font\n";
        return -1;
    }

    // Initialize the GUI Manager
    GUIManager guiManager(window, font);

    // Run the main application loop
    guiManager.run();

    return 0;
}

