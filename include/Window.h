#pragma once
#include <utility>
#include <GLFW/glfw3.h>

namespace RudeRacoon {
  class Window final {
  public:
    Window() = default;
    Window(int width, int height, const char* title);
    ~Window();
    Window(const Window&) = delete;
    Window& operator = (const Window&) = delete;
    Window(Window&& other) noexcept;
    Window& operator = (Window&& other) noexcept;
    void processInput();
    void SetFrameBufferSizeCallback();

    inline GLFWwindow* GetWindow() const {
      return mWindow;
    }

    inline void MakeContextCurrent() const {
      glfwMakeContextCurrent(mWindow);
    }

    inline void SwapBuffers() {
      glfwSwapBuffers(mWindow);
    }

    inline bool ShouldClose() const {
      return glfwWindowShouldClose(mWindow);
    }

    inline std::pair<int, int> GetSize() {
      int w, h;
      glfwGetFramebufferSize(mWindow, &w, &h);
      return {w, h};
    }

  private:
    GLFWwindow* mWindow = nullptr;

  };
}
