#include "menu.h"
#include "matriz.h"
#include <iostream>

using namespace std;

int validarArranque(Ubicaciones &ubicacionesTxt,Materiales &materialesTxt,Edificios &edificiosTxt){

    int valor = SALIR;

    if(ubicacionesTxt.getArchivoValido() && materialesTxt.getArchivoValido() && edificiosTxt.getArchivoValido()){
        valor = ENTRAR;
    }
    return valor;
}

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

void procesarOpcion(Matriz *&punteroMatriz, int opcion_elegida, Materiales &materiales, Edificios &edificios, Constructora &prueba)
{
    string aux;
    string nombreNuevoEdificio;
    int coord1, coord2;
    
    switch (opcion_elegida)
    {
    case CONSTRUIR_EDIFICIOS:
        prueba.construirEdificio();
        break;
    case MOSTRAR_EDIFICIOS_CONSTRUIDOS:
        punteroMatriz->mostrarEdificiosConstruidos();
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
        punteroMatriz->mostrarCoordenada(coord1, coord2);
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
