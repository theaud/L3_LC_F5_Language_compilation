#include <fstream>
#include "Regle.h"

//----------------------------------------------------------------------------------------------------------------------
//-----------------------------------   Constructeur    ----------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------
Regle::Regle()
{

}

Regle::Regle(vector<string> entrer)
{

    if(entrer.size()<=2){cerr<<"Regle::Regle(vector<string> entrer) , Entrer trop courte"<<endl;}
    if(entrer[1]!="="){cerr<<"Regle::Regle(vector<string> entrer) , Erreur de synthaxe"<<endl;}

     Nom=entrer[0];

    vector<string> current;
    for(int i =2;i<entrer.size();i++)
    {
        if(entrer[i]=="|")
            {token.push_back(current);
                current.clear();
            }
        else
            {current.push_back(entrer[i]);}

    }
    token.push_back(current);

}

Regle::Regle(string nom,vector<string> entrer)
{
    Nom=nom;

    vector<string> current;
    for(int i =0;i<entrer.size();i++)
    {
        if(entrer[i]=="|")
        {token.push_back(current);
            current.clear();
        }
        else
        {current.push_back(entrer[i]);}

    }
    token.push_back(current);

}
Regle::Regle(string nom,string entrer)
{
    Nom=nom;
    vector<string> current;
    current.push_back(entrer);
    token.push_back(current);

}
//----------------------------------------------------------------------------------------------------------------------
//-----------------------------------   afficher    ----------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------
vector<string> Regle::afficher()
{    vector<string> returned;
    returned.push_back("Regle : "+Nom+" donne :");
    for(vector<string>ligne :token)
    {string tmp="     ";
         for(string Case:ligne)
        {tmp+=" "+Case;}
        returned.push_back(tmp);
    }
    return returned ;
}
//----------------------------------------------------------------------------------------------------------------------
//-----------------------------------   get_premier/get_suivant    ----------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------
vector<string> Regle::get_premier()
{
    vector<string> premier;
    for(vector<string> a:token)
    {if(a.size()>0){  premier.push_back(a[0]); }}
    return premier;
}

vector<string> Regle::get_suivant()
{
    vector<string> initialisation;
    for(vector<string> a:token)
    {if(a.size()>0){cout<<endl<<a[a.size()-1]<<" ";

            if(!a[a.size()-1].compare("#")){

                cout<<a[a.size()-1]<<"="<<"#"<<endl;
                initialisation.push_back("$");
            }
            else
            {
                cout<<"ajoue "<<a[a.size()-1]<<endl;
                initialisation.push_back(a[a.size()-1]);
            }

        }}
    return initialisation;
}

//----------------------------------------------------------------------------------------------------------------------
//-----------------------------------   recursif/nn_recursif    ----------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------
int Regle::recursif()
{int cmp=0;for(vector<string> ligne:token){ if(!ligne[0].compare(Nom)){ cmp++;}}return cmp;}

vector<string> Regle::nn_recursif()
{for(vector<string> R:token){if(R[0].compare(Nom)){return R;}}}


vector<string> Regle::getRegle(string valeur_initiale)
{
    for(vector<string> tester:token)
    {
        if(tester.size()>0 && tester[0].compare(valeur_initiale)==0)
        {
            return tester;
        }
    }

    vector<string> vide;
    return vide ;
}