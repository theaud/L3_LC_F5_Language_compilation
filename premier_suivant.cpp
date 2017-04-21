//
// Created by mathieu on 09/04/2017.
//

#include "premier_suivant.h"

premier_suivant::premier_suivant(){}

premier_suivant::premier_suivant(string nom,vector<string> liste_element)
{
    Nom=nom;
    Liste_element=liste_element;

}

premier_suivant::premier_suivant(string nom,string element)
{
    Nom=nom;
    Liste_element.push_back(element);

}

void premier_suivant::afficher()
{
    cout<<Nom<<" = [ ";
    for(string valeur:Liste_element)
    {
        cout<<valeur<<" , ";
    }
    cout<<" ]"<<endl;

}

bool premier_suivant::possede(string tester)
{
    for(string a:Liste_element)
    {
        if(a.compare(tester)==0){ return true;}
    }


    return false;
}
