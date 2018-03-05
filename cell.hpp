#pragma once

class Cell{

    public:
        int x;
        int y;
        char status;

        Cell(int x, int y);
        ~Cell();

        int check_neighbours(Cell* grid,  int w,  int h);

    private:

};
