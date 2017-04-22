#include "Structure.h"

#include "Entrer.h"
#include "Utilitaire.h"


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

     Utilitaire::ecriture_fichier("L3_LC_F5_3_sortie_non_terminaux.txt",affichage_non_terminaux(non_terminaux));

    terminaux=Gramairre_derecurssiver.get_terminaux(non_terminaux);

   Utilitaire::ecriture_fichier("L3_LC_F5_4_sortie_terminaux.txt",affichage_terminaux(terminaux));
    terminaux.push_back("$");

    premier=Gramairre_derecurssiver.get_premier(terminaux);

   Utilitaire::ecriture_fichier("L3_LC_F5_5_sortie_premier.txt",afficher_premier());

    suivant=Gramairre_derecurssiver.get_suivant(premier,terminaux,non_terminaux);

    Utilitaire::ecriture_fichier("L3_LC_F5_6_sortie_suivant.txt",afficher_suivant());

    return true;
}
bool Structure::etape4()
{

     table_d_analyse=Gramairre_derecurssiver.table_d_analyse(premier,suivant,terminaux,non_terminaux);


    cout<<endl<<"----------etape 4 :construction table d'analyse------------"<<endl;
    Utilitaire::ecriture_fichier("L3_LC_F5_7_table_d_analyse.txt",afficher_table_d_analyse(table_d_analyse));

    return true;
}
bool Structure::etape5()
{

    cout<<endl<<"----------etape 5 :Analyse d'une chaine d'entre------------"<<endl;


    return true;
}
vector<string> Structure::afficher_premier()
{vector<string> returned;
    returned.push_back("Affichage les premiers");
    for(premier_suivant a:premier)
    {string tmp=" Pour\t"+a.Nom+"\t";
        if(a.Liste_element.size()==0){tmp+=" il n'y a pas de premier";}
        else if(a.Liste_element.size()==1){tmp+=" le premier est  : "+a.Liste_element[0];}
        else {tmp+=" les premiers sont : [  ";

            for(int i=0;i<a.Liste_element.size();i++)
            {
                if(i+1<a.Liste_element.size())
                {tmp+=a.Liste_element[i]+"\t~\t";}
                else
                {tmp+=a.Liste_element[i];}
            }
        }
        tmp+="  ]";
        returned.push_back(tmp);
    }
    return returned;
}
vector<string> Structure::afficher_suivant()
{vector<string> returned;
    returned.push_back("Affichage les suivants");
    for(premier_suivant a:suivant)
    {string tmp=" Pour\t"+a.Nom+"\t";
        if(a.Liste_element.size()==0){tmp+=" il n'y a pas de suivant";}
        else if(a.Liste_element.size()==1){tmp+=" le suivant est  : [\t"+a.Liste_element[0];}
        else {tmp+=" les suivants sont : [\t";
            for(int i=0;i<a.Liste_element.size();i++)
            {
                if(i+1<a.Liste_element.size())
                {tmp+=a.Liste_element[i]+"\t~\t";}
                else
                {tmp+=a.Liste_element[i];}
            }
        }
        tmp+="  ]";
        returned.push_back(tmp);
    }   return returned;
}
vector<string> Structure::afficher_table_d_analyse(L3_LC_F5_Grammaire table_d_analyse)
{
    vector<string> retour;
    string tmp="";
    for(string a : terminaux)
    {
        if(a.compare("#"))
            tmp+=a+"\t";
    }
    retour.push_back("\t"+tmp);


    for(Regle ligne : table_d_analyse.List_Regle)
    {int i=0;tmp=ligne.Nom;

        for(vector<string> case_tableau:ligne.token)
        {
            if(case_tableau.size()==0)
            { if(terminaux[i].compare("#")!=0)
                    tmp+="-";
            }
            else
            {for(string valeur:case_tableau)                {tmp+=valeur;}}
            tmp+="\t";
            i++;
        }
       retour.push_back(tmp);
    }
    return retour;
}

vector<string> Structure::affichage_non_terminaux(vector<string> non_terminaux)
{vector<string> a;
    string returned="Etat non terminaux : [";
    for(int i=0;i<non_terminaux.size();i++)    { returned+="\t"+non_terminaux[i]; }
    returned+="\t]";
    a.push_back(returned);
    return a;
}
vector<string> Structure::affichage_terminaux(vector<string> terminaux)
{vector<string> a;
    string returned="Etat terminaux : [";
    for(int i=0;i<terminaux.size();i++)    { returned+="\t"+terminaux[i]; }
    returned+="\t]";
    a.push_back(returned);
    return a;
}