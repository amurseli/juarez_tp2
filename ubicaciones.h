#ifndef JUAREZ_TP2_UBICACIONES_H
#define JUAREZ_TP2_UBICACIONES_H

#include "archivo.h"
#include <string>
#include "matriz.h"
#include <string>

using namespace std;

class Ubicaciones : public Archivo
{
private:

    Matriz* punteroMatriz;

public:

    Ubicaciones(string nombre,Matriz* &matriz);

    
    void leerArchivo(string nombre);

    int arreglarCoordenadaX(string coordX);

    int arreglarCoordenadaY(string coordY);

    void escribirArchivo();
};

#endif //JUAREZ_TP2_UBICACIONES_H
