#include "menu.h"
#include "matriz.h"
#include <iostream>

using namespace  std;

void mostrar_menu(){
    cout << "1. Construir edificios por nombre" << endl;
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

void procesar_opcion(Matriz* punteroMatriz, int opcion_elegida) {
    string aux;
    switch (opcion_elegida) {
        case CONSTRUIR_EDIFICIOS: //cambiar los nombres del switch en menu.h

            break;
        case MOSTRAR_EDIFICIOS_CONSTRUIDOS:

            break;
        case MOSTRAR_EDIFICIOS:

            break;
        case DEMOLER_EDIFICIO:

            break;
        case MOSTRAR_MAPA:

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

            break;
        case RECOLECTAR:

            break;
        case LLUVIA_DE_RECUROS:

            break;
        case SALIR:

            cout << "Adios!"<< endl;
            break;
        default:
            cout << "Error: opcion invalida";
    }
}

bool es_opcion_valida(int elegida) {
    return (elegida >= OPCION_MINIMA && elegida <= OPCION_MAXIMA);
}