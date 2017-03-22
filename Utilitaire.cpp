//
// Created by mathieu on 03/03/2017.
//

#include <vector>
#include <sstream>
#include "include.h"


void Utilitaire::debug(string text)
{
    if(DEBUG ==true)
    {
        cout<< text;
    }
}
void Utilitaire::debugln(string text)
{
    if(DEBUG ==  true)
    {
        cout<< text<<endl;
    }
}


vector<string> Utilitaire::parse(string entrer) {
    vector<string> retour;
    stringstream ss(entrer);
    string tok;
    while(getline(ss, tok, ' ')) {
        retour.push_back(tok);
    }
    return retour;
}

void Utilitaire::affichageln( vector<string> entrer){ for(string ligne:entrer){cout<<ligne<<endl;}}
void Utilitaire::affichage( vector<string> entrer){ for(string ligne:entrer){cout<<ligne<<" ";}}