

#ifndef L3_LC_F5_LANGUAGE_COMPILATION_REGLE_H
#define L3_LC_F5_LANGUAGE_COMPILATION_REGLE_H

#include <vector>
#include "include.h"

class Regle {
public:
    string Nom;
    vector<vector<string>> token;


    Regle();
    Regle(string nom,vector<string> entrer);
   void afficher();

};


#endif //L3_LC_F5_LANGUAGE_COMPILATION_REGLE_H
