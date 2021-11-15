#include "menu.h"
#include "matriz.h"
#include "mapa.h"
#include <iostream>

using namespace std;

Menu::Menu()
{
    punteroMateriales = new Materiales(PATH_MATERIALES);
    punteroEdificios = new Edificios(PATH_EDIFICIOS);
    punteroMapa = new Mapa(PATH_MAPA);
    punteroMatriz = punteroMapa->retornarPunteroMatriz();
}

void Menu::leerUbicaciones()
{
    if (punteroMapa->getArchivoValido())
    {
        punteroUbicaciones = new Ubicaciones(PATH_UBICACIONES, punteroMatriz);
    }
}

void Menu::crearConstructora()
{
    punteroConstructora = new Constructora(punteroEdificios, punteroMateriales, punteroMatriz);
}

int Menu::validarArranque()
{

    int valor = SALIR;

    if (punteroMapa->getArchivoValido() && punteroEdificios->getArchivoValido() && punteroMateriales->getArchivoValido())
    {
        valor = ENTRAR;
    }
    return valor;
}

void Menu::mostrarMenu()
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

int Menu::elegirOpcion()
{

    int opcion_elegida;

    cout << "Ingrese su opcion: ";
    cin >> opcion_elegida;

    return (opcion_elegida);
}

void Menu::mostrarMensajeError()
{

    cout << "\nIngrese una opcion valida: " << endl;
}

void Menu::procesarOpcion(int opcion_elegida) //cambiarle el nombre al puntero constructora xd
{
    string aux;
    string nombreNuevoEdificio;

    switch (opcion_elegida)
    {
    case CONSTRUIR_EDIFICIOS:
        cout << endl;
        punteroConstructora->construirEdificio();
        break;
    case MOSTRAR_EDIFICIOS_CONSTRUIDOS:
        punteroMatriz->mostrarEdificiosConstruidos();
        break;
    case MOSTRAR_EDIFICIOS:
        punteroEdificios->listarTodosLosEdificios();
        break;
    case DEMOLER_EDIFICIO:
        punteroConstructora->demolerEdificio();
        break;
    case MOSTRAR_MAPA:
        punteroMatriz->mostrarMatriz();
        break;
    case CONSULTAR_COORDENADA:
        coordenadasConsultar();
        break;
    case MOSTRAR_INVENTARIO:
        punteroMateriales->mostrarMateriales();
        break;
    case RECOLECTAR:
        punteroMatriz->recoletarMateriales(punteroMateriales);
        break;
    case LLUVIA_DE_RECUROS:
        punteroMatriz->generarLluviaMateriales();
        break;
    case SALIR:
        punteroMateriales->escribirArchivo();
        punteroUbicaciones->escribirArchivo();
        cout << "Adios!" << endl;
        break;
    default:
        cout << "Error: opcion invalida";
    }
}

bool Menu::esOpcionValida(int elegida)
{
    return (elegida >= OPCION_MINIMA && elegida <= OPCION_MAXIMA);
}

void Menu::coordenadasConsultar()
{
    int coord1, coord2;

    cout << "Ingrese fila: ";
    cin >> coord1;
    cout << endl
         << "Ingrese la columna: ";
    cin >> coord2;
    while (coord1 > punteroMatriz->devolverMaxFil() - 1 || coord2 > punteroMatriz->devolverMaxCol() - 1 || coord1 < 0 || coord2 < 0)
    {
        cout << "Fila -> (0, " << punteroMatriz->devolverMaxFil() - 1 << ") Columna -> (0, " << punteroMatriz->devolverMaxCol() - 1 << ")" << endl;
        cout << "Ingrese fila: ";
        cin >> coord1;
        cout << endl
             << "Ingrese la columna: ";
        cin >> coord2;
    }
    punteroMatriz->mostrarCoordenada(coord1 - 1, coord2 - 1);
}

Menu::~Menu()
{
    delete punteroConstructora;
    delete punteroMapa;
    delete punteroEdificios;
    delete punteroMateriales;
    delete punteroUbicaciones;
}
