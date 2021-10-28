#ifndef MATERIALES_H
#define MATERIALES_H
#include "archivo.h"
#include <string>

using namespace std;

class materiales : public archivo
{
public:
    materiales(string nombre);
    void leerArchivo(string nombre);
};

#endif
