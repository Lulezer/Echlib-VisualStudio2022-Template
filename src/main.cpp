#include "echlib.h"

int main() {
    MakeWindow(1920, 1080, "Hello World");

    while (!WindowShouldClose()) {
        StartDrawing();

        ClearBackground(BLACK);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
