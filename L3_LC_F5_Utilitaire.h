//
// Created by mathieu on 03/03/2017.
//

#ifndef L3_LC_F5_LANGUAGE_COMPILATION_UTILITAIRE_H
#define L3_LC_F5_LANGUAGE_COMPILATION_UTILITAIRE_H

#include <iostream>
#include <vector>
using namespace std;

class Utilitaire {
public:
    void debug(string text);
    void debugln(string text);
    static void affichageln( vector<string> entrer);
    static void affichage(vector<string> entrer);
    static vector<string> parse(string entrer);
    static bool appartient(string a,vector<string>non_terminaux);
    static vector<string> extend(string valeur);
    static vector<string> test();
    static void ecriture_fichier( const char *Fichier,const char *Fichier2,vector<string> entrer);
    static void clear_fichier(const char *Fichier);

};


#endif //L3_LC_F5_LANGUAGE_COMPILATION_UTILITAIRE_H
