#include <utility>
#include <vector>
#include "behavior.h"

using namespace std;

void Behavior::Draw() {
    grid.Draw();
}

void Behavior::Set_cell(size_t row, size_t column, size_t value) {
    grid.Set_cell(row, column, value);
}

size_t Behavior::Live_neighbors(size_t row, size_t column) {
    size_t live_neighbors = 0;

    vector<pair<ssize_t, ssize_t>> neighbors_pos = {
        {-1, 0}, 
        {1, 0}, 
        {0, -1}, 
        {0, 1},
        {-1, -1},
        {-1, 1}, 
        {1, -1}, 
        {1, 1}
    };
    
    for(const auto &pos : neighbors_pos) {
        size_t neighbor_row = (row + pos.first + grid.Get_rows()) % grid.Get_rows();
        size_t neighbor_column = (column + pos.second + grid.Get_columns()) % grid.Get_columns();
        live_neighbors += grid.Get_cell(neighbor_row, neighbor_column);
    }

    return live_neighbors;
}

void Behavior::Update() {
    if(is_running) {
        for(size_t i = 0; i < grid.Get_rows(); i++) {
            for(size_t j = 0; j < grid.Get_columns(); j++) {
                size_t live_neighbors = Live_neighbors(i, j);
                size_t value = grid.Get_cell(i, j);

                if(value == 1) {
                    if(live_neighbors > 3 || live_neighbors < 2) {
                        temp.Set_cell(i, j, 0);
                    } else {
                        temp.Set_cell(i, j, 1);
                    }
                } else {
                    if(live_neighbors == 3) {
                        temp.Set_cell(i, j, 1);
                    } else {
                        temp.Set_cell(i, j, 0);
                    }
                }
            }
        }

        grid = temp;
    }
}

void Behavior::Clear_grid() {
    if(!is_running) {
        grid.Clear();
    }
}

void Behavior::Fill_grid() {
    if(!is_running) {
        grid.Fill();
    }
}

void Behavior::Toggle_cell_state(size_t row, size_t column) {
    if(!is_running) {
        grid.Toggle_cell_state(row, column);
    }
}