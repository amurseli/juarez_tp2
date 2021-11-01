#ifndef MAPA_H
#define MAPA_H
#include "archivo.h"
#include "matriz.h"
#include<string>

using namespace std;

class Mapa : public Archivo
{
private:
    int filas;
    int columnas;
    Matriz* matrizMapa;


public:
    Mapa(string nombre);
    void leerArchivo(string nombre);
    void construirMatriz();

    //Pre:
    //Post:Devuelve la direccion de memoria de la matriz.
    Matriz* retornarPunteroMatriz();
    
    ~Mapa();
};

#endif
