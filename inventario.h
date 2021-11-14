#ifndef INVENTARIO_H
#define INVENTARIO_H
#include <string>
#include <iostream>

using namespace std;

class Inventario
{
private:
    string nombreEdificio;
    int piedraNecesaria, maderaNecesaria, metalNecesario, maximaCantidadPermitidos;
public:

    Inventario(string nombre, int piedra, int madera, int metal, int maximaCantidadPermitidos);

    string devolverNombre();

    int devolverPiedra();

    int devolverMadera();

    int devolverMetal();

    //Pre:
    //Post: Devuelve los datos de todos los edificos
    void devolverEdificios();

    int devolverMaximaCantidadPermitidos();

    //Pre:
    //Post:Devuelve un puntero al array
    Inventario* devolverMemoria();

    ~Inventario();
};



#endif