project(plant_random_generator CXX)

find_path(TREEHH_INCLUDE_DIRS "treehh/tree.hh")

add_executable(
        ${PROJECT_NAME}
        main.cpp
)

target_include_directories(
        ${PROJECT_NAME}
        PRIVATE
        ${TREEHH_INCLUDE_DIRS}
)