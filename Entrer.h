//
// Created by mathieu on 03/03/2017.
//

#ifndef L3_LC_F5_LANGUAGE_COMPILATION_PARSER_H
#define L3_LC_F5_LANGUAGE_COMPILATION_PARSER_H
#include <iostream>
#include <vector>

using namespace std;

class Entrer {
public :

    static string lirestr(FILE *file);
    static vector<string> lecture(const char * adresse);


private:

};


#endif //L3_LC_F5_LANGUAGE_COMPILATION_PARSER_H
