

#ifndef L3_LC_F5_LANGUAGE_COMPILATION_STRUCTURE_H
#define L3_LC_F5_LANGUAGE_COMPILATION_STRUCTURE_H
#include <iostream>
#include <vector>

using namespace std;

#include "Grammaire.h"

class Structure {
public:

    Grammaire Grammaire_brute;
    Grammaire Gramairre_derecurssiver;
    vector<string> premier;
    vector<string> suivant;

    Structure();



};


#endif //L3_LC_F5_LANGUAGE_COMPILATION_STRUCTURE_H
