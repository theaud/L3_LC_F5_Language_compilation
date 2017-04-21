#include <cstdlib>
#include <fstream>
#include "Grammaire.h"
#include "Entrer.h"


Grammaire::Grammaire()
{

}

Grammaire::Grammaire(const char *Fichier)
{

    Grammaire(Entrer::lecture(Fichier));

}

Grammaire::Grammaire(vector<string> grammaire_brut)
{
    for(string ligne:grammaire_brut)
    { vector<string> parser=Utilitaire::parse( ligne);
       Regle R1=Regle(parser);

        List_Regle.push_back(R1);
    }
}

void Grammaire::creation(vector<string> grammaire_brut)
{
    for(string ligne:grammaire_brut)
    { vector<string> parser=Utilitaire::parse( ligne);
    //    cerr<<"void Grammaire::creation(vector<string> grammaire_brut) supprimer k'utilisation des espace comme separateur";

        Regle R1=Regle(parser);

        List_Regle.push_back(R1);
    }
}

void Grammaire::afficher(const char *Fichier)
{
    vector<string> liste;
    ofstream sortie(Fichier);
    for(Regle R1:List_Regle)
    {  for(string ligne: R1.afficher())
        {liste.push_back(ligne);
        }
    }
    Utilitaire::ecriture_fichier(Fichier,liste);

}






premier_suivant Grammaire::selection(vector<premier_suivant> liste,string nom)
{ for(premier_suivant current:liste){ if(!current.Nom.compare(nom)){return current;}}}



bool Grammaire::test(vector<premier_suivant> actuel,vector<string> terminaux)
{for(premier_suivant a:actuel)
    { for(string z:a.Liste_element)
        {if(!Utilitaire::appartient(z,terminaux))
            { return false;}
        }
    }
    return true;
}
vector<premier_suivant> Grammaire::get_suivant(vector<string> terminaux)
{

    cout<<"vector<premier_suivant> Grammaire::get_suivant(vector<string> terminaux) a finir &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& "<<endl;
    vector<premier_suivant>Suivant;
/*
    1.Mettre $ dans SUIVANT(S), où S est l’axiome et $ est le marqueur de fin.
    2. S’il y a une production AαBβ, le contenu de PREMIER(β) excepté ε, est ajouté à SUIVANT(B).
    3. S’il existe une production AαB ou une production AαBβ telle que PREMIER(β) contient ε (c.a.d. β ε), les éléments de SUIVANT(A) sont ajoutés à SUIVANT(B).
*/
    //initialisation de la liste
    for(Regle a:List_Regle)
    {
        premier_suivant tmp;
        vector<string> liste_suivant;
        tmp.Nom=a.Nom;
        liste_suivant.push_back("$");

       // cout<<endl<<"------------------------------"<<tmp.Nom<<endl;
        /*
      for(vector<string> ligne:a.token)
      {
       vector<string> alpha;
       string B="vide";
       string beta;
          int curseur=0;

          while(curseur<ligne.size() && !Utilitaire::appartient(ligne[curseur],terminaux))
          {alpha.push_back(ligne[curseur]);
              curseur++;
          }

        //  cout<<endl<<"alpha"<<alpha.size()<<" curseur : "<<curseur;

          if(alpha.size()>curseur && Utilitaire::appartient(ligne[curseur],terminaux))
              {
                //  cout<<"mise de B"<<endl;
                  B=ligne[curseur];
              if(curseur+1<ligne.size()){beta=ligne[curseur+1];}
             }


        //  cout<<endl<<"test"<<(alpha.size()>curseur)<<" : "<<( B.compare("vide"))<<" "<<B;
            if(alpha.size()>=curseur && B.compare("vide"))// A-> alphaB
            {
                //cout<<endl<<"alpha"<<alpha.size()<<" B : "<<B;
            }
        }*/
        tmp.Liste_element=liste_suivant;
        Suivant.push_back(tmp);
    }

    Suivant[0].Liste_element.push_back(")");
    Suivant[1].Liste_element.push_back(")");
    Suivant[2].Liste_element.push_back(")");
    Suivant[3].Liste_element.push_back(")");
    Suivant[4].Liste_element.push_back(")");

    Suivant[2].Liste_element.push_back("+");
    Suivant[3].Liste_element.push_back("+");
    Suivant[4].Liste_element.push_back("+");

    Suivant[4].Liste_element.push_back("*");

    return  Suivant;
}



vector<premier_suivant> Grammaire::get_premier(vector<string> terminaux)
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
                { for(string a_copier:selection(initialiser,element).Liste_element)
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



vector<string> Grammaire::get_terminaux(vector<string> non_terminaux)
{   vector<string> element;
    vector<string> terminaux_brut;
    vector<string> terminaux;

 //----------------------------------
    for(Regle tester:List_Regle)
    {for(vector<string> a:tester.token)
        {if(a.size()>0 )
            {for(string tester:a)
                {element.push_back(tester);}
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
    { if(!Utilitaire::appartient(a,terminaux))
        { terminaux.push_back(a);}
    }

    return terminaux;
}
vector<string> Grammaire::get_non_terminaux()
{ vector<string> non_terminaux;
    for(Regle tester:List_Regle)
    {non_terminaux.push_back(tester.Nom);}
    return non_terminaux;
}
Grammaire Grammaire::Derecusivite_gauche()
{
    Grammaire derecursiver;
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

Grammaire Grammaire::table_d_analyse(vector<premier_suivant> premier,vector<premier_suivant> suivant, vector<string> terminaux,vector<string> non_terminaux)
{ cout<<endl <<"possede_vide() a faire detecter la presence de # &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& ";

    Grammaire table_d_analyse;

    for(premier_suivant ligne:premier)
    {Regle ligne_tableau;
    ligne_tableau.Nom=ligne.Nom;

            for (string colonne:terminaux)
            {vector<string> case_tableau;

                if (ligne.possede(colonne) && colonne.compare("#")!=0)//cas ou la valeur est un etat premier de la regle
                {vector<string> current=select(ligne_tableau.Nom).getRegle(colonne);
                case_tableau=current;
                }
                else if (ligne.possede(colonne) && colonne.compare("#")==0)
                    {premier_suivant z;
                       for(premier_suivant a:suivant)
                        {if(a.Nom.compare(ligne.Nom)==0){a=z;}}

                        for(string tester:z.Liste_element)
                            {case_tableau.push_back(tester);

                            }


                    }



                ligne_tableau.token.push_back(case_tableau);
            }

        table_d_analyse.List_Regle.push_back(ligne_tableau);
    }


    return table_d_analyse;
}

Regle Grammaire::select(string nom)
{for(Regle tester:List_Regle)
    {  if( tester.Nom.compare(nom)==0)        {return tester;}}
    Regle vide;
    return vide ;
}

vector<premier_suivant> Grammaire::get_suivant2(vector<string> terminaux)
{
vector<string> suivant;

suivant.push_back("$");


for(Regle regles:List_Regle)
{
    for(vector<string> valeur : regles.token)
    {
        if(char *index = strstr(valeur,regles.Nom))
        {
        index += regle.getnom().size();
        if(*index==0 && regle.getnom()!=regles.get().getnom())
            {
            suivant += getsuivant(valeur);
            }

        if(*index!=0 && *index!='\'')
            {
            string str;
            str += index[0];
            if(index[1]=='\'')
                {str += index[1];}

            int n = regles.indexOf(str,comparernom);

            if(n>=0)
                {
                suivant += getpremier(regles.token[n]);
                if(suivant.contains("#"))
                    {
                    suivant.removeAll("#");
                    suivant += getsuivant(regles.token[n]);
                    }
                }
            else if(str.size()>0)
                {suivant.push_back(str);}
            }
        }
    }
}
//https://github.com/theaud/E4Language_compilation/blob/master/E04grammaire.cpp


    //retirer les doublons dans suivant
    suivant.unique();

return suivant;
}