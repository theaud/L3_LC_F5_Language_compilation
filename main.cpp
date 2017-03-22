#include <vector>
#include "include.h"
#include "Regle.h"
#include "Entrer.h"
#include "Grammaire.h"

int main() {





    Entrer a;
    a.lecture("F5G0.txt");

    Grammaire(a.Texte);

    Grammaire("F5G0.txt");

    return 0;
}