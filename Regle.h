

#ifndef L3_LC_F5_LANGUAGE_COMPILATION_REGLE_H
#define L3_LC_F5_LANGUAGE_COMPILATION_REGLE_H

#include <vector>
#include "include.h"

class Regle {
public:
    string Nom;
    vector<vector<string>> token;

    Regle();
    Regle(vector<string> entrer);
    Regle(string nom,vector<string> entrer);
    Regle(string nom,string entrer);
    vector<string> afficher();
    vector<string> get_premier();
    vector<string> get_suivant();
    int recursif();
    vector<string> nn_recursif();
};


#endif //L3_LC_F5_LANGUAGE_COMPILATION_REGLE_H
