#ifndef ARRAY_H
#define ARRAY_H
#include <string>

using namespace std;

class array
{
private:
    string* lista;
    string* auxiliarLista;
    int tamanio;   

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

    //Pre:Recibe el elemento a agregar y la posicion donde se agregara en el array.
    //Post:agrega un elemento a la posicion pasada.
    void agregarElemento(string elemento);

    //void cambiarElemento(string elemento,int posicion);

    ~array();

    //Pre:-
    //Post:Muestra la informacion almacenada
    void mostrarArray();

    
};

#endif
