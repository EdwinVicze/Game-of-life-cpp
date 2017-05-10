#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "cell.hpp"

class Window{


    public:
        Cell* grid;
        Cell* copyGrid;
        sf::RenderWindow* window;
        Window(int width, int height, const std::string& title);
        void run();
        void update();
        void render();
        ~Window();



};
