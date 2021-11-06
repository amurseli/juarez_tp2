#ifndef MATERIALES_H
#define MATERIALES_H
#include "archivo.h"
#include <string>

using namespace std;

const string MADERA = "madera";
const string PIEDRA = "piedra";
const string METAL = "metal";

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
    void agregarMaterial(string material, int cantidad);
    void sumarPiedra(int cantidad);
    void sumarMadera(int cantidad);
    void sumarMetal(int cantidad);
    void restarPiedra(int cantidad);
    void restarMadera(int cantidad);
    void restarMetal(int cantidad);
    void mostrarMateriales();
    bool validarMateriales(int piedraNecesaria, int maderaNecesaria, int metalNecesario);
    Materiales* devolverDireccionMemoria();
};

#endif
