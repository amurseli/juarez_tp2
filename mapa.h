#ifndef MAPA_H
#define MAPA_H
#include "archivo.h"
#include "matriz.h"
#include<string>

using namespace std;

class mapa : public archivo
{
private:
    int filas;
    int columnas;
    Matriz* matrizMapa;


public:
    mapa(string nombre);
    void leerArchivo(string nombre);
    void construirMatriz();
    ~mapa();
};

#endif
