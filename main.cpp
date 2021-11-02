#include <iostream>
#include<fstream>
#include<string>
#include"materiales.h"
#include "array.h"
#include"edificios.h"
#include"mapa.h"
#include"matriz.h"
#include"menu.h"
#include "ubicaciones.h"

using namespace std;

const string PATH_MATERIALES = "../materiales.txt";
const string PATH_EDIFICIOS = "../edificios.txt";
const string PATH_MAPA = "../mapa.txt";
const string PATH_UBICACIONES = "../ubicaciones.txt";

int main()
{
    Ubicaciones ubicacionesTxt(PATH_UBICACIONES);
    Materiales materialesTxt(PATH_MATERIALES);
    Edificios edificiosTxt(PATH_EDIFICIOS);
    Mapa mapaTxt(PATH_MAPA);

    Matriz* punteroOriginal; // Para trabajar con la matriz desde el main

    punteroOriginal = mapaTxt.retornarPunteroMatriz();

    cout << "Bienvenido a Andypolis!" << endl;

    int opcionElegida = -1;

    do
    {
        mostrarMenu();
        opcionElegida = elegirOpcion();

        if (!esOpcionValida(opcionElegida))
            mostrarMensajeError();

        else{

            procesarOpcion(punteroOriginal,opcionElegida,materialesTxt,edificiosTxt);
        }

    } while (opcionElegida != SALIR);
    

    /*;
    do{
        cout << "Escriba una opcion" << endl;
        mostrar_menu();
        cin >> opcion_elegida;
        while(!es_opcion_valida(opcion_elegida)){
            cout << "Ese numero de opcion no es valido, intentemos otra vez:"<< endl;
            mostrar_menu();
            cin >> opcion_elegida;
        }
        procesar_opcion(punteroOriginal,opcion_elegida,materialesTxt,edificiosTxt);
    }while(opcion_elegida != SALIR);*/




    return 0;
}

