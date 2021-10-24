#include<string>
#include<iostream>
#include "array.h"

using namespace std;


array::array(){

    tamanio=0;

}

void array::agregarElemento(string elemento)
{
    tamanio += 1;

    crearMemoria();

    if (tamanio != 1)
        eliminarMemoria();

    lista[tamanio-1] = elemento;


}

void array::crearMemoria()
{
      
    if (tamanio != 1)
    {
        auxiliarLista = lista;
    }

    lista = new string[tamanio];   
    
}

void array::eliminarMemoria()
{
    transferenciaInformacion();
    delete[] auxiliarLista;
}

void array::transferenciaInformacion(){

    int tamanioArrayAux = tamanio -1;

    for (int i = 0; i < tamanioArrayAux; i++)
    {
        lista[i]=auxiliarLista[i];
    }
    
}

void array::mostrarArray(){
    
    for (int i = 0; i < tamanio; i++)
    {
        cout<<lista[i]<<endl;
    }
}

array::~array(){
    if (tamanio>0)
       delete [] lista;
}