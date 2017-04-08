#include "Regle.h"

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


void Regle::afficher()
{
    cout<<endl<<"Regle : "<<Nom<<" donne :"<<endl;
    for(vector<string>ligne :token)
    {cout<<"     ";
        for(string Case:ligne)
        {
            cout<<" "<<Case;
        }
        cout<<endl;
    }



}