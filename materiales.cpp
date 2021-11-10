#include "materiales.h"
#include <string>
#include <iostream>

using namespace std;

Materiales::Materiales(string nombre) : Archivo(nombre)
{
    if (getArchivoValido())
        leerArchivo(nombre);
}
void Materiales::leerArchivo(string nombre)
{

    fstream documento(nombre, ios::in);

    string nombreMaterial, cantidad;

    while (documento >> nombreMaterial)
    {
        documento >> cantidad;
        guardarDatos(nombreMaterial, cantidad);
    }
    documento.close();
}

void Materiales::escribirArchivo()
{

    fstream documento(devolverNombre(), ios::out);

    documento << "piedra " + to_string(devolverPiedra()) << endl;
    documento << "madera " + to_string(devolverMadera()) << endl;
    documento << "metal " + to_string(devolverMetal()) << endl;

    documento.close();
}

void Materiales::guardarDatos(string nombreMaterial, string cantidad)
{
    if (nombreMaterial == "piedra")
    {
        piedra = atoi(cantidad.c_str());
    }
    else if (nombreMaterial == "madera")
    {
        madera = atoi(cantidad.c_str());
    }
    else if (nombreMaterial == "metal")
    {
        metal = atoi(cantidad.c_str());
    }
}

void Materiales::mostrarMateriales()
{
    cout << "Piedra disponible: " << piedra << endl;
    cout << "Madera disponible: " << madera << endl;
    cout << "Metal disponible: " << metal << endl;
}

void Materiales::agregarMaterial(string material, int cantidad){

    if(material == PIEDRA){
        sumarPiedra(cantidad);
        cout << "Se agregò piedra" << endl;
    }
    else if(material == MADERA){
        sumarMadera(cantidad);
        cout << "Se agregò madera" << endl;
    }
    else if(material == METAL){
        sumarMetal(cantidad);
        cout << "Se agregò metal" << endl;
    }
}

bool Materiales::validarMateriales(int piedraNecesaria, int maderaNecesaria, int metalNecesario)
{
    bool piedraOk = false ,maderaOk = false,metalOk = false;

    if(piedraNecesaria <= devolverPiedra())
    {
        piedraOk = true;
    }
    if( maderaNecesaria <= devolverMadera())
    {
        maderaOk = true;
    }
    if(metalNecesario <= devolverMetal())
    {
        metalOk = true;
    }
    return (maderaOk && piedraOk && metalOk);
}

int Materiales::devolverPiedra()
{
    return piedra;
}
int Materiales::devolverMadera()
{
    return madera;
}
int Materiales::devolverMetal()
{
    return metal;
}

void Materiales::sumarPiedra(int cantidad) {
    piedra = piedra + cantidad;
}
void Materiales::sumarMadera(int cantidad) {
    madera = madera + cantidad;
}
void Materiales::sumarMetal(int cantidad) {

    metal = metal + cantidad;
}

void Materiales::restarPiedra(int cantidad) {
    piedra = piedra - cantidad;
}
void Materiales::restarMadera(int cantidad) {
    madera = madera - cantidad;
}
void Materiales::restarMetal(int cantidad) {

    metal = metal - cantidad;
}

Materiales* Materiales::devolverDireccionMemoria(){

    return (this);
}

Materiales::~Materiales(){}
