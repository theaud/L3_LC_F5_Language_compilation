cmake_minimum_required(VERSION 3.3)
project(L3_LC_F5_Language_compilation)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES L3_LC_F5_main.cpp L3_LC_F5_Grammaire.cpp L3_LC_F5_Grammaire.h L3_LC_F5_Regle.cpp L3_LC_F5_Regle.h L3_LC_F5_Structure.cpp L3_LC_F5_Structure.h L3_LC_F5_Entrer.cpp L3_LC_F5_Entrer.h L3_LC_F5_Utilitaire.cpp L3_LC_F5_Utilitaire.h L3_LC_F5_premier_suivant.cpp L3_LC_F5_premier_suivant.h L3_LC_F5_include.h)
add_executable(L3_LC_F5_Language_compilation ${SOURCE_FILES})