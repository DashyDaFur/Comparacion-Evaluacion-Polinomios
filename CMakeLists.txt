cmake_minimum_required(VERSION 3.12)
project(Evaluacion_Polinomios)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(evaluador
  src/main.cpp
  src/aux.cpp
  src/metodos.cpp
)
)
