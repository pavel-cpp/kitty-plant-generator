project(plant_viewer CXX)

find_package(SFML COMPONENTS system window graphics REQUIRED)

add_executable(
    ${PROJECT_NAME}
    main.cpp
    application.cpp
    drawer.cpp
)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
    sfml-window
    sfml-graphics
)