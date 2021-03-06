

#ifndef L3_LC_F5_LANGUAGE_COMPILATION_REGLE_H
#define L3_LC_F5_LANGUAGE_COMPILATION_REGLE_H

#include "L3_LC_F5_include.h"


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

    int recursif();
    vector<string> nn_recursif();
    vector<string> getRegle(string valeur_initiale);

};


#endif //L3_LC_F5_LANGUAGE_COMPILATION_REGLE_H
