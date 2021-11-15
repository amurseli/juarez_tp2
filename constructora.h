#ifndef CONSTRUCTORA_H
#define CONSTRUCTORA_H
#include <iostream>
#include "edificios.h"
#include "matriz.h"
#include "materiales.h"

#include <string>

using namespace std;

const string CONFIRMADO = "s";
const string NO_CONFIRMADO = "n";

class Constructora
{
private:

    Edificios* edificios = NULL;
    Materiales* materiales = NULL;
    Matriz* matriz = NULL;

    int filaParaTrabajar;
    int columnaParaTrabajar;

public:
    
    //PRE:Necesita la posicion de memoria de edificios, materiales y matriz
    //POST:  Vincula los punteros edificios, material y matriz a los originales creados.
    Constructora(Edificios* &edificioTxt,Materiales* &MaterialesTxt,Matriz* &matrizOriginal);

    //PRE:
    //POST: Empieza las validaciones para contruir el edificio
    void construirEdificio();

    //PRE:
    //POST: EMpieza las validaciones para demoles el edificio
    void demolerEdificio();

    //PRE:Necesita el nombre del edifico a construir
    //POST: Contruye el edificio
    void avanzarConConstruccion(string nombreNuevoEdificio);

    //PRE:
    //POST: Pregunta las coordenadas al usuario y las valida
    void preguntarCoordenadas();

    //PRE:Necesita el nombre del edifico a construir
    //POST: devuelve true si aun no se ha llegado al maximo de edificios
    bool validarMaximoEdificio(string nombreNuevoEdificio);

    //PRE:Necesita el nombre del edifico a construir
    //POST: Devuelve true si hay materiales disponibles
    bool validarMateriales(string nombreNuevoEdificio);

    //PRE:Necesita los maeriales que se utilizaran
    //POST: le muestra al usuario como quedara su inventario y le pide confirmar
    bool confirmar(int piedraNecesaria, int maderaNecesaria, int metalNecesario);

    //PRE:Necesita 2 coordenadas
    //POST: Devuelve true si las coordenadas son correctas
    bool validarCoordenadas(int coord1, int coord2);

    //PRE:
    //POST: devuelve true si el ingreso de coordenadas fue valido.
    bool ingresoDeCoordenadas();

    //PRE:Necesita el nombre del edifico a construir
    //POST: resta los materiales una vez confirmada la construccion
    void restarMateriales(string nombreNuevoEdificio);

    //PRE:Necesita el nombre del edifico a construir
    //POST: Suma los materiales una vez confirmada la destruccion
    void sumarMateriales(string nombreEdificio);

    //PRE:Necesita un bool de que es un terreno construible o no
    //POST: muestra el aviso si el terreno no es construible
    void mostrarAvisoTerreno(bool aviso);

    //PRE:Necesita el nombre del edifico a construir
    //POST: devuelve true si no hay nada en el terreno
    bool terrenoVacio(string nombreEdificio);

    //PRE:
    //POST: muestra por pantalla que esta errado
    void mostrarAviso();

};


#endif //CONSTRUCTORA_H
