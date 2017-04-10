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

