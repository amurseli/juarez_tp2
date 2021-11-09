#include "inventario.h"

Inventario::Inventario(string nombre, int piedra, int madera, int metal, int maximaCantidad){

    nombreEdificio = nombre;
    piedraNecesaria = piedra;
    maderaNecesaria = madera;
    metalNecesario = metal;
    maximaCantidadPermitidos = maximaCantidad;
}

string Inventario::devolverNombre(){

    return nombreEdificio;
}

int Inventario::devolverPiedra(){

    return piedraNecesaria;
}

int Inventario::devolverMadera(){

    return maderaNecesaria;
}

int Inventario::devolverMetal(){

    return metalNecesario;
}

int Inventario::devolverMaximaCantidadPermitidos(){

    return (maximaCantidadPermitidos);
}

void Inventario::devolverEdificios(){

    cout << "\n..::" << nombreEdificio <<endl;
    cout << ">Cantidad de piedra necesaria: " << piedraNecesaria << endl;
    cout << ">Cantidad de madera necesaria: " << maderaNecesaria << endl;
    cout << ">Cantidad de metal necesaria: " << metalNecesario << endl;
}

Inventario* Inventario::devolverMemoria(){

    return(this);
}

Inventario::~Inventario(){}
