#ifndef INVENTARIO_H
#define INVENTARIO_H
#include <string>
#include <iostream>

using namespace std;

class Inventario
{
private:
    string nombreEdificio;
    int piedraNecesaria, maderaNecesaria, metalNecesario, maximaCantidadPermitidos, construidos;
public:
    Inventario(string nombre, int piedra, int madera, int metal, int maximaCantidadPermitidos);

    string devolverNombre();

    int devolverPiedra();

    int devolverMadera();

    int devolverMetal();

    void devolverEdificios();

    int devolverMaximaCantidadPermitidos();

    Inventario* devolverMemoria();

    ~Inventario();
};



#endif