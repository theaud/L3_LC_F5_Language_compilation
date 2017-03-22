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
};


#endif //L3_LC_F5_LANGUAGE_COMPILATION_UTILITAIRE_H
