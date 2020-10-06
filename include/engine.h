#pragma once

#include "Log.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int Initialise();
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);
int AppInit();
