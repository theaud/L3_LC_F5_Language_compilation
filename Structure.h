

#ifndef L3_LC_F5_LANGUAGE_COMPILATION_STRUCTURE_H
#define L3_LC_F5_LANGUAGE_COMPILATION_STRUCTURE_H
#include <iostream>
#include <vector>

using namespace std;

#include "Grammaire.h"
#include "premier_suivant.h"

class Structure {
public:

    Grammaire Grammaire_brute;
    Grammaire Gramairre_derecurssiver;
    vector<premier_suivant> premier;
    vector<premier_suivant> suivant;
    vector<string> terminaux;
    vector<string> non_terminaux;
    Grammaire table_d_analyse;

    Structure();

    vector<string> afficher_premier();
    vector<string> afficher_suivant();
    vector<string> afficher_table_d_analyse(Grammaire table_d_analyse);
    vector<string> affichage_non_terminaux(vector<string> non_terminaux);
    vector<string> affichage_terminaux(vector<string> terminaux);

    bool etape1();
    bool etape2();
    bool etape3();
    bool etape4();
    bool etape5();
};


#endif //L3_LC_F5_LANGUAGE_COMPILATION_STRUCTURE_H
