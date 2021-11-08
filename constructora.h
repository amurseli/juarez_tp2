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
    
    Constructora(Edificios* &edificioTxt,Materiales* &MaterialesTxt,Matriz* &matrizOriginal);

    void construirEdificio();

    void demolerEdificio();

    void avanzarConConstruccion(string nombreNuevoEdificio);

    void preguntarCoordenadas();

    bool validarMaximoEdificio(string nombreNuevoEdificio);

    bool validarMateriales(string nombreNuevoEdificio);

    bool confirmar(int piedraNecesaria, int maderaNecesaria, int metalNecesario);

    bool validarCoordenadas(int coord1, int coord2);

    bool ingresoDeCoordenadas();

    void restarMateriales(string nombreNuevoEdificio);

    void sumarMateriales(string nombreEdificio);

    void mostrarAvisoTerreno(bool aviso);

    bool terrenoVacio(string nombreEdificio);

    void mostrarAviso();




};


#endif //CONSTRUCTORA_H
