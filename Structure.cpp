#include "Structure.h"
#include "Camille.h"
#include "Entrer.h"


Structure::Structure()
{
    //etape 0 :choix du fichier
        cout<<"rajouter choix du fichier d'entrer"<<endl;

    //etape 1 :initialisation de la gramaire
        etape1();

    //etape 2 :suppression recursiviter a gauche
       etape2();

    //etape 3 :Calcul premier et suivant
        etape3();

    //etape 4 :construction table d'analyse
        etape4();

    //etape 5 :Analyse d'une chaine d'entre
        etape5();



return ;
}








bool Structure::etape1()
{
    cout<<endl<<"----------etape 1 :initialisation de la gramaire------------"<<endl;
    Utilitaire::affichageln(Entrer::lecture("F5G0.txt"));


    Grammaire_brute.creation(Entrer::lecture("F5G0.txt"));


    Grammaire_brute.afficher("L3_LC_F5_1_sortie_Gramaire_brut.txt");


    return true;
}
bool Structure::etape2()
{

    cout<<endl<<"----------etape 2 :suppression recursiviter a gauche------------"<<endl;

    Gramairre_derecurssiver=Grammaire_brute.Derecusivite_gauche();

    Gramairre_derecurssiver.afficher("L3_LC_F5_2_sortie_Gramaire_derecurssiver.txt");


    return true;
}
bool Structure::etape3()
{ cout<<endl<<"----------etape 3 :Calcul premier et suivant------------"<<endl;

    non_terminaux=Gramairre_derecurssiver.get_non_terminaux();
    cout<<"etat non terminaux : ";
     Utilitaire::ecriture_fichier("L3_LC_F5_3_sortie_non_terminaux.txt",non_terminaux);

    terminaux=Gramairre_derecurssiver.get_terminaux(non_terminaux);
    cout<<endl<<"etat terminaux : ";
   Utilitaire::ecriture_fichier("L3_LC_F5_4_sortie_terminaux.txt",terminaux);
    terminaux.push_back("$");

    premier=Gramairre_derecurssiver.get_premier(terminaux);


   Utilitaire::ecriture_fichier("L3_LC_F5_5_sortie_premier.txt",afficher_premier());

    suivant=Gramairre_derecurssiver.get_suivant(terminaux);

    cout<<endl<<"rechercher les suivant"<<endl;
    Utilitaire::ecriture_fichier("L3_LC_F5_6_sortie_suivant.txt",afficher_suivant());




    return true;
}
bool Structure::etape4()
{
    cout<<endl<<"----------etape 4 :construction table d'analyse------------"<<endl;
    vector<Regle> table_d_analyse=Gramairre_derecurssiver.table_d_analyse(premier,terminaux,non_terminaux);

    //affichage
    return true;
}
bool Structure::etape5()
{

    cout<<endl<<"----------etape 5 :Analyse d'une chaine d'entre------------"<<endl;


    return true;
}

vector<string> Structure::afficher_premier()
{vector<string> returned;

    for(premier_suivant a:premier)
    {string tmp=" Pour "+a.Nom;
        if(a.Liste_element.size()==0){tmp+=" il n'y a pas de premier";}
        else if(a.Liste_element.size()==1){tmp+=" le premier est  : "+a.Liste_element[0];}
        else {tmp+=" les premiers sont : ";
            for(string z:a.Liste_element)
            {tmp+=z+" ";}
        }
        returned.push_back(tmp);
    }
    return returned;
}
vector<string> Structure::afficher_suivant()
{vector<string> returned;

    for(premier_suivant a:suivant)
    {string tmp=" Pour "+a.Nom;
        if(a.Liste_element.size()==0){tmp+=" il n'y a pas de suivant";}
        else if(a.Liste_element.size()==1){tmp+=" le suivant est  : "+a.Liste_element[0];}
        else {tmp+=" les suivants sont : ";
            for(string z:a.Liste_element)
            {tmp+=z+" ";}
        }
        returned.push_back(tmp);
    }   return returned;
}