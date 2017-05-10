#include "cell.hpp"


Cell::Cell(int x, int y){
    this->x = x;
    this->y = y;
}

int Cell::check_neighbours(Cell* map, const int& w, const int& h){
    int neighbours = 0;

    if(x + 1 > 0 && x + 1 < w)
        if(map[x + 1 + y * w].status == 1) neighbours++;

    if(x - 1 > 0 && x + 1 < w)
        if(map[x - 1 + y * w].status == 1) neighbours++;

    if(y - 1 > 0 && y - 1 < h)
        if(map[x + (y - 1) * w].status == 1) neighbours++;

    if(y + 1 > 0 && y + 1 < h)
        if(map[x + (y + 1) * w].status == 1) neighbours++;

    if(y - 1 > 0 && y - 1 < h && x + 1 > 0 && x + 1 < w)
        if(map[x + 1 + (y - 1) * w].status == 1) neighbours++;

    if(y + 1 > 0 && y + 1 < h && x + 1 > 0 && x + 1 < w)
        if(map[x + 1 + (y + 1) * w].status == 1) neighbours++;

    if(y - 1 > 0 && y - 1 < h && x - 1 > 0 && x - 1 < w)
        if(map[x - 1 + (y - 1) * w].status == 1) neighbours++;

    if(y + 1 > 0 && y + 1 < h && x - 1 > 0 && x - 1 < w)
        if(map[x - 1 + (y + 1) * w].status == 1) neighbours++;

    return neighbours;
}

Cell::~Cell(){}
