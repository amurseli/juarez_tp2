#include <iostream>
#include "matriz.h"

using namespace std;

Matriz::Matriz(int ancho, int alto, array *&contenido) {
    columnas = new array<string>(ancho);
    for (int i = 0; i < ancho; ++i) {
        //columnas->agregarElemento("a");
    }
    tamanio = columnas->devolverTamanio();
    //cout<<tamanio<<endl;
//contenido->devolverElemento(i)
    cout<<columnas->devolverElemento(0)<<endl;
}

void Matriz::agregarElementoArrayMatriz(string elemento)
{

}

Matriz::~Matriz() {

}

