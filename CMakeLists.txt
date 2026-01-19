cmake_minimum_required(VERSION 3.10)
project(2048)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Chemin vers SDL2 (modifie si besoin)
set(SDL2_PATH "C:/libs/SDL2-2.32.10/x86_64-w64-mingw32")

# Includes et libs SDL2
include_directories(${SDL2_PATH}/include)
include_directories(include)
link_directories(
    ${SDL2_PATH}/lib
    C:/msys64/mingw64/lib
)

# COPIE DU DOSSIER assets DANS LE DOSSIER build
file(COPY ${CMAKE_SOURCE_DIR}/assets DESTINATION ${CMAKE_BINARY_DIR})

# EXECUTABLE PRINCIPAL
add_executable(2048
    src/main.cpp
    src/Game.cpp
    src/Grid.cpp
    src/Display.cpp
    src/InputManager.cpp
)

target_link_libraries(2048
    mingw32
    SDL2main
    SDL2
    SDL2_ttf
    SDL2_gfx
)


# ============================================
# TESTS UNITAIRES (commentés pour l'instant)
# ============================================
# enable_testing()

# # Test Grille (pas besoin de SDL2)
# add_executable(test_grille
#     tests/test_grid.cpp
#     src/Grid.cpp
# )

# # Test Affichage (besoin de SDL2)
# add_executable(test_affichage
#     tests/test_Display.cpp
#     src/Display.cpp
# )

# target_link_libraries(test_affichage
#     mingw32
#     SDL2main
#     SDL2
# )

# # Test InputManager (besoin de SDL2)
# add_executable(test_input
#     tests/test_input.cpp
#     src/InputManager.cpp
# )

# target_link_libraries(test_input
#     mingw32
#     SDL2main
#     SDL2
# )

# # Test Game (besoin de tout)
# add_executable(test_game
#     tests/test_game.cpp
#     src/Game.cpp
#     src/Grid.cpp
#     src/Display.cpp
#     src/InputManager.cpp
# )

# target_link_libraries(test_game
#     mingw32
#     SDL2main
#     SDL2
# )

# # Ajouter les tests à CTest
# add_test(NAME TestGrille COMMAND test_grille)
# add_test(NAME TestAffichage COMMAND test_affichage)
# add_test(NAME TestInput COMMAND test_input)
# add_test(NAME TestGame COMMAND test_game)