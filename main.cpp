#include <iostream>
#include<fstream>
#include<string>
#include"materiales.h"
#include "array.h"
#include"edificios.h"
#include"mapa.h"
#include"matriz.h"
#include"menu.h"
using namespace std;

const string PATH_MATERIALES = "../materiales.txt";
const string PATH_EDIFICIOS = "../edificios.txt";
const string PATH_MAPA = "../mapa.txt";

int main()
{
    Matriz* punteroOriginal; // Para trabajar con la matriz desde el main

    Mapa prueba(PATH_MAPA);

    punteroOriginal = prueba.retornarPunteroMatriz();

    cout << "Bienvenido a Andypolis!" << endl;

    int opcion_elegida;
    do{
        cout << "Escriba una opcion" << endl;
        mostrar_menu();
        cin >> opcion_elegida;
        while(!es_opcion_valida(opcion_elegida)){
            cout << "Ese numero de opcion no es valido, intentemos otra vez:"<< endl;
            mostrar_menu();
            cin >> opcion_elegida;
        }
        procesar_opcion(punteroOriginal,opcion_elegida);
    }while(opcion_elegida != SALIR);




    return 0;
}

