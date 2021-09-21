//
// Created by yurychu on 22.09.2021.
//

#include <stdio.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define WIDTH 1024
#define HEIGHT 768


int main(int argc, char* argv[])
{
    const char* glfw_version = glfwGetVersionString();
    puts(glfw_version);

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", NULL, NULL);
    if (!window){
        puts("Fail create window!");
        return -1;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        puts("Failed to initialize OpenGL context");
        return -1;
    }

    glViewport(0, 0, WIDTH, HEIGHT);

    return 0;
}
