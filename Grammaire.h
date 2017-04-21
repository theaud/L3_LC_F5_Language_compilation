

#ifndef L3_LC_F5_LANGUAGE_COMPILATION_GRAMMAIRE_H
#define L3_LC_F5_LANGUAGE_COMPILATION_GRAMMAIRE_H
#include "include.h"

#include "Regle.h"
#include "premier_suivant.h"

class Grammaire {
public :
vector <Regle> List_Regle;

public :

    void creation(vector<string> grammaire_brut);
    Grammaire();
    Grammaire(const char *Fichier);
    Grammaire(vector<string> grammaire_brut);


    void afficher(const char *Fichier);
    bool test(vector<premier_suivant> actuel,vector<string> terminaux);
    vector<premier_suivant> get_premier(vector<string> terminaux);
    vector<premier_suivant> get_suivant(vector<string> terminaux);
    vector<string> get_terminaux(vector<string> non_terminaux);
    vector<string> get_non_terminaux();
    premier_suivant selection(vector<premier_suivant> liste,string nom);
    vector<Regle> table_d_analyse(vector<premier_suivant> premier, vector<string> terminaux,vector<string> non_terminaux);
    Grammaire Derecusivite_gauche();
    Regle Grammaire::select(string nom);
};


#endif //L3_LC_F5_LANGUAGE_COMPILATION_GRAMMAIRE_H
