cmake_minimum_required(VERSION 3.19)
project(Proyecto_ajedrez)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Proyecto_ajedrez
        Alfiles.cpp
        Alfiles.h
        Caballos.cpp
        Caballos.h
        main.cpp
        Peones.cpp
        Peones.h
        Piezas.h
        Reinas.cpp
        Reinas.h
        Reyes.cpp
        Reyes.h
        Tablero.cpp
        Tablero.h
        tempCodeRunnerFile.cpp
        Torres.cpp
        Torres.h)
