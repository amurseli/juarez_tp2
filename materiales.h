#ifndef MATERIALES_H
#define MATERIALES_H
#include "archivo.h"
#include <string>

using namespace std;

class Materiales : public Archivo
{
private:
    int tamanio = 0;
    int piedra;
    int madera;
    int metal;
public:
    Materiales(string nombre);
    void leerArchivo(string nombre);
    void guardarDatos(string nombreMaterial, string cantidad);
    int devolverPiedra();
    int devolverMadera();
    int devolverMetal();
    void mostrarMateriales();
};

#endif
