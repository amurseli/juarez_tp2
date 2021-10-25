#ifndef MAPA_H
#define MAPA_H
#include "archivo.h"
#include<string>

using namespace std;

class mapa : public archivo
{
public:
    mapa(string nombre);
    void leerArchivo(string nombre);
};

#endif
