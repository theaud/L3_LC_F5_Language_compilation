#include <sstream>
#include <fstream>
#include "Utilitaire.h"



bool Utilitaire::appartient(string element_tester,vector<string>list_tester)
{for(string a:list_tester)
    {if(!a.compare(element_tester)){return true;}}
    return false;
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
void Utilitaire::affichage( vector<string> entrer){ for(string ligne:entrer){cout<<ligne<<" ";}cout<<endl;}

void Utilitaire::ecriture_fichier(const char *Fichier, vector<string> entrer)
{ofstream sortie(Fichier);for(string ligne:entrer){sortie<<ligne<<endl;cout<<ligne<<endl;}sortie<<endl;cout<<endl;}

vector<string> Utilitaire::extend(string valeur){vector <string> returned;returned.push_back(valeur);    return returned;}

 vector<string> Utilitaire::test()
{
    vector<string> a=Utilitaire::parse("te te");
    return a;
}