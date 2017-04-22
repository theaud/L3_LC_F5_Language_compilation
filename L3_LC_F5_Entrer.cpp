//
// Created by mathieu on 03/03/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include "L3_LC_F5_Entrer.h"
#include "L3_LC_F5_Grammaire.h"



string L3_LC_F5_Entrer::lirestr(FILE *file)
{
    char temp[1000];
    fgets(temp,1000,file);
    if(char *index = strchr(temp,'\n')) *index = 0;
    char *str = (char*)malloc(sizeof(char)*(strlen(temp)+1));
    strcpy(str,temp);
    return str;
}


vector<string> L3_LC_F5_Entrer::lecture(const char * addresse)
{
    vector<string> Texte;
    fstream fichier(addresse);

    if ( !fichier )
    { cout << "fichier inexistant";}
    else
    { bool continuer = true;

        while( !fichier.eof() )
        {
            Texte.push_back("");//creation d'une ligne vide
            getline(fichier, Texte.back());//lecture d'une ligne du fichier
            int ligne = Texte.size() - 1;//je recupere la taille du tableau (-1 pour la ligne 0)

            if(Texte[ligne].empty())//si la ligne est vide
                Texte.pop_back();//on la retire du tableau
        }
    }


    return Texte;
 }

