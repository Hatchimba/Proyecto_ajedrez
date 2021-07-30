cmake_minimum_required(VERSION 3.17.5)
project(Proyecto_ajedrez)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Proyecto_ajedrez
        Alfiles.h
        Caballos.h
        main.cpp
        Peones.h
        Piezas.h
        Reinas.h
        Reyes.h
        Tablero.cpp
        Tablero.h
        Torres.h)
