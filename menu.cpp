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

int validarEdificio(string edificio, Edificios &edificios)
{
    int i, contador;
    bool found = false;
    for ( i = 0; i < edificios.devolverTamanio(); ++i)
    {
        if (edificio == edificios.devolverElemento(i))
        {
            found = true;
            contador = i;
        }
    }
    if (!found)
    {
        i = -1;
    }
    return contador;
}

bool validarMateriales(int posicion, Edificios &edificios, Materiales &materiales)
{
    bool piedraOk = false ,maderaOk = false,metalOk = false;
    if(atoi(edificios.devolverElemento(posicion+1).c_str()) <= materiales.devolverPiedra())
    {
        piedraOk = true;
    }
    if(atoi(edificios.devolverElemento(posicion+2).c_str()) <= materiales.devolverMadera())
    {
        maderaOk = true;
    }
    if(atoi(edificios.devolverElemento(posicion+3).c_str()) <= materiales.devolverMetal())
    {
        metalOk = true;
    }
    return (maderaOk && piedraOk && metalOk);
}

bool confirmar(int posicion,Edificios &edificios, Materiales &materiales)
{
    string confirmacion;
    cout<< "Los materiales después de la onstruccion seran: " << endl;
    cout<< "Piedra: " << materiales.devolverPiedra()- atoi(edificios.devolverElemento(posicion+1).c_str());
    cout<< "Madera: " << materiales.devolverMadera() - atoi(edificios.devolverElemento(posicion+2).c_str());
    cout<< "Metal: " << materiales.devolverMetal() - atoi(edificios.devolverElemento(posicion+3).c_str());
    cout << endl << "¿Construir? [s/n]";
    cin >>  confirmacion;
    return (confirmacion == "s");
}

void correrFuncion(Matriz *&punteroMatriz, int opcion_elegida, Materiales &materiales, Edificios &edificios)
{
    string nombreNuevoEdificio;
    int entradaValida;
    bool materialesValidos = false;
    int coord1, coord2;

    cout << "Ingrese el nombre del nuevo edificio: ";
    cin >> nombreNuevoEdificio;
    entradaValida = validarEdificio(nombreNuevoEdificio, edificios);
    while (entradaValida == -1)
    {
        cout << "Ingrese el nombre del nuevo edificio: ";
        cin >> nombreNuevoEdificio;
        entradaValida = validarEdificio(nombreNuevoEdificio, edificios);

        if (nombreNuevoEdificio == "0")
            entradaValida = 0;
    }
    materialesValidos = validarMateriales(entradaValida, edificios,materiales);
    if (materialesValidos) {
        bool confirmacion = confirmar(entradaValida,edificios, materiales);
        if(confirmacion) {
            cout << "Ingrese la primer coordenada: ";
            cin >> coord1;
            cout << endl << "Ingrese la segunda coordenada: ";
            cin >> coord2;
            punteroMatriz->construirEdificio(coord1 - 1, coord2 - 1, nombreNuevoEdificio);
        }
    }
    else
    {
        cout << "xdn´t" << endl;
    }

}

void procesarOpcion(Matriz *&punteroMatriz, int opcion_elegida, Materiales &materiales, Edificios &edificios)
{
    string aux;
    string nombreNuevoEdificio;
    int coord1, coord2;
    
    switch (opcion_elegida)
    {
    case CONSTRUIR_EDIFICIOS:
        edificios.mostrarContenido();
        correrFuncion(punteroMatriz,opcion_elegida, materiales,edificios); //chequar
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
        materiales.mostrarMateriales();
        break;
    case RECOLECTAR:
        punteroMatriz->recoletarMateriales();
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
