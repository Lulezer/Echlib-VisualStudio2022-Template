#include "echlib.h"

int main() {
    MakeWindow(600, 600, "Hello World");

    while (!WindowShouldClose()) {
        StartDrawing();

        ClearBackground(BLACK);
        DrawTriangle(0.0f, 0.0f, 1.0f, 1.0f, RED);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
