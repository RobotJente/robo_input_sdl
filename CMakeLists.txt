cmake_minimum_required(VERSION 3.14)
project(robo_input_sdl)

set(CMAKE_CXX_STANDARD 14)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")


INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})
add_executable(robo_input_sdl main.cpp)
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARIES})
