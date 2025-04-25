cmake_minimum_required(VERSION 3.26.0)
project(RudeRacoon VERSION 1.0.0)
# cmake_policy(SET CMP0072 NEW)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
find_package(OpenGL REQUIRED)
find_package(GLFW3 REQUIRED)

add_executable(RudeRacoon src/main.cpp src/glad.c)

target_include_directories(RudeRacoon PRIVATE dependencies)

target_link_libraries(RudeRacoon GLFW3 OpenGL::GL)