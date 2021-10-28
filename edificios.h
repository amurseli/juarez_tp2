#ifndef EDIFICIOS_H
#define EDIFICIOS_H
#include"archivo.h"
#include<string>

using namespace std;

class edificios : public archivo
{
public:
    edificios(string nombre);
    void leerArchivo(string nombre);
};


#endif