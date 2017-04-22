#ifndef L3_LC_F5_LANGUAGE_COMPILATION_PREMIER_SUIVANT_H
#define L3_LC_F5_LANGUAGE_COMPILATION_PREMIER_SUIVANT_H

#include "include.h"

class premier_suivant {

public:
    string Nom;
    vector<string> Liste_element;


    premier_suivant();
    premier_suivant(string nom,vector<string> liste_element);

    premier_suivant(string nom,string element);
    void afficher();
    bool possede(string tester);
};


#endif //L3_LC_F5_LANGUAGE_COMPILATION_PREMIER_SUIVANT_H
