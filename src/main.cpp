#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <fstream>
#include <filesystem>

#include "Log.h"
#include "Window.h"

std::string loadShaderSrc(const char*);

int main() {
    std::cout << "RudeRacoon @_@\n"; 
    std::cout << "Current working directory: " 
    << std::filesystem::current_path() << "\n";

    RudeRacoon::Window window = RudeRacoon::Window(800, 600, "RudeRacoon");
    window.MakeContextCurrent();

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD\n";
        return -1;
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
# endif

    glViewport(0, 0, 800, 600);
    window.SetFrameBufferSizeCallback();

    Log("Starting engine");

    while(!window.ShouldClose()) {
        glfwPollEvents();
        window.processInput();

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        window.SwapBuffers();   
    }
    return 0;
}

std::string loadShaderSrc(const char* filename) {
    std::ifstream file;
    std::stringstream buf;
    
    std::string ret = "";

    file.open(filename);
    if (file.is_open()) {
        buf << file.rdbuf();
        ret = buf.str();
    } else {
        std::cout << "could not open " << filename << "\n";
    }
    file.close();

    return ret;
}