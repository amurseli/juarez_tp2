#ifndef MATERIALES_H
#define MATERIALES_H
#include"archivo.h"
#include<string>

using namespace std;

class materiales : public archivo
{
public:
    using archivo::archivo;
    void leerArchivo(string nombre);
};


#endif
