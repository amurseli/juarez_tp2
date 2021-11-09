#include "menu.h"
#include "matriz.h"
#include "mapa.h"
#include <iostream>

using namespace std;

Menu::Menu() {
    Materiales materialesTxt(PATH_MATERIALES);
    Edificios edificiosTxt(PATH_EDIFICIOS);
    Mapa mapaTxt(PATH_MAPA);

    Edificios* direccionMemoria;
    Materiales* direccionMemoriaMateriales;
    Matriz *punteroOriginal; // Para trabajar con la matriz desde el main
    Constructora* punteroConstructora = NULL;
    Ubicaciones* punteroUbicaciones;

    direccionMemoria = edificiosTxt.retornarPunteroEdificios();
    punteroOriginal = mapaTxt.retornarPunteroMatriz();
    direccionMemoriaMateriales= materialesTxt.devolverDireccionMemoria();

    Ubicaciones ubicacionesTxt(PATH_UBICACIONES, punteroOriginal);

    punteroUbicaciones = ubicacionesTxt.devolverPuntero();

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

            procesarOpcion(punteroOriginal, opcionElegida, materialesTxt, edificiosTxt, punteroConstructora, punteroUbicaciones);
        }
    }

    if(punteroConstructora != nullptr)
        delete punteroConstructora;
}

int Menu::validarArranque(Ubicaciones &ubicacionesTxt,Materiales &materialesTxt,Edificios &edificiosTxt){

    int valor = SALIR;

    if(ubicacionesTxt.getArchivoValido() && materialesTxt.getArchivoValido() && edificiosTxt.getArchivoValido()){
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

void Menu::procesarOpcion(Matriz *&punteroMatriz, int opcion_elegida, Materiales &materiales, Edificios &edificios, Constructora* &prueba, Ubicaciones* &ubicaciones) //cambiarle el nombre al puntero constructora xd
{
    string aux;
    string nombreNuevoEdificio;
    int coord1, coord2;
    
    switch (opcion_elegida){
    case CONSTRUIR_EDIFICIOS:
        cout << endl;
        prueba->construirEdificio();
        break;
    case MOSTRAR_EDIFICIOS_CONSTRUIDOS:
        punteroMatriz->mostrarEdificiosConstruidos();
        break;
    case MOSTRAR_EDIFICIOS:
        edificios.listarTodosLosEdificios();
        break;
    case DEMOLER_EDIFICIO:
        prueba->demolerEdificio();
        break;
    case MOSTRAR_MAPA:
        punteroMatriz->mostrarMatriz();
        break;
    case CONSULTAR_COORDENADA:
        
        cout << "Ingrese fila: ";
        cin >> coord1;
        cout << endl
             << "Ingrese la columna: ";
        cin >> coord2;
        while(coord1 > punteroMatriz->devolverMaxFil()-1 || coord2 > punteroMatriz->devolverMaxCol()-1 || coord1 < 0 || coord2 < 0)
        {
            cout << "Fila -> (0, " <<  punteroMatriz->devolverMaxFil() -1 <<") Columna -> (0, " << punteroMatriz->devolverMaxCol() -1 << ")" << endl;
            cout << "Ingrese fila: ";
            cin >> coord1;
            cout << endl
                 << "Ingrese la columna: ";
            cin >> coord2;
        }
        punteroMatriz->mostrarCoordenada(coord1-1, coord2-1);
        break;
    case MOSTRAR_INVENTARIO:
        materiales.mostrarMateriales();
        break;
    case RECOLECTAR:
        punteroMatriz->recoletarMateriales(materiales);
        break;
    case LLUVIA_DE_RECUROS:
        punteroMatriz->generarLluviaMateriales();
        break;
    case SALIR:
        materiales.escribirArchivo();
        ubicaciones->escribirArchivo();
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
