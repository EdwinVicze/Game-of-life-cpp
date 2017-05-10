#pragma once

class Cell{

    public:
        int x;
        int y;
        char status;

        Cell(int x, int y);
        int check_neighbours(Cell* grid, const int& w, const int& h);
        ~Cell();

    private:

};
