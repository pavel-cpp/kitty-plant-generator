cmake_minimum_required(VERSION 3.23)
project(kitty_plant CXX)

set(CMAKE_CXX_STANDARD 23)

include_directories(common)

add_subdirectory(plant_viewer)
add_subdirectory(random_generator)
