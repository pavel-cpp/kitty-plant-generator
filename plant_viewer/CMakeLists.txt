project(plant_viewer CXX)

find_package(SFML COMPONENTS system window graphics REQUIRED)
find_path(TREEHH_INCLUDE_DIRS "treehh/tree.hh")

add_executable(
        ${PROJECT_NAME}
        main.cpp
        application.cpp
        slices/animated_slice.cpp
)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
    sfml-window
    sfml-graphics
)

target_include_directories(
        ${PROJECT_NAME}
        PRIVATE
        ${TREEHH_INCLUDE_DIRS}
        .
)