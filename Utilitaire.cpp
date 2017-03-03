//
// Created by mathieu on 03/03/2017.
//

#include "include.h"


void Utilitaire::debug(string text)
{
    if(DEBUG ==true)
    {
        cout<< text;
    }
}
void Utilitaire::debugln(string text)
{
    if(DEBUG ==  true)
    {
        cout<< text<<endl;
    }
}