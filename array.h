#ifndef ARRAY_H
#define ARRAY_H
#include <string>
#include <iostream>

using namespace std;

template<typename T>
class array
{
private:
    T* lista;
    T* auxiliarLista;
    T** puntero;
    int tamanio, dimensionAuxiliar;

    //Pre:Recibe un valor, es el tamanio de la lista
    //Post:Crea en el heap los bloques de memoria solicitada
    void crearMemoria();

    //Pre:Recibe el tamanio del array a eliminar
    //Post:Libera los bloques de memoria solicitados.
    void eliminarMemoria();

    //Pre:-
    //Post:agrega a lista los valores guardados en auxLista
    void transferenciaInformacion();


public:

     array();
     array(int filas, int columnas);

    //Pre:Recibe la cantidad de punteros que habra en el array.
    //Post:Genera un array de punteros.
    void crearMemoriaPunteros();

    //Pre:Recibe el elemento a agregar y la posicion donde se agregara en el array.
    //Post:agrega un elemento a la posicion pasada.
    void agregarElemento(T elemento);

    int devolverTamanio();
    //void cambiarElemento(string elemento,int posicion);


    T devolverElemento(int indice);

    ~array();

    //Pre:-
    //Post:Muestra la informacion almacenada
    void mostrarArray();

    void mostrarArrayPuntero();

    
};

template<typename T>
array<T>::array(){

    tamanio=0;

}

template<typename T>
array<T>::array(int filas, int columnas)
{
    tamanio = filas;
    dimensionAuxiliar=columnas;
    crearMemoriaPunteros();
}

template<typename T>
void array<T>::crearMemoriaPunteros()
{

    puntero = new T*[tamanio];

    for (int i = 0; i < tamanio-1; i++)
    {
      *puntero= new T[dimensionAuxiliar];       
    }

}

template<typename T>
void array<T>::agregarElemento(T elemento)
{
    tamanio += 1;
    crearMemoria();

    if (tamanio != 1)
        eliminarMemoria();

    lista[tamanio-1] = elemento;
}

template<typename T>
void array<T>::crearMemoria()
{
      
    if (tamanio != 1)
    {
        auxiliarLista = lista;
    }

    lista = new T[tamanio];    
    
}

template<typename T>
void array<T>::eliminarMemoria()
{
    transferenciaInformacion();
    delete[] auxiliarLista;
}

template<typename T>
void array<T>::transferenciaInformacion(){

    int tamanioArrayAux = tamanio -1;

    for (int i = 0; i < tamanioArrayAux; i++)
    {
        lista[i]=auxiliarLista[i];
    }
    
}

template<typename T>
int array<T>::devolverTamanio()
{
    return tamanio;
}

template<typename T>
T array<T>::devolverElemento(int indice)
{
    return lista[indice];
}


template<typename T>
void array<T>::mostrarArray(){
    
    for (int i = 0; i < tamanio; i++)
    {
        cout<<lista[i]<<endl;
    }
}

template<typename T>
void array<T>::mostrarArrayPuntero(){

    cout << "Entramos a imprimir" << endl;

    for (int i = 0; i < tamanio-1; i++)
    {
        for (int j = 0; j < dimensionAuxiliar; j++)
        {
            puntero[i][j]="A";
        }
    }

    for (int i = 0; i < tamanio-1; i++)
    {
        for (int j = 0; j < dimensionAuxiliar; j++)
        {
            cout<<puntero[i][j]<<endl;   
        }
    }

    cout << "finalizamos imprimir" << endl;
}

template<typename T>
array<T>::~array(){
    if (tamanio>0)
       delete [] lista;
    else
        delete lista;
}

#endif
