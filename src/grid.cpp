#include <raylib.h>
#include "grid.h"

void Grid::Draw() {
    for(size_t i = 0; i < rows; i++) {
        for(size_t j = 0; j < columns; j++) {
            Color color = cells[i][j] ? Color{255, 0, 0, 255} : Color{55, 55, 55, 255};
            DrawRectangle(cell_size * j, cell_size * i, cell_size - 1, cell_size - 1, color);
        }
    }
}

void Grid::Set_cell(size_t row, size_t column, size_t value) {
    if(row >= 0 && row < rows && column >= 0 && column < columns) {
        cells[row][column] = value;
    }
}

size_t Grid::Get_cell(size_t row, size_t column)
{
    if(row >= 0 && row < rows && column >= 0 && column < columns) {
        return cells[row][column];
    }

    return 0;
}

void Grid::Fill() {
    for(size_t i = 0; i < rows; i++) {
        for(size_t j = 0; j < columns; j++) {
            size_t rand = GetRandomValue(0, 4);
            cells[i][j] = (rand == 4) ? 1 : 0;
        }
    }
}
