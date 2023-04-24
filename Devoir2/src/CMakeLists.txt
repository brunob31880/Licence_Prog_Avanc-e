cmake_minimum_required(VERSION 3.10)
project(Maze)

set(CMAKE_CXX_STANDARD 11)


# Ajouter les fichiers sources
set(SOURCE_FILES node.cpp maze.cpp main.cpp)

# Créer l'exécutable pour les tests
add_executable(Maze ${SOURCE_FILES})
