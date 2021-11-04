#include "menu.h"
#include "matriz.h"
#include <iostream>

using namespace std;

void mostrarMenu()
{
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

int elegirOpcion()
{

    int opcion_elegida;

    cout << "Ingrese su opcion: ";
    cin >> opcion_elegida;

    return (opcion_elegida);
}

void mostrarMensajeError()
{

    cout << "\nIngrese una opcion valida: " << endl;
}

bool validarEdificio(string edificio, Edificios &edificios)
{
    bool found = false;
    for (int i = 0; i < edificios.devolverTamanio(); i = i + 5)
    {
        if (edificio == edificios.devolverElemento(i))
        {
            found = true;
        }
    }
    return found;
}

void correrFuncion(Matriz *&punteroMatriz, int opcion_elegida, Materiales &materiales, Edificios &edificios)
{
    string nombreNuevoEdificio;
    bool entradaValida = false;
    int coord1, coord2;

    cout << "Ingrese el nombre del nuevo edificio: ";
    cin >> nombreNuevoEdificio;
    entradaValida = validarEdificio(nombreNuevoEdificio, edificios);
    while (!entradaValida)
    {
        cout << "Ingrese el nombre del nuevo edificio: ";
        cin >> nombreNuevoEdificio;
        entradaValida = validarEdificio(nombreNuevoEdificio, edificios);

        if (nombreNuevoEdificio == "0")
            entradaValida = true;
    }

    cout << "Ingrese la primer coordenada: ";
    cin >> coord1;
    cout << endl
         << "Ingrese la segunda coordenada: ";
    cin >> coord2;
    punteroMatriz->construirEdificio(coord1 - 1, coord2 - 1, nombreNuevoEdificio);
}

void procesarOpcion(Matriz *&punteroMatriz, int opcion_elegida, Materiales &materiales, Edificios &edificios)
{
    string aux;
    string nombreNuevoEdificio;
    bool entradaValida = false;
    int coord1, coord2;
    switch (opcion_elegida)
    {
    case CONSTRUIR_EDIFICIOS:
        edificios.mostrarContenido();
        correrFuncion(Matriz * &punteroMatriz, int opcion_elegida, Materiales &materiales, Edificios &edificios); //chequar
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
        cout << "Ingrese la primer coordenada: ";
        cin >> coord1;
        cout << endl
             << "Ingrese la segunda coordenada: ";
        cin >> coord2;
        punteroMatriz->mostrarCoordenada(coord1 - 1, coord2 - 1);
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

        cout << "Adios!" << endl;
        break;
    default:
        cout << "Error: opcion invalida";
    }
}

bool esOpcionValida(int elegida)
{
    return (elegida >= OPCION_MINIMA && elegida <= OPCION_MAXIMA);
}
