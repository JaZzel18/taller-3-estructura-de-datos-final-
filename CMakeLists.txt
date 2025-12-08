cmake_minimum_required(VERSION 4.0)
project(untitled2)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled2 main.cpp
        src/Utils/LecturaArchivo.cpp
        src/Include/Utils/LecturaArchivo.h
        src/Utils/Menu.cpp
        src/Include/Utils/Menu.h
        src/Include/Models/Partidas.h
        "src/Include/Models/Personas.h"
        src/Models/Partidas.cpp
        src/Models/Personas.cpp
        src/Include/Models/MinHeap.h
        src/Models/MinHeap.cpp
        src/Include/Models/Avl.h
        src/Models/Avl.cpp
        src/Include/Models/NodoAvl.h
        src/Models/NodoAvl.cpp)
