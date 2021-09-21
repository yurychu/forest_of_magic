//
// Created by yurychu on 22.09.2021.
//

#include <stdio.h>

#include <GLFW/glfw3.h>


int main(int argc, char* argv[])
{
    const char* glfw_version = glfwGetVersionString();
    puts(glfw_version);

    return 0;
}
