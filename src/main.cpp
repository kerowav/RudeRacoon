#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <fstream>
#include <filesystem>

#include "Log.h"
#include "Window.h"
#include "Application.h"

std::string loadShaderSrc(const char*);

class Engine : public RudeRacoon::Application {
public:
    Engine() = default;
    virtual ~Engine() = default;

    virtual void Init() override {
        std::cout << "RudeRacoon @_@\n";
        mWindow = RudeRacoon::Window(800, 600, "RudeRacoon", [](){
            glfwWindowHint(GLFW_SAMPLES, 4);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        #ifdef __APPLE__
            glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        # endif
        });
        
        if(!mWindow.GetWindow()) {
            std::cout << "Failed to load OpenGL.\n";
            Stop();
            return;
          }
    
        mWindow.MakeContextCurrent();
    
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            std::cout << "Failed to initialize GLAD\n";
            Stop();
            return;
        }
    
        glViewport(0, 0, 800, 600);
        mWindow.SetFrameBufferSizeCallback();
    }

    virtual void Update() override {
        glfwPollEvents();
        mWindow.processInput();

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        mWindow.SwapBuffers();

        if(mWindow.ShouldClose()) Stop();
    }

    virtual void Destroy() override {

    }

private:
    RudeRacoon::Window mWindow;
};

int main() {
    Engine engine;
    engine.Start();
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