#ifndef EDIFICIOS_H
#define EDIFICIOS_H
#include"archivo.h"
#include<string>

using namespace std;

class Edificios : public Archivo
{

public:
    Edificios(string nombre);
    void leerArchivo(string nombre);
    void validarEdificio(string edificio);


};


#endif