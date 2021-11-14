#ifndef CASILLEROCONSTRUIBLE_H
#define CASILLEROCONSTRUIBLE_H
#include <string>
#include <iostream>
#include "casillero.h"
#include "obelisco.h"
#include "mina.h"

using namespace std;

const string MINA = "mina";
const string ASERRADERO = "aserradero";
const string FABRICA = "fabrica";
const string ESCUELA = "escuela";
const string OBELISCO = "obelisco";
const string PLANTA_ELECTRICA = "planta electrica";  
const int CONSTRUIR = 1;
const int DEMOLER = 2;

class CasilleroConstruible : public Casillero //debe heredar de casillero.h
{
private:

    Edificio* punteroEdificio = nullptr;
    int posicionX,posicionY;

public:

    //PRE:Recibe el elemento de la casilla y la posicion para guardarla.
    //Post:guarda las posiciones en la variable correspondientes.
    CasilleroConstruible(string elemento,int posicionX, int posicionY);
    
    //PRE:
    //Post:Dice que tipo de casillero es y si hay algo llama a su edificio para que hable.
    void queSoy();

    //PRE:
    //Post:Dice que tipo de casillero es y si hay algo llama a su edificio para que hable.
    void mostrarContenido();

    //PRE:Recibe el edificio a agregar
    //Post:Agrega el edificio a la casilla correspondiente.
    void modificarTerreno(string nombreEdificio, int opcion);

    //PRE:Recibe el nombre del edificio.
    //Post:crear una instancia en el heap de un edificio y lo vincula al punteroEdificio.
    void crearEdificio(string nombreEdificio);

    //PRE:
    //Post:Elimina la direccion de memoria del edificio y apunta a nullptr el punteroEdificio.
    void removerEdificio();

    //PRE:
    //Post: imprime por pantalla sus coordenadas.
    void devolverPosicion();

    //PRE:Recibe una copia de materiales.  
    //Post: Le suma lo recolectado por edificio construido.
    void recolectar(Materiales* &materiales);

    //PRE:
    //Post:devuelve 0 porque no hay materiales en este casillero.
    string mostrarMaterial();

    //PRE:
    //Post:Si tiene un edificio, devuelve el nombre del edificio.
    string mostrarEdificio();

    //PRE:
    //POST:Borra la direccion de memoria solicitada en ubicaciones.cpp.
    virtual ~CasilleroConstruible();
   
};

#endif