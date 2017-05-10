#include "window.hpp"

#include <iostream>

int rw = 20;
int rh = 20;
int w = 256;
int h = 256;

sf::RectangleShape rect(sf::Vector2f(rw, rh));

Window::Window(int width, int height, const std::string& title){
    rect.setOutlineColor(sf::Color(0, 0, 0));
    rect.setOutlineThickness(1);
    this->window = new sf::RenderWindow(sf::VideoMode(width, height), title);
    this->window->setFramerateLimit(60);
    this->grid = (Cell*)malloc(sizeof(Cell) * w * h);
    this->copyGrid = (Cell*)malloc(sizeof(Cell) * w * h);

    for(int y = 0; y < h; y++){
        for(int x = 0; x < w; x++){
            grid[x + y * w] = Cell(x, y);
            grid[x + y * w].status = 0;
            copyGrid[x + y * w] = Cell(x, y);
            copyGrid[x + y * w].status = 0;
        }
    }
}

void Window::run(){
    while(this->window->isOpen()){
        sf::Event event;
        while(this->window->pollEvent(event)){
            if(event.type == sf::Event::Closed) this->window->close();
        }
        update();
        render();
    }
}

bool canStart = false;

void Window::update(){
    int x = sf::Mouse::getPosition(*window).x / rw;
    int y = sf::Mouse::getPosition(*window).y / rh;
    if(x > 0 && x < w && y > 0 && y < h){
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            grid[x + y * w].status = 1;
        }
    }

    if(canStart){
        for(int i = 0; i < w << 8; i++){
            if(grid[i].status == 1 && grid[i].check_neighbours(grid, w, h) < 2)
                copyGrid[i].status = 0;
            if(grid[i].status == 1 && (grid[i].check_neighbours(grid, w, h) == 2 || grid[i].check_neighbours(grid, w, h) == 3))
                copyGrid[i].status = 1;
            if(grid[i].status == 1 && grid[i].check_neighbours(grid, w, h) > 3)
                copyGrid[i].status = 0;
            if(grid[i].status == 0 && grid[i].check_neighbours(grid, w, h) == 3)
                copyGrid[i].status = 1;
        }
        for(int i = 0; i < w << 8; i++) grid[i] = copyGrid[i];
    }
    if(sf::Mouse::isButtonPressed(sf::Mouse::Right)) canStart = true;
}


void Window::render(){
    this->window->clear();

    for(int y = 0; y < h; y++){
        for(int x = 0; x < w; x++){
            if(grid[x + y * w].status == 0){
                rect.setFillColor(sf::Color(255, 255, 255));
                rect.setPosition(sf::Vector2f(x * rw + 1, y * rh + 1));
            } else if(grid[x + y * w].status == 1){
                rect.setFillColor(sf::Color(0, 0, 0));
                rect.setPosition(sf::Vector2f(x * rw + 1, y * rh + 1));
            }
            this->window->draw(rect);
        }
    }


    this->window->display();
}

Window::~Window(){}
