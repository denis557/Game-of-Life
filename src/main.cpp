#include <raylib.h>
#include <stddef.h>
#include <iostream>
#include "behavior.h"

int main() 
{
    const size_t win_width = 1920;
    const size_t win_height = 1080;
    const Color bg_color = {29, 29, 29, 100};

    InitWindow(win_width, win_height, "Game of Life");
    SetTargetFPS(12);
    Behavior behavior{win_width, win_height, 25};
    
    while (!WindowShouldClose())
    {
        if(IsKeyPressed(KEY_SPACE)) {
            behavior.Set_is_running(!behavior.Get_is_running());
        }

        behavior.Update();

        BeginDrawing();
        ClearBackground(bg_color);
        behavior.Draw();
        EndDrawing();
    }
    
    CloseWindow();
}