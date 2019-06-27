# cmake_minimum_required(VERSION <specify CMake version here>)
project(trabalho_tp1)

set(CMAKE_CXX_STANDARD 14)

add_executable(trabalho_tp1 main.cpp dominios.h dominios.cpp entidades.h entidades.cpp interfaces.h interfaceUsuario.cpp controladores.h controladores.cpp)
