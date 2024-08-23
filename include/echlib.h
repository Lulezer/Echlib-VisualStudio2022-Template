#ifndef ECHLIB_H
#define ECHLIB_H

#ifdef __cplusplus
extern "C" {
#endif

// Colors
#define RED 1.0f, 0.0f, 0.0f, 1.0f        // Red
#define GREEN 0.0f, 1.0f, 0.0f, 1.0f      // Green
#define BLUE 0.0f, 0.0f, 1.0f, 1.0f       // Blue
#define WHITE 1.0f, 1.0f, 1.0f, 1.0f       // White
#define BLACK 0.0f, 0.0f, 0.0f, 1.0f       // Black
#define GRAY 0.5f, 0.5f, 0.5f, 1.0f        // Gray (0.5, 0.5, 0.5 = 128/255)
#define YELLOW 1.0f, 1.0f, 0.0f, 1.0f      // Yellow
#define CYAN 0.0f, 1.0f, 1.0f, 1.0f        // Cyan
#define MAGENTA 1.0f, 0.0f, 1.0f, 1.0f     // Magenta
#define ORANGE 1.0f, 0.647f, 0.0f, 1.0f    // Orange (255/255, 165/255)
#define PURPLE 0.5f, 0.0f, 0.5f, 1.0f      // Purple (128/255)
#define PINK 1.0f, 0.75f, 0.796f, 1.0f     // Pink (255/255, 192/255, 203/255)
#define BROWN 0.545f, 0.298f, 0.149f, 1.0f  // Brown (139/255, 69/255, 19/255)
#define LIGHT_BLUE 0.678f, 0.847f, 0.902f, 1.0f  // Light Blue (173/255, 216/255, 230/255)
#define BEIGE 0.827f, 0.690f, 0.514f, 1.0f    // Beige (211/255, 176/255, 131/255)
#define LIGHT_GREEN 0.565f, 0.933f, 0.565f, 1.0f  // Light Green (144/255, 238/255, 144/255)
#define DARK_GREEN 0.0f, 0.459f, 0.173f, 1.0f     // Dark Green (0/255, 117/255, 44/255)
#define LIGHT_CORAL 0.941f, 0.502f, 0.502f, 1.0f   // Light Coral (240/255, 128/255, 128/255)

	void MakeWindow(int width, int height, const char* title);
	void CloseWindow();
	int WindowShouldClose();
	void StartDrawing();
	void EndDrawing();
	void ClearBackground(float r, float g, float b, float a);
	void DrawTriangle(float x, float y, float width, float height, float r, float g, float b, float a);

#ifdef __cplusplus
}
#endif

#endif // ECHLIB_H
