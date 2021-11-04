#include "ubicaciones.h"


using namespace std;

Ubicaciones::Ubicaciones(string nombre, Matriz* &matriz):Archivo(nombre){
    punteroMatriz = matriz;
    leerArchivo(nombre);
}
void Ubicaciones::leerArchivo(string nombre)
{
    fstream documento(nombre, ios::in);

    string nombreEdificio;
    string coordX, coordY;
    int cleanCoordX, cleanCoordY;
    while (documento >> nombreEdificio)
    {
        documento >> coordX;
        documento >> coordY;

        coordX = coordX.substr(1);
        coordX.pop_back();
        cleanCoordX = atoi(coordX.c_str());

        coordY.pop_back();
        cleanCoordY = atoi(coordY.c_str());        

        punteroMatriz->construirEdificio(cleanCoordX-1,cleanCoordY-1,nombreEdificio);
    }

    documento.close();
}

