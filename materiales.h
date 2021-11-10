#ifndef MATERIALES_H
#define MATERIALES_H
#include "archivo.h"
#include <string>

using namespace std;

const string MADERA = "madera";
const string PIEDRA = "piedra";
const string METAL = "metal";

class Materiales : public Archivo
{
private:
    int piedra;
    int madera;
    int metal;
public:
    Materiales(string nombre);

    //Pre:
    //Post:Lee el archivo y actualiza los atributos
    void leerArchivo(string nombre);

    void guardarDatos(string nombreMaterial, string cantidad);

    int devolverPiedra();

    int devolverMadera();

    int devolverMetal();

    //Pre:
    //Post:Llama a los metodos sumar dependiendo del tipo de materiañ
    void agregarMaterial(string material, int cantidad);

    //Pre:
    //Post:Actualuiza atributos
    void sumarPiedra(int cantidad);

    //Pre:
    //Post:Actualuiza atributos
    void sumarMadera(int cantidad);

    //Pre:
    //Post:Actualuiza atributos
    void sumarMetal(int cantidad);

    //Pre:
    //Post:Actualuiza atributos
    void restarPiedra(int cantidad);

    //Pre:
    //Post:Actualuiza atributos
    void restarMadera(int cantidad);

    //Pre:
    //Post:Actualuiza atributos
    void restarMetal(int cantidad);

    void mostrarMateriales();

    //Pre:
    //Post:Escribe los cambios en un archivo
    void escribirArchivo();

    //Pre:REcibe parametros de pmateriales necesarios
    //Post:Devuelve verdadero si hay materiales suficientes
    bool validarMateriales(int piedraNecesaria, int maderaNecesaria, int metalNecesario);

    //Pre:
    //Post:Retorna la direccion de memoria del objeto
    Materiales* devolverDireccionMemoria();

    virtual ~Materiales();
};

#endif
