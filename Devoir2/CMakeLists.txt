cmake_minimum_required(VERSION 3.10)
project(MazeTest)

set(CMAKE_CXX_STANDARD 11)

# Ajouter le dossier de Google Test
add_subdirectory(googletest)

# Ajouter les fichiers sources
set(SOURCE_FILES src/node.cpp src/node_test.cpp src/maze.cpp src/maze_test.cpp)

# Créer l'exécutable pour les tests
add_executable(MazeTest ${SOURCE_FILES})

# Ajouter les liens vers les bibliothèques nécessaires
target_link_libraries(MazeTest gtest gtest_main)