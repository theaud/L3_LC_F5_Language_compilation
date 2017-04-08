

#ifndef L3_LC_F5_LANGUAGE_COMPILATION_GRAMMAIRE_H
#define L3_LC_F5_LANGUAGE_COMPILATION_GRAMMAIRE_H
#include "include.h"

#include "Regle.h"

class Grammaire {
public :
vector <Regle> List_Regle;

public :

    Grammaire();
    Grammaire(const char *Fichier);
    Grammaire(vector<string> grammaire_brut);


    vector<string> get_premier();
    vector<string> get_suivant();


};


#endif //L3_LC_F5_LANGUAGE_COMPILATION_GRAMMAIRE_H
