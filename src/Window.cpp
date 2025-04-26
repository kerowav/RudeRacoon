#include <iostream>
#include <GLFW/glfw3.h>

#include "Window.h"
#include "Log.h"

void framebuffer_size_callback(GLFWwindow*, int, int);

namespace RudeRacoon {
  static size_t windowCount = 0;

  Window::Window(int width, int height, const char* title) {
    if(windowCount == 0) {
      glfwSetErrorCallback([](int error_code, const char* description) {
        std::cout << "Glfw error: " << error_code << "\n" << description << "\n"; 
      });

      if (!glfwInit()) {
        std::cout << "failed to initialze glfw\n";
      }
    }
    ++windowCount;
    mWindow = glfwCreateWindow(width, height, title , nullptr, nullptr);

    if(!mWindow) {
      std::cout << "Failed to create window.\n";
    }

  }

  Window::~Window() {
    if (mWindow) glfwDestroyWindow(mWindow);
    mWindow = nullptr;

    --windowCount;
    if (windowCount == 0) {
      glfwTerminate();
      glfwSetErrorCallback(nullptr);
    }
  }

  Window::Window(Window&& other) noexcept {
    Window::operator=(std::move(other));
  }

  Window& Window::operator = (Window&& other) noexcept {
    Window::~Window();
    mWindow = other.mWindow;
    other.mWindow = nullptr;
    return *this;
  }

  void Window::processInput() {
    if(glfwGetKey(mWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(mWindow, true);
  } 
  
  void Window::SetFrameBufferSizeCallback() {
    glfwSetFramebufferSizeCallback(mWindow, framebuffer_size_callback);
  }
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
  glViewport(0, 0, width, height);
}