#include "ubicaciones.h"


using namespace std;

Ubicaciones::Ubicaciones(string nombre, Matriz* &matriz):Archivo(nombre){
    punteroMatriz = matriz;

    if(getArchivoValido())
        leerArchivo(nombre);

}
void Ubicaciones::leerArchivo(string nombre)
{
    fstream documento(nombre, ios::in);

    string nombreEdificio, segundoNombre;
    string coordX, coordY;
    int cleanCoordX, cleanCoordY;
    while (documento >> nombreEdificio)
    {   
        if(nombreEdificio == "planta"){
            documento >> segundoNombre;
            nombreEdificio = nombreEdificio + " " + segundoNombre;
        }

        documento >> coordX;
        documento >> coordY;

        cleanCoordX = arreglarCoordenadaX(coordX);
        cleanCoordY = arreglarCoordenadaY(coordY);

        punteroMatriz->construirEdificio(cleanCoordX,cleanCoordY,nombreEdificio);
    }

    documento.close();
}

int Ubicaciones::arreglarCoordenadaX(string coordX){

        coordX = coordX.substr(1);
        coordX.pop_back();

        return (atoi(coordX.c_str()));
}

int Ubicaciones::arreglarCoordenadaY(string coordY){

        coordY.pop_back();
        return (atoi(coordY.c_str()));       
}
