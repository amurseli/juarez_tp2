#include <iostream>
#include "matriz.h"

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
        crearCasillero = new CasilleroConstruible(elemento,coordenadaX,coordenadaY);
    }
    else if (elemento == TRANSITABLE)
    {
        crearCasillero = new CasilleroTransitable(elemento);
    }

    punteroMatriz[coordenadaY][coordenadaX] = crearCasillero;
    
}

void Matriz::mostrarCoordenada(int coordenadaX, int CoordenadaY){

    punteroMatriz[coordenadaX][CoordenadaY]->queSoy();

}

void Matriz::mostrarEdificiosConstruidos(){
    string nombreEdificio;
    int contMina=0,contObelisco=0,contYacimiento=0,contEscuela=0,contFabrica=0,contPlanta=0;
    
    for (int i = 0; i < filas; i++){
        for (int j = 0; j < columnas; j++){
             nombreEdificio = punteroMatriz[i][j]->mostrarEdificio(); // Aca esta las coords.
            if (nombreEdificio == MINA){
                contMina++;
                punteroMatriz[i][j]->devolverPosicion();
            }
            else if (nombreEdificio == OBELISCO){
                contObelisco++;
            }
            else if (nombreEdificio == YACIMIENTO){
                contYacimiento++;
            }
            else if (nombreEdificio == ESCUELA){
                contEscuela++;
            }
            else if (nombreEdificio == FABRICA){
                contFabrica++;
            }
            else if (nombreEdificio == PLANTA_ELECTRICA){
                contPlanta++;
            }
        }
    }
    if(contMina > 0)
        cout << "- Minas = " << contMina << endl;
    if(contObelisco > 0)
        cout << "- Obeliscos = " << contObelisco << endl;
    if(contYacimiento > 0)
        cout << "- Yacumientos = " << contYacimiento << endl;
    if(contEscuela > 0)
        cout << "- Escuelas = " << contEscuela << endl;
    if(contFabrica > 0)
        cout << "- Fabricas = " << contFabrica << endl;
    if(contPlanta > 0)
        cout << "- Plantas Electricas = " << contPlanta << endl;
}

void Matriz::construirEdificio(int coordX, int coordY, string nombreNuevoEdificio)
{
    if (validarTipoConstruible(coordX,coordY))
    {
        punteroMatriz[coordX][coordY]->modificarTerreno(nombreNuevoEdificio,CONSTRUIR);
    }
}

void Matriz::demolerEdificio(int coordX, int coordY)
{
    punteroMatriz[coordX][coordY]->modificarTerreno(VACIO,DEMOLER);
}

void Matriz::mostrarMatriz()
{

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)

            punteroMatriz[i][j]->mostrarTipoTerreno();
        cout << " " << endl;
    }
}

void Matriz::recoletarMateriales(Materiales &materiales){
    string tipoTerreno;

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            tipoTerreno = punteroMatriz[i][j]->obtenerTipoTerreno();
            if(tipoTerreno == CONSTRUIBLE)
                punteroMatriz[i][j]->recolectar(materiales);

        }
    }
}

void Matriz::generarLluviaMateriales(){

    string tipoTerreno;

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            tipoTerreno = punteroMatriz[i][j]->obtenerTipoTerreno();
            validarParaAgregar(tipoTerreno,i,j);
        }
    }

}

void Matriz::validarParaAgregar(string tipoTerreno, int coordenadaX, int coordenadaY){

    string materialCayendo;
    
    if (tipoTerreno == TRANSITABLE)
    {
        materialCayendo = generarRandom();
        punteroMatriz[coordenadaX][coordenadaY]->modificarTerreno(materialCayendo,SIN_ACCION);
    }
}

string Matriz::generarRandom(){

    int numeroAleatorio;
    string material;

    srand ((unsigned int)time(NULL));

    cout << numeroAleatorio << endl;

    if(numeroAleatorio == 1){
        material = "PIEDRA";
    }
    else if(numeroAleatorio == 2){
        material = "MADERA";
    }
    else if(numeroAleatorio == 3){
        material = "METAL";
    }

    return material;

}

bool Matriz::validarTipoConstruible(int coord1, int coord2){

    bool terrenoValido = (devolverTipoTerreno(coord1,coord2) == CONSTRUIBLE);

    return (terrenoValido);
}

string Matriz::devolverTipoTerreno(int coord1,int coord2)
{
    return  punteroMatriz[coord1][coord2]->obtenerTipoTerreno();
}

string Matriz::devolverTipoEdificio(int coord1,int coord2)
{
    
    return punteroMatriz[coord1][coord2]->mostrarEdificio();
}

int Matriz::devolverMaxCol() {
    return columnas;
}

int Matriz::devolverMaxFil() {
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

        delete punteroMatriz;
    }
}
