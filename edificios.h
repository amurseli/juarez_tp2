#ifndef EDIFICIOS_H
#define EDIFICIOS_H
#include "archivo.h"
#include "inventario.h"
#include <string>

using namespace std;

class Edificios : public Archivo
{

private:

    Inventario** inventarioTotal;
    int tamanio = 0;

public:
    Edificios(string nombre);

    //PRE:Necesita el nombre del archivo
    //POST:Si esta correcto lo lee guardando la informacion de acuerdo a cada edificio
    void leerArchivo(string nombre);

    void crearContenidoInventario();

    void agregarEnInventario(string nombreEdificio, string piedra, string madera, string metal, string maximaCantidadPermitidos);

    //PRE:Recibe el nombre de un edificio
    //Devuelve un booleano para avisar si existe o no.
    bool validarEdificios(string nombre);

    string devolverNombreEdificio(int edificio);

    Inventario* devolverInventario(string edificio);

    int buscarPosicionEnInventario(string edificio);

    Edificios* retornarPunteroEdificios();

    ~Edificios();
};

#endif