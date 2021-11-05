#include <iostream>
#include <fstream>
#include <string>
#include "materiales.h"
#include "array.h"
#include "edificios.h"
#include "mapa.h"
#include "matriz.h"
#include "menu.h"
#include "menu.h"
#include "ubicaciones.h"
#include "constructora.h"

using namespace std;

const string PATH_MATERIALES = "materiales.txt";
const string PATH_EDIFICIOS = "edificios.txt";
const string PATH_MAPA = "mapa.txt";
const string PATH_UBICACIONES = "ubicaciones.txt";

int main()
{
    Materiales materialesTxt(PATH_MATERIALES);
    Edificios edificiosTxt(PATH_EDIFICIOS);
    Mapa mapaTxt(PATH_MAPA);

    Edificios* direccionMemoria;
    Materiales* direccionMemoriaMateriales;
    Matriz *punteroOriginal; // Para trabajar con la matriz desde el main

    direccionMemoria = edificiosTxt.retornarPunteroEdificios();
    punteroOriginal = mapaTxt.retornarPunteroMatriz();
    direccionMemoriaMateriales= materialesTxt.devolverDireccionMemoria();

    Ubicaciones ubicacionesTxt(PATH_UBICACIONES, punteroOriginal);

    cout << "Bienvenido a Andypolis!" << endl;

    int opcionElegida = validarArranque(ubicacionesTxt, materialesTxt, edificiosTxt);

    Constructora prueba(direccionMemoria,direccionMemoriaMateriales,punteroOriginal); //crear cuando se haya validado

    while (opcionElegida != SALIR)
    {
        mostrarMenu();
        opcionElegida = elegirOpcion();

        if (!esOpcionValida(opcionElegida))
            mostrarMensajeError();
        else
        {
            procesarOpcion(punteroOriginal, opcionElegida, materialesTxt, edificiosTxt, prueba);
        }
    }

    return 0;
}
