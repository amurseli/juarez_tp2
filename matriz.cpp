#include <iostream>
#include "matriz.h"
#include "colors.h"

using namespace std;

Matriz::Matriz(int columnasMatriz, int filasMatriz)
{

    filas = filasMatriz;
    columnas = columnasMatriz;

    crearMemoriaPunteros();
}

void Matriz::crearMemoriaPunteros()
{
    punteroMatriz = new Casillero **[filas];

    for (int i = 0; i < filas; i++)
        punteroMatriz[i] = new Casillero *[columnas];
}

void Matriz::agregarCasillero(string elemento, int coordenadaX, int coordenadaY)
{
    Casillero *crearCasillero;

    if (elemento == LAGO)
    {
        crearCasillero = new CasilleroInaccesible(elemento);
    }
    else if (elemento == CONSTRUIBLE)
    {
        crearCasillero = new CasilleroConstruible(elemento, coordenadaX, coordenadaY);
    }
    else
    {
        crearCasillero = new CasilleroTransitable(elemento);
    }

    punteroMatriz[coordenadaY][coordenadaX] = crearCasillero;
}

void Matriz::mostrarCoordenada(int coordenadaX, int CoordenadaY)
{

    punteroMatriz[coordenadaX][CoordenadaY]->queSoy();
}

void Matriz::mostrarEdificiosConstruidos()
{
    string nombreEdificio;
    int contMina = 0, contObelisco = 0, contAserradero = 0, contEscuela = 0, contFabrica = 0, contPlanta = 0;

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            nombreEdificio = punteroMatriz[i][j]->mostrarEdificio(); // Aca esta las coords.
            if (nombreEdificio == MINA)
            {
                contMina++;
                punteroMatriz[i][j]->devolverPosicion();
                cout << "-> Mina" << endl;
            }
            else if (nombreEdificio == OBELISCO)
            {
                contObelisco++;
                punteroMatriz[i][j]->devolverPosicion();
                cout << "-> Obelisco" << endl;
            }
            else if (nombreEdificio == ASERRADERO)
            {
                contAserradero++;
                punteroMatriz[i][j]->devolverPosicion();
                cout << "-> Aserradero" << endl;
            }
            else if (nombreEdificio == ESCUELA)
            {
                contEscuela++;
                punteroMatriz[i][j]->devolverPosicion();
                cout << "-> Escuela" << endl;
            }
            else if (nombreEdificio == FABRICA)
            {
                contFabrica++;
                punteroMatriz[i][j]->devolverPosicion();
                cout << "-> Fabrica" << endl;
            }
            else if (nombreEdificio == PLANTA_ELECTRICA)
            {
                contPlanta++;
                punteroMatriz[i][j]->devolverPosicion();
                cout << "-> Planta Electrica" << endl;
            }
        }
    }
    imprimirCantidades(contMina, contObelisco, contAserradero, contEscuela, contFabrica, contPlanta);
}

int Matriz::devolverCantidadEdificio(string edificio){
    int cantidadEdificio = 0;
    string nombreEdificio;

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            nombreEdificio = punteroMatriz[i][j]->mostrarEdificio();
            if (nombreEdificio == edificio)
                cantidadEdificio++;
        }
    }
    return (cantidadEdificio);
}

void Matriz::imprimirCantidades(int contMina, int contObelisco, int contAserradero, int contEscuela, int contFabrica, int contPlanta)
{
    cout << endl;
    if (contMina > 0)
        cout << "- Minas = " << contMina << endl;
    if (contObelisco > 0)
        cout << "- Obeliscos = " << contObelisco << endl;
    if (contAserradero > 0)
        cout << "- Aserraderos = " << contAserradero << endl;
    if (contEscuela > 0)
        cout << "- Escuelas = " << contEscuela << endl;
    if (contFabrica > 0)
        cout << "- Fabricas = " << contFabrica << endl;
    if (contPlanta > 0)
        cout << "- Plantas Electricas = " << contPlanta << endl;
}

void Matriz::construirEdificio(int coordX, int coordY, string nombreNuevoEdificio)
{
    if (validarTipoConstruible(coordX, coordY))
    {
        punteroMatriz[coordX][coordY]->modificarTerreno(nombreNuevoEdificio, CONSTRUIR);
    }
}

void Matriz::demolerEdificio(int coordX, int coordY)
{
    punteroMatriz[coordX][coordY]->modificarTerreno(VACIO, DEMOLER);
}

void Matriz::mostrarMatriz()
{
    cout << endl;
    for (int i = 0; i < columnas; ++i)
    {
        cout << i + 1 << " ";
    }
    cout << endl;
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            punteroMatriz[i][j]->mostrarContenido();
            cout<< " ";
        }
        cout << i + 1 << endl;
    }
    cout << endl;
}

void Matriz::recoletarMateriales(Materiales* &materiales)
{
    string tipoTerreno;

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            tipoTerreno = punteroMatriz[i][j]->obtenerTipoTerreno();
            if (tipoTerreno == CONSTRUIBLE)
                punteroMatriz[i][j]->recolectar(materiales);
        }
    }
}

void Matriz::generarLluviaMateriales()
{

    int numeroAleatorioPiedra, numeroAleatorioMadera, numeroAleatorioMetales;
    string material;

    srand((unsigned int)time(NULL));

    numeroAleatorioPiedra = 1 + rand() % (2);
    numeroAleatorioMadera = rand() % (2);
    numeroAleatorioMetales = 2 + rand() % (5 - 2);

    agregarMaterial(numeroAleatorioPiedra, PIEDRA);
    agregarMaterial(numeroAleatorioMadera, MADERA);
    agregarMaterial(numeroAleatorioMetales, METAL);

    cout << "\n Parece que la lluvia no ha llegado a todos los lugares, son tiempos dificiles" << endl;
}

void Matriz::agregarMaterial(int cantidad, string material)
{

    for (int i = 0; i < cantidad; i++)
    {
        agregarAcoordenada(cantidad, material);
    }
}

void Matriz::agregarAcoordenada(int cantidad, string material)
{

    int coordeX, coordeY, cantidadIntentos = 0, cantidadExitoso = 0;
    bool terrenoTransitableValido = false;
    string terreno;

    srand((unsigned int)time(NULL));

    while (!terrenoTransitableValido && cantidadIntentos != cantidad)
    {
        coordeX = rand() % (filas);
        coordeY = rand() % (columnas);
        terreno = devolverTipoTerreno(coordeX, coordeY);
        if (terreno == TRANSITABLE)
        {
            terrenoTransitableValido = validarExistenciaMaterial(coordeX, coordeY);
            cantidadIntentos++;
        }
        if (terrenoTransitableValido)
        {
            punteroMatriz[coordeX][coordeY]->modificarTerreno(material, SIN_ACCION);
            cantidadExitoso++;
            cout << "Ha llovido en la coordenada: fila:" + to_string(coordeX + 1) + " columna" + to_string(coordeY + 1) << endl;
        }
    }

}

bool Matriz::validarExistenciaMaterial(int coordeX, int coordeY)
{
    return (punteroMatriz[coordeX][coordeY]->mostrarMaterial() == VACIO);
}

bool Matriz::validarTipoConstruible(int coord1, int coord2)
{

    bool terrenoValido = (devolverTipoTerreno(coord1, coord2) == CONSTRUIBLE);

    return (terrenoValido);
}

string Matriz::devolverTipoTerreno(int coord1, int coord2)
{
    return punteroMatriz[coord1][coord2]->obtenerTipoTerreno();
}

string Matriz::devolverTipoEdificio(int coord1, int coord2)
{

    return punteroMatriz[coord1][coord2]->mostrarEdificio();
}

int Matriz::devolverMaxCol()
{
    return columnas;
}

int Matriz::devolverMaxFil()
{
    return filas;
}

Matriz::~Matriz()
{

    if (columnas > 0)
    {

        for (int i = 0; i < filas; i++)
        {
            for (int j = 0; j < columnas; j++)

                delete punteroMatriz[i][j];

            delete[] punteroMatriz[i];
        }

        delete[] punteroMatriz;
    }
}
