#include <fstream>
#include <cstdlib>
#include "L3_LC_F5_Grammaire.h"
#include "L3_LC_F5_Entrer.h"


L3_LC_F5_Grammaire::L3_LC_F5_Grammaire(){}

L3_LC_F5_Grammaire::L3_LC_F5_Grammaire(const char *Fichier){    L3_LC_F5_Grammaire(L3_LC_F5_Entrer::lecture(Fichier));}

L3_LC_F5_Grammaire::L3_LC_F5_Grammaire(vector<string> grammaire_brut)
{ for(string ligne:grammaire_brut)
    { vector<string> parser=Utilitaire::parse( ligne);
       Regle R1=Regle(parser);

        List_Regle.push_back(R1);
    }
}

void L3_LC_F5_Grammaire::creation(vector<string> grammaire_brut)
{
    for(string ligne:grammaire_brut)
    { vector<string> parser=Utilitaire::parse( ligne);
    //    cerr<<"void L3_LC_F5_Grammaire::creation(vector<string> grammaire_brut) supprimer k'utilisation des espace comme separateur";

        Regle R1=Regle(parser);

        List_Regle.push_back(R1);
    }
}

void L3_LC_F5_Grammaire::afficher(const char *Fichier,string complet)
{
    vector<string> liste;
    ofstream sortie(Fichier);
    for(Regle R1:List_Regle)
    {  for(string ligne: R1.afficher())
        {liste.push_back(ligne);}
    }
    Utilitaire::ecriture_fichier(Fichier,complet.c_str(),liste);

}

premier_suivant L3_LC_F5_Grammaire::selection(vector<premier_suivant> liste,string nom)
{ for(premier_suivant current:liste){ if(!current.Nom.compare(nom)){return current;}}}



bool L3_LC_F5_Grammaire::test(vector<premier_suivant> actuel,vector<string> terminaux)
{for(premier_suivant a:actuel)
    { for(string z:a.Liste_element)
        {if(!Utilitaire::appartient(z,terminaux))
            { return false;}
        }
    }
    return true;
}

vector<premier_suivant> L3_LC_F5_Grammaire::get_premier(vector<string> terminaux)
{ vector<premier_suivant>initialiser;
    vector<premier_suivant>tmp;
    for(Regle a:List_Regle)
    {initialiser.push_back(premier_suivant(a.Nom,a.get_premier())); }

//remplacement des element non terminaux par leur propre suivant
    do{for(Regle a:List_Regle)
        { premier_suivant current;
            current.Nom=a.Nom;
            for(string element:a.get_premier())
            {if(Utilitaire::appartient(element,terminaux))
                {current.Liste_element.push_back(element);}
                else
                {
                    for(string a_copier:selection(initialiser,element).Liste_element)
                    { current.Liste_element.push_back(a_copier);}
                }
            }
            tmp.push_back(current);
        }
        initialiser=tmp;
        tmp.clear();
    }while(!test(initialiser,terminaux));

    return  initialiser;
}



vector<string> L3_LC_F5_Grammaire::get_terminaux(vector<string> non_terminaux)
{   vector<string> element;
    vector<string> terminaux_brut;
    vector<string> terminaux;

 //----------------------------------
    for(Regle tester:List_Regle)
    {for(vector<string> a:tester.token)
        {if(a.size()>0 )
            {for(string tester:a)
                { element.push_back(tester); }
            }
        }
    }
  //-------------------------------------------
    for(string a:element)//suppression etat nn terminaux de la liste
    {if(!Utilitaire::appartient(a,non_terminaux))
        {terminaux_brut.push_back(a);}
    }
//-------------------------------------------------------
    for(string a:terminaux_brut)//suppresion doublon
    { if(!Utilitaire::appartient(a,terminaux) )
        { terminaux.push_back(a);}
    }

    return terminaux;
}
vector<string> L3_LC_F5_Grammaire::get_non_terminaux()
{ vector<string> non_terminaux;
    for(Regle tester:List_Regle)
    {non_terminaux.push_back(tester.Nom);}
    return non_terminaux;
}
L3_LC_F5_Grammaire L3_LC_F5_Grammaire::Derecusivite_gauche()
{
    L3_LC_F5_Grammaire derecursiver;
    int nb_recursiviter;

    for(Regle R:List_Regle)
    {nb_recursiviter= R.recursif();
        if(nb_recursiviter==0)
        {
            derecursiver.List_Regle.push_back(R);
        }
        else
        {if(nb_recursiviter<R.token.size())
            {Regle A;
             Regle A_bis;
             A.Nom=R.Nom;
             A_bis.Nom=A.Nom+"'";
            A_bis.token.push_back(Utilitaire::extend("#"));

                for(vector<string> tester:R.token)
                { if(!tester[0].compare(R.Nom))//recursif
                    {vector<string> tmp;
                        for(int i=1;i<tester.size();i++)
                        {tmp.push_back(tester[i]);}
                        tmp.push_back(A_bis.Nom);
                        A_bis.token.push_back(tmp);
                    }
                    else //non recursif => Nomregle=> Liste_nn_recursif Nomregle'
                    { vector<string> tmp;
                        for(string a:tester){tmp.push_back(a);}
                        tmp.push_back(A_bis.Nom);
                        A.token.push_back(tmp);
                    }
                }
                derecursiver.List_Regle.push_back(A);
                derecursiver.List_Regle.push_back(A_bis);

            }
            else
            {cout<<endl<<R.Nom<<" "<<R.token.size()<<" "<<nb_recursiviter<<endl;
              cout<<"La grammaire entre comporte une regle qui ne peut pas etre derecursiver";
              cout<< "(tous les element commence par le nom de cette regle"<<endl;
              exit(1);
            }
        }
    }

    return derecursiver;
}

L3_LC_F5_Grammaire L3_LC_F5_Grammaire::table_d_analyse(vector<premier_suivant> premier,vector<premier_suivant> suivant, vector<string> terminaux,vector<string> non_terminaux)
{    L3_LC_F5_Grammaire table_d_analyse;

    /*
1. Pour chaque production A α de la grammaire, procéder aux étapes 2 et 3.
2. Pour chaque terminal a dans PREMIER(α), ajouter A α à M[A,a].
3. Si ε est dans PREMIER(α), ajouter A α à M[A,b] pour chaque terminal b dans SUIVANT(A). Si ε est dans PREMIER(α) et $ est dans SUIVANT(A), ajouter A α à M[A,$].
3. Faire de chaque entrée non définie de M une erreur.
     */

    for(premier_suivant ligne:premier)
    {Regle ligne_tableau;
    ligne_tableau.Nom=ligne.Nom;

            for (string colonne:terminaux)
            {if(colonne.compare("#")!=0)
                { vector<string> case_tableau;

                if (ligne.possede(colonne))//cas ou la valeur est un etat premier de la regle
                    {
                        case_tableau=getRegle(ligne.Nom,colonne,terminaux,premier);

                    }
                else if(get_ID_List_premier_suivant(premier,"#")!=-1 )//cas ou Regle posede #
                    {
                        cout <<"testerrrrr "<<endl;
                        vector<string> a;
                        a.push_back("test");
                        case_tableau=a;
                    }


                ligne_tableau.token.push_back(case_tableau);
                }
            }

        table_d_analyse.List_Regle.push_back(ligne_tableau);
    }

    return table_d_analyse;
}

Regle L3_LC_F5_Grammaire::select(string nom)
{for(Regle tester:List_Regle)
    {  if( tester.Nom.compare(nom)==0)        {return tester;}}
    Regle vide;
    return vide ;
}

vector<premier_suivant> L3_LC_F5_Grammaire::get_suivant(vector<premier_suivant> premier,vector<string> terminaux,vector<string> non_terminaux)
{
    vector<premier_suivant>suivant;

    cout<<" A rajouter get_suivant2 la selection pour mettre $"<<endl;
    //1.Mettre $ dans SUIVANT(S), où S est l’axiome et $ est le marqueur de fin.

    for(Regle a:List_Regle)
    {
        premier_suivant test;
        test.Nom=a.Nom;
        test.Liste_element.push_back("$");//check la condition quand c'est pas vrai
        suivant.push_back(test);

    }

    //2. S’il y a une production AαBβ, le contenu de PREMIER(β) excepté ε, est ajouté à SUIVANT(B).
    for(Regle a:List_Regle)
    {
        for(vector<string> b:a.token)
        {
            if(b.size()==3 && Utilitaire::appartient(b[1],non_terminaux) )
            {if(Utilitaire::appartient(b[2],non_terminaux))
                {for(string z:premier[get_ID_List_premier_suivant(premier,b[2])].Liste_element)
                    { if(z.compare("#")!=0)
                        {suivant[get_ID_List_premier_suivant(suivant,b[1])].Liste_element.push_back(z); }
                    }
                }
                else
                {suivant[get_ID_List_premier_suivant( suivant,b[1])].Liste_element.push_back(b[2]);}
            }
        }
    }

    //3. S’il existe une production AαB ou une production AαBβ telle que PREMIER(β) contient ε (c.a.d. β ε), les éléments de SUIVANT(A) sont ajoutés à SUIVANT(B).

    for(Regle a:List_Regle)
    {for(vector<string> b:a.token)
        {if((b.size()==2 && Utilitaire::appartient(b[1],non_terminaux))||(b.size()==3 && get_ID_List_premier_suivant(premier,b[2])!=-1 && premier[get_ID_List_premier_suivant(premier,b[2])].possede("#") ))
            {if(a.Nom.compare(b[1])!=0)
                { for(string z:suivant[get_ID_List_premier_suivant(suivant,a.Nom)].Liste_element)
                    { if(z.compare("#")!=0 && !Utilitaire::appartient(z,suivant[get_ID_List_premier_suivant(suivant,b[1])].Liste_element))//si different de # et qu'il n'est pas deja present
                        {suivant[get_ID_List_premier_suivant(suivant,b[1])].Liste_element.push_back(z);}
                    }
                }
            }
        }
    }

return suivant;
}


int L3_LC_F5_Grammaire::get_ID_List_regle(vector<Regle> list,string nom)
{for(int i=0;i<list.size();i++){if(list[i].Nom.compare(nom)==0){return i;}}return -1;}

int L3_LC_F5_Grammaire::get_ID_List_premier_suivant(vector<premier_suivant> list,string nom)
{for(int i=0;i<list.size();i++){if(list[i].Nom.compare(nom)==0){return i;}}return -1;}



vector<string> L3_LC_F5_Grammaire::getRegle(string nom_regle_origine,string valeur_rechercher,vector< string> non_terminaux,vector<premier_suivant> premier)
{

    int i=get_ID_List_regle(List_Regle,nom_regle_origine);
    if(List_Regle[i].token.size()==1)//un seul element c'est donc le bon
    {for(vector<string> returned:List_Regle[i].token)
        {return returned; }

    }
    else if(List_Regle[i].token.size()>1)
    {
        for(vector<string> returned:List_Regle[i].token)
        {
            if(returned.size()>0 && returned[0].compare(valeur_rechercher)==0)
                {return returned; }

            else if (returned.size()>0 && Utilitaire::appartient(returned[0],non_terminaux))//a ajouter cas
                {// cout<<endl<<" ajouter comparaison du premier de returned[0] qui est un etat nn terminaux :"<<nom_regle_origine<<" "<<valeur_rechercher;

                }
        }

    }
    cout<<endl<<" ajouter comparaison du premier de returned[0] qui est un etat nn terminaux :"<<nom_regle_origine<<" "<<valeur_rechercher;

    vector<string> vide;
    return vide ;
}



