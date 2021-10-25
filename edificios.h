#ifndef EDIFICIOS_H
#define EDIFICIOS_H
#include"archivo.h"
#include<string>

using namespace std;

class edificios : public archivo
{
public:

    using archivo::archivo;
    void leerArchivo(string nombre);
};


#endif