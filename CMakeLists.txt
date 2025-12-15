cmake_minimum_required(VERSION 3.10)
project(2048)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

include_directories(include)

add_executable(2048
    src/main.cpp
    src/Game.cpp
    src/Grille.cpp
    src/Affichage.cpp
    src/InputManager.cpp
)

target_link_libraries(2048 sfml-graphics sfml-window sfml-system)