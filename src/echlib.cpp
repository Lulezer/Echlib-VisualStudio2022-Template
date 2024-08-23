#include "echlib.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

static GLFWwindow* window = nullptr;

void MakeWindow(int width, int height, const char* title) {
    if (!glfwInit()) {
        return;
    }

    window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!window) {
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(window);

    // Initialize GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        glfwDestroyWindow(window);
        glfwTerminate();
        return;
    }
}

void CloseWindow() {
    if (window) {
        glfwDestroyWindow(window);
        window = nullptr;
    }
    glfwTerminate();
}

int WindowShouldClose() {
    return glfwWindowShouldClose(window);
}

void StartDrawing() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void EndDrawing() {
    glfwSwapBuffers(window);
    glfwPollEvents();
}

void ClearBackground(float r, float g, float b, float a) {
    glClearColor(r, g, b, a);
}
