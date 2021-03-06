

#ifndef L3_LC_F5_LANGUAGE_COMPILATION_STRUCTURE_H
#define L3_LC_F5_LANGUAGE_COMPILATION_STRUCTURE_H

#include "L3_LC_F5_include.h"
#include "L3_LC_F5_Grammaire.h"


class Structure {
public:

    L3_LC_F5_Grammaire Grammaire_brute;
    L3_LC_F5_Grammaire Gramairre_derecurssiver;
    vector<premier_suivant> premier;
    vector<premier_suivant> suivant;
    vector<string> terminaux;
    vector<string> terminaux_premier;
    vector<string> non_terminaux;
    L3_LC_F5_Grammaire table_d_analyse;
    string fichier;
    string complet;
    Structure();

     vector<string> afficher_premier();
     vector<string> afficher_suivant();
     vector<string> afficher_table_d_analyse(L3_LC_F5_Grammaire table_d_analyse);
     vector<string> affichage_non_terminaux(vector<string> non_terminaux);
     vector<string> affichage_terminaux(vector<string> terminaux);
     vector<string> netoyage_terminaux(vector<string>  terminaux_brut);
     vector<string> Analyse(string chaine_entrer);

    bool etape0();
    bool etape1();
    bool etape2();
    bool etape3();
    bool etape4();
    bool etape5();
};


#endif //L3_LC_F5_LANGUAGE_COMPILATION_STRUCTURE_H
