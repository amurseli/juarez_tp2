#ifndef EDIFICIOS_H
#define EDIFICIOS_H
#include "archivo.h"
#include "inventario.h"
#include <string>

using namespace std;

class Edificios : public Archivo
{

private:

    Inventario** inventarioTotal = NULL;
    int tamanio = 0;

public:
    Edificios(string nombre);

    //PRE:Necesita el nombre del archivo
    //POST:Si esta correcto lo lee guardando la informacion de acuerdo a cada edificio
    void leerArchivo(string nombre);

    //PRE:
    //POST:crea espacio de la memoria
    void crearContenidoInventario();

    //PRE:
    //POST:muestra por pantalla todos los edificios
    void listarTodosLosEdificios();

    //PRE:Necesita los datos del txt edificios
    //POST: agrega al inventario correspondiente la nueva informacion, el inventario es basicamente la informacion para la construccion de edifcios
    void agregarEnInventario(string nombreEdificio, string piedra, string madera, string metal, string maximaCantidadPermitidos);

    //PRE:Recibe el nombre de edificio
    //Devuelve true si el edificio existe
    bool validarEdificios(string nombre);

    //PRE:Necesita el nombre del edifico a construir
    //POST: devuelve el nombre del edificio
    string devolverNombreEdificio(int edificio);

    //PRE:Necesita el nombre del edifico
    //POST: devuelve la posicion en memoria de lel inventario que desea ver
    Inventario* devolverInventario(string edificio);

    //PRE:Necesita el nombre del edifcio
    //POST:retorna la posicion dentro del array inventario donde se encuentra el edificio requerido
    int buscarPosicionEnInventario(string edificio);

    //PRE:
    //POST: devuelve la posicion en memoria de si mismo
    Edificios* retornarPunteroEdificios();

    virtual ~Edificios();
};

#endif