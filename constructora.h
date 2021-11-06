#ifndef CONSTRUCTORA_H
#define CONSTRUCTORA_H
#include <iostream>
#include "edificios.h"
#include "matriz.h"
#include "materiales.h"

#include <string>

using namespace std;

class Constructora
{
private:

    Edificios* edificios = NULL;
    Materiales* materiales = NULL;
    Matriz* matriz = NULL;

public:
    
    Constructora(Edificios* &edificioTxt,Materiales* &MaterialesTxt,Matriz* &matrizOriginal);

    void construirEdificio();

    void preguntarCoordenadas();

    void validarMateriales(string nombreNuevoEdificio);

    bool confirmar(int piedraNecesaria, int maderaNecesaria, int metalNecesario);

    void validarCoordenadas(int coord1, int coord2);

    void ingresoDeCoordenadas(string nombreNuevoEdificio);

    void mostrarAviso();




};


#endif //CONSTRUCTORA_H
