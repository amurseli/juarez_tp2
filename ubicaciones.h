#ifndef JUAREZ_TP2_UBICACIONES_H
#define JUAREZ_TP2_UBICACIONES_H

#include "archivo.h"
#include <string>

using namespace std;

class Ubicaciones : public Archivo
{
private:
    int tamanio = 0;
public:
    Ubicaciones(string nombre);
    void leerArchivo(string nombre);
};

#endif //JUAREZ_TP2_UBICACIONES_H
