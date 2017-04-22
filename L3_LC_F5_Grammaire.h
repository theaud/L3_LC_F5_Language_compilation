

#ifndef L3_LC_F5_LANGUAGE_COMPILATION_GRAMMAIRE_H
#define L3_LC_F5_LANGUAGE_COMPILATION_GRAMMAIRE_H

#include "L3_LC_F5_include.h"
#include "L3_LC_F5_Regle.h"
#include "L3_LC_F5_premier_suivant.h"

class L3_LC_F5_Grammaire {
public :
vector <Regle> List_Regle;

public :

    void creation(vector<string> grammaire_brut);
    L3_LC_F5_Grammaire();
    L3_LC_F5_Grammaire(const char *Fichier);
    L3_LC_F5_Grammaire(vector<string> grammaire_brut);


    void afficher(const char *Fichier,string complet);
    bool test(vector<premier_suivant> actuel,vector<string> terminaux);
    vector<premier_suivant> get_premier(vector<string> terminaux);

    vector<premier_suivant> get_suivant(vector<premier_suivant> premier,vector<string> terminaux,vector<string> non_terminaux);

    int get_ID_List_regle(vector<Regle> list,string nom);
    int get_ID_List_premier_suivant(vector<premier_suivant> list,string nom);
    vector<string> get_terminaux(vector<string> non_terminaux);
    vector<string> get_non_terminaux();
    premier_suivant selection(vector<premier_suivant> liste,string nom);
    L3_LC_F5_Grammaire table_d_analyse(vector<premier_suivant> premier,vector<premier_suivant> suivant, vector<string> terminaux,vector<string> non_terminaux);
    L3_LC_F5_Grammaire Derecusivite_gauche();
    Regle select(string nom);
    vector<string> getRegle(string nom_regle_origine,string valeur_rechercher,vector< string> non_terminaux,vector<premier_suivant> premier);

};


#endif //L3_LC_F5_LANGUAGE_COMPILATION_GRAMMAIRE_H
