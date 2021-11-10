#ifndef JUAREZ_TP2_UBICACIONES_H
#define JUAREZ_TP2_UBICACIONES_H

#include "archivo.h"
#include <string>
#include "matriz.h"
#include <string>
#include <iostream>

using namespace std;

class Ubicaciones : public Archivo
{
private:

    Matriz* punteroMatriz;

public:

    Ubicaciones(string nombre,Matriz* &matriz);

    void leerArchivo(string nombre);

    //Pre:
    //Post:Convierte el string leido del archivo en un int
    int arreglarCoordenadaX(string coordX);

    //Pre:
    //Post:Convierte el string leido del archivo en un int
    int arreglarCoordenadaY(string coordY);

    Ubicaciones* devolverPuntero();

    //Pre:
    //Post:Escribe los cambios en un archivo
    void escribirArchivo();

    virtual ~Ubicaciones();
};

#endif //JUAREZ_TP2_UBICACIONES_H
