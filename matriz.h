#include<string>
#include<fstream>
#include"array.h"

using namespace std;

class Matriz : public array<string>
{
private:
    int tamanio;
    array* columnas;

public:

    Matriz(int ancho,int alto, array* &contenido);

    void agregarElementoArrayMatriz(string elemento);

    void mostrarMatriz();

    ~Matriz();
};




