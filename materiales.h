#ifndef MATERIALES_H
#define MATERIALES_H
#include "archivo.h"
#include <string>

using namespace std;

class Materiales : public Archivo
{
public:
    Materiales(string nombre);
    void leerArchivo(string nombre);
};

#endif
