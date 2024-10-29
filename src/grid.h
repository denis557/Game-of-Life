#pragma once
#include <vector>
#include <stddef.h>

using namespace std;

class Grid
{
    public:
        Grid(size_t win_width, size_t win_height, size_t cell_size)
        : rows(win_height/cell_size), columns(win_width/cell_size), cell_size(cell_size), cells(rows, vector<size_t>(columns, 0)) {};
        void Draw();
        size_t Get_rows() {return rows;}
        size_t Get_columns() {return columns;}
        void Set_cell(size_t row, size_t column, size_t value);
        size_t Get_cell(size_t row, size_t column);
        void Fill();
        void Clear();
        void Toggle_cell_state(size_t row, size_t column);
    private:
        size_t rows;
        size_t columns;
        size_t cell_size;
        vector<vector<size_t>> cells;
};