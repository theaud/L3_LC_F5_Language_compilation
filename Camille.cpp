#include "Camille.h"

/*
Grammaire Camille::Derecusivite_gauche(Grammaire entrer)
{

    Grammaire Derecusive;

    for(Regle tester:*entrer.List_Regle)
    {

        int nb_recursivite=recusive(*tester);
        if(nb_recursivite)
        { if(tester->token.size()==1){cerr<<" impossible de derecursiver une regle d'un seul maillon";}
         //--------------------------------------------------------------------------------------
            for(vector<string> current:tester->token)
            {
                if(current[0]==tester->Nom)
                {
                    //transformer S = S alpha en S= BetaS'
                    //mettre regle S' = alpha S' | epsilon
                    //camille reprendre ici

                }
            }
        }
        else
            {Derecusive.List_Regle->push_back(tester);}
    }


    return Derecusive;
}

bool Camille::recusive(Regle tester)
{
    for(vector<string> ligne:tester.token)
    {
        for(string current:ligne)
        {
            if(current==tester.Nom)
            { return true;}
        }
    }

  return false;
}

}*/