cmake_minimum_required(VERSION 3.26.0)
project(RudeRacoon VERSION 1.0.0)
# cmake_policy(SET CMP0072 NEW)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
find_package(OpenGL REQUIRED)
find_package(GLFW3 REQUIRED)

add_library(Includes STATIC src/Log.cpp src/Window.cpp)
target_include_directories(Includes PRIVATE include)

add_executable(RudeRacoon src/main.cpp lib/glad.c lib/stb.cpp src/Window.cpp src/Application.cpp)

target_include_directories(RudeRacoon PUBLIC dependencies include)

target_link_libraries(RudeRacoon GLFW3 OpenGL::GL Includes)