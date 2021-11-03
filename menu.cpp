#include "menu.h"
#include "matriz.h"
#include <iostream>

using namespace  std;

void mostrarMenu(){
    cout << "\n1. Construir edificios por nombre" << endl;
    cout << "2. Listar los edificios construidos " << endl;
    cout << "3. Listar todos los edificios " << endl;
    cout << "4. Demoler un edificio por coordenada " << endl;
    cout << "5. Mostrar mapa" << endl;
    cout << "6. Consultar coordenada " << endl;
    cout << "7. Mostrar inventario " << endl;
    cout << "8. Recolectar recursos producidos " << endl;
    cout << "9. Lluvia de recursos" << endl;
    cout << "10. Guardar y Salir" << endl;

}

int elegirOpcion(){

    int opcion_elegida;

    cout << "Ingrese su opcion: ";
    cin >> opcion_elegida;

    return (opcion_elegida);
}

void mostrarMensajeError(){

    cout << "\nIngrese una opcion valida: " << endl;

}

void procesarOpcion(Matriz* &punteroMatriz, int opcion_elegida, Materiales &materiales, Edificios &edificios) {
    string aux;
    switch (opcion_elegida) {
        case CONSTRUIR_EDIFICIOS: //cambiar los nombres del switch en menu.h
            cout << "Soy la opcion 1" << endl;
            break;
        case MOSTRAR_EDIFICIOS_CONSTRUIDOS:
            cout << "Soy la opcion 2" << endl;
            break;
        case MOSTRAR_EDIFICIOS:
            edificios.mostrarContenido();
            break;
        case DEMOLER_EDIFICIO:
            cout << "Soy la opcion 4" << endl;
            break;
        case MOSTRAR_MAPA:
            cout << "Soy la opcion 5" << endl;
            break;
        case CONSULTAR_COORDENADA:
            int coord1, coord2;
            cout <<"Ingrese la primer coordenada: ";
            cin >> coord1 ;
            cout << endl << "Ingrese la segunda coordenada: ";
            cin >> coord2;
            punteroMatriz->mostrarCoordenada(coord1-1,coord2-1);
            break;
        case MOSTRAR_INVENTARIO:
            materiales.mostrarContenido();
            break;
        case RECOLECTAR:
            cout << "Soy la opcion 8" << endl;
            break;
        case LLUVIA_DE_RECUROS:
            punteroMatriz->generarLluviaMateriales();
            break;
        case SALIR:

            cout << "Adios!"<< endl;
            break;
        default:
            cout << "Error: opcion invalida";
    }
}

bool esOpcionValida(int elegida) {
    return (elegida >= OPCION_MINIMA && elegida <= OPCION_MAXIMA);
}