#pragma once
#include "grid.h"

class Behavior {
    public:
        Behavior(size_t win_width, size_t win_height, size_t cell_size)
        : grid(win_width, win_height, cell_size), temp(win_width, win_height, cell_size), is_running(false) {};

        void Draw();
        void Set_cell(size_t row, size_t column, size_t value);
        size_t Live_neighbors(size_t row, size_t column);
        void Update();
        bool Get_is_running() { return is_running; }
        void Set_is_running(bool is_running) { this->is_running = is_running; };
        void Clear_grid();
        void Fill_grid();
        void Toggle_cell_state(size_t row, size_t column);
    private:
        Grid grid;
        Grid temp;
        bool is_running;
};