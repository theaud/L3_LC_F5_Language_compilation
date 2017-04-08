

#include "Structure.h"
#include "Camille.h"


Structure::Structure()
{
    //etape 0 :choix du fichier
    cout<<"rajouter choix du fichier d'entrer"<<endl;


    //etape 1 :initialisation de la gramaire
    cout<<endl<<"----------etape 1 :initialisation de la gramaire------------"<<endl;
    Grammaire_brute=Grammaire("F5G0_bis.txt");

    //etape 2 :suppression recursiviter a gauche
    cout<<endl<<"----------etape 2 :suppression recursiviter a gauche------------"<<endl;

  //  Gramairre_derecurssiver=Camille::Derecusivite_gauche(Grammaire_brute);

    //etape 3 :Calcul premier et suivant
    cout<<endl<<"----------etape 3 :Calcul premier et suivant------------"<<endl;

   // vector<string> premier=Gramairre_derecurssiver.get_premier();
  //  vector<string> suivant=Gramairre_derecurssiver.get_suivant();

    //etape 4 :construction table d'analyse
    cout<<endl<<"----------etape 4 :construction table d'analyse------------"<<endl;

    //etape 5 :Analyse d'une chaine d'entre

    cout<<endl<<"----------etape 5 :Analyse d'une chaine d'entre------------"<<endl;



return ;
}