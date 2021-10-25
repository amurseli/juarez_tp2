#ifndef ARCHIVO_H
#define ARCHIVO_H
#include<string>
#include<fstream>
#include"array.h"

using namespace std;

class archivo : public array<string>
{
    private:
        
        string nombre;
        bool existenciaArchivo;
        array* contenido;

    public:
        //Pre:Debe recibir el nombre del archivo.
        //Post: crea la Lista.
        archivo(string nombreArchivo);

        //Pre:-
        //Post:devuelve el estado del la variable existeciaArchivo.
        bool getArchivoValido(); 

        //Pre:
        //Post: 
        virtual void leerArchivo(string nombre)=0;

        //Pre:
        //Post: 
        void agregarElementoArray(string elemento);

        //Pre:-
        //Post:Muestra el array
        void mostrarContenido();

        ~archivo();
        

    private:
        
        //Pre:Debe recibir el nombre del archivo.
        //Post:valida si existe el archivo.
        void validarArchivo();


};

#endif