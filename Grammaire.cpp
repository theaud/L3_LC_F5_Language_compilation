#include "Grammaire.h"
#include "Entrer.h"


Grammaire::Grammaire(const char *Fichier)
{ Entrer a;
    a.lecture(Fichier);
    Grammaire(a.Texte);
}

Grammaire::Grammaire(vector<string> grammaire_brut)
{


    for(string ligne:grammaire_brut)
    {
        vector<string> parser=Utilitaire::parse( ligne);

       Regle R1= Regle();
        R1.afficher();


    }






}

