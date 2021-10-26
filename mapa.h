#ifndef MAPA_H
#define MAPA_H
#include "archivo.h"
#include<string>

using namespace std;

class mapa : public archivo
{
private:
    int ancho;
    int alto;

public:
    mapa(string nombre);
    void leerArchivo(string nombre);
    int devolverAncho();
    int devolverAlto();
};

#endif
