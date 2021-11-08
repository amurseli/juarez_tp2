#include <iostream>
#include <string>
#include "materiales.h"
#include "edificios.h"
#include "mapa.h"
#include "menu.h"

using namespace std;

int main()
{
    Materiales materialesTxt(PATH_MATERIALES);
    Edificios edificiosTxt(PATH_EDIFICIOS);
    Mapa mapaTxt(PATH_MAPA);

    Edificios* direccionMemoria;
    Materiales* direccionMemoriaMateriales;
    Matriz *punteroOriginal; // Para trabajar con la matriz desde el main
    Constructora* punteroConstructora = NULL;

    direccionMemoria = edificiosTxt.retornarPunteroEdificios();
    punteroOriginal = mapaTxt.retornarPunteroMatriz();
    direccionMemoriaMateriales= materialesTxt.devolverDireccionMemoria();

    Ubicaciones ubicacionesTxt(PATH_UBICACIONES, punteroOriginal);

    int opcionElegida = validarArranque(ubicacionesTxt, materialesTxt, edificiosTxt);

    if(opcionElegida){
        punteroConstructora = new Constructora(direccionMemoria,direccionMemoriaMateriales,punteroOriginal); 
        cout << "Bienvenido a Andypolis!" << endl;
    }
    

    while (opcionElegida != SALIR)
    {
        mostrarMenu();
        opcionElegida = elegirOpcion();

        if (!esOpcionValida(opcionElegida))
            mostrarMensajeError();
        else
        {   
            
            procesarOpcion(punteroOriginal, opcionElegida, materialesTxt, edificiosTxt, punteroConstructora);
        }
    }

    if(punteroConstructora !=NULL)
        delete punteroConstructora;

    return 0;
}
