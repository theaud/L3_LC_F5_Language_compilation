#include <sstream>
#include <fstream>
#include "L3_LC_F5_Utilitaire.h"
#include "L3_LC_F5_Entrer.h"


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

void Utilitaire::ecriture_fichier(const char *Fichier,const char *Fichier2, vector<string> entrer)
{
   vector<string> copy=L3_LC_F5_Entrer::lecture(Fichier2);

    ofstream sortie(Fichier);
    ofstream ss(Fichier2);

    for(string a:copy)    {ss<<a<<endl;}

        for(string ligne:entrer)
        {ss<<ligne<<endl;sortie<<ligne<<endl;cout<<ligne<<endl;}


    sortie<<endl<<"---------------------------------------------------------------"<<endl;
    cout<<endl<<"-----------------------------------------------------------------"<<endl;
    ss<<endl<<"-------------------------------------------------------------------"<<endl;

}
void Utilitaire::clear_fichier(const char *Fichier){ofstream ss(Fichier);}

vector<string> Utilitaire::extend(string valeur){vector <string> returned;returned.push_back(valeur);    return returned;}

 vector<string> Utilitaire::test()
{
    vector<string> a=Utilitaire::parse("te te");
    return a;
}