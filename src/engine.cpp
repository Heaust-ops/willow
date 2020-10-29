#include "engine.h"
#include "Math.h"


#include <iostream>
#include <sstream>

// Defining Shape

Vector2 A1 = Vector2(0.5f,  0.5f);
Vector2 A2 = Vector2(0.5f, -0.5f);
Vector2 A3 = Vector2(-0.5f, -0.5f);

Vector2 B1 = Vector2(0.5f,  0.5f);
Vector2 B2 = Vector2(-0.5f, -0.5f);
Vector2 B3 = Vector2(-0.5f,  0.5f);

float vertices[] = {
    // first triangle
    A1.x, A1.y, 0.0f,  // left 
    A2.x, A2.y, 0.0f,  // right
    A3.x, A3.y, 0.0f,  // top 
    // second triangle
    B1.x, B1.y, 0.0f,  // left 
    B2.x, B2.y, 0.0f,  // right
    B3.x, B3.y, 0.0f,  // top 
}; 

// Make Shader Sources

std::string vertexShader = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\n";
std::string fragmentShaderBlue = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(0.2f, 0.6f, 1.0f, 1.0f);\n"
    "}\n";

std::string fragmentShaderRed = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.3f, 0.3f, 1.0f);\n"
    "}\n";

std::string fragmentShaderGreen = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(0.2f, 0.9f, 0.5f, 1.0f);\n"
    "}\n";

static unsigned int CompileShader(unsigned int type, const std::string& source)
{
    unsigned int id = glCreateShader(type);
    const char* src = source.c_str();
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    // Error handling
    int success;
    char infoLog[512];
    glGetShaderiv(id, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(id, 512, NULL, infoLog);
        WI_CORE_ERROR("ERROR::SHADER::VERTEX::COMPILATION_FAILED");
        WI_CORE_INFO(infoLog);
        glDeleteShader(id);
        return 0;
    }

    return id;
}

static unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
{
    unsigned int program = glCreateProgram();
    unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);

    // Error handling
    int success;
    char infoLog[512];
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(program, 512, NULL, infoLog);
        WI_CORE_ERROR("ERROR::SHADER::PROGRAM::LINKING_FAILED");
        WI_CORE_INFO(infoLog);
    }

    glDeleteShader(vs);
    glDeleteShader(fs);

    return program;

}

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    
    if(glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS)
    {
        unsigned int shader = CreateShader(vertexShader, fragmentShaderBlue);
        glUseProgram(shader);
    }

    if(glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS)
    {
        unsigned int shader = CreateShader(vertexShader, fragmentShaderRed);
        glUseProgram(shader);
    }

    if(glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS)
        {
            unsigned int shader = CreateShader(vertexShader, fragmentShaderGreen);
            glUseProgram(shader);
        }
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

int AppInit()
{
    WI_INFO("Initializing GLFW");
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    WI_INFO("Creating Window");
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Renderer Engine", NULL, NULL);
    if (window == NULL)
    {
        WI_ERROR("Failed to create GLFW window");
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    WI_INFO("Loading OpenGL Functions Pointers");
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        WI_ERROR("Failed to initialize GLAD");
        return -1;
    }    










    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0); 

    glBindVertexArray(0); 





unsigned int shader = CreateShader(vertexShader, fragmentShaderBlue);
glUseProgram(shader);







    WI_INFO("Creating Render Loop");
    while (!glfwWindowShouldClose(window))
    {
        // input
        processInput(window);

        // render work
        glClear(GL_COLOR_BUFFER_BIT);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 6);

        // check and call events and swap the buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    WI_INFO("Clearing all allocated resources");
    glfwTerminate();
    return 0;
}

int Initialise() {
    std::cout << "ENGINE INIT" << std::endl;
    return 0;
}