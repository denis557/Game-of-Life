#include <raylib.h>
#include <stddef.h>
#include <iostream>
#include "behavior.h"

int main() 
{
    const size_t win_width = 1920;
    const size_t win_height = 1080;
    const Color bg_color = {29, 29, 29, 100};
    size_t fps = 12;
    size_t size = 25;

    InitWindow(win_width, win_height, "Game of Life");
    SetTargetFPS(fps);
    Behavior behavior{win_width, win_height, size};
    
    while (!WindowShouldClose())
    {
        if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            Vector2 pos = GetMousePosition();
            size_t row = pos.y / size;
            size_t column = pos.x / size;
            behavior.Toggle_cell_state(row, column);
        }

        if(IsKeyPressed(KEY_SPACE)) {
            behavior.Set_is_running(!behavior.Get_is_running());
        } else if(IsKeyPressedRepeat(KEY_UP)) {
            if(fps < 240) {
                fps++;
                SetTargetFPS(fps);
            }
        } else if(IsKeyPressedRepeat(KEY_DOWN)) {
            if(fps > 3) {
                fps--;
                SetTargetFPS(fps);
            }
        } else if(IsKeyPressed(KEY_F)) {
            behavior.Fill_grid();
        } else if(IsKeyPressed(KEY_C)) {
            behavior.Clear_grid();
        }

        behavior.Update();

        BeginDrawing();
        ClearBackground(bg_color);
        behavior.Draw();
        EndDrawing();
    }
    
    CloseWindow();
}