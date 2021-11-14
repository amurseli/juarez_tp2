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
    Matriz* matrizMapa = NULL;


public:
    Mapa(string nombre);

    //Pre:
    //Post:Lee el archivo y actualiza los atributos
    void leerArchivo(string nombre);

    //Pre:
    //Post:LLama al constructor de la clase matriz
    void construirMatriz();

    //Pre:
    //Post:Devuelve la direccion de memoria de la matriz.
    Matriz* retornarPunteroMatriz();
    
    virtual ~Mapa();
};

#endif
