cmake_minimum_required(VERSION 3.3)
project(L3_LC_F5_Language_compilation)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Grammaire.cpp Grammaire.h Regle.cpp Regle.h Structure.cpp Structure.h Entrer.cpp Entrer.h Utilitaire.cpp Utilitaire.h include.h Camille.cpp Camille.h)
add_executable(L3_LC_F5_Language_compilation ${SOURCE_FILES})