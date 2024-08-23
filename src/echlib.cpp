#include "echlib.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

static GLFWwindow* window = nullptr;
static GLuint shaderProgram;
static GLuint vao, vbo;

static const char* vertexShaderSource = R"(
#version 330 core
layout(location = 0) in vec2 aPos;

void main() {
    gl_Position = vec4(aPos, 0.0, 1.0);
}
)";

static const char* fragmentShaderSource = R"(
#version 330 core
out vec4 FragColor;

uniform vec4 uColor;

void main() {
    FragColor = uColor;
}
)";

static void CompileShader() {
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

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

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        glfwDestroyWindow(window);
        glfwTerminate();
        return;
    }

    CompileShader();

    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
}

void CloseWindow() {
    if (window) {
        glfwDestroyWindow(window);
        window = nullptr;
    }
    glDeleteProgram(shaderProgram);
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
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

void DrawTriangle(float x, float y, float width, float height, float r, float g, float b, float a) {
    float vertices[] = {
        x, y,
        x + width, y,
        x + width / 2, y + height
    };

    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glUseProgram(shaderProgram);
    glUniform4f(glGetUniformLocation(shaderProgram, "uColor"), r, g, b, a);

    glDrawArrays(GL_TRIANGLES, 0, 3);

    glBindVertexArray(0);
}
