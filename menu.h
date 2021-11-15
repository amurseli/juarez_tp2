#ifndef TP1_MENU_H
#define TP1_MENU_H

#include "edificios.h"
#include "matriz.h"
#include <string>
#include "materiales.h"
#include "edificios.h"
#include "ubicaciones.h"
#include "constructora.h"
#include "mapa.h"

const string PATH_MATERIALES = "materiales.txt";
const string PATH_EDIFICIOS = "edificios.txt";
const string PATH_MAPA = "mapa.txt";
const string PATH_UBICACIONES = "ubicaciones.txt";
const int OPCION_MINIMA = 1;
const int OPCION_MAXIMA = 10;
const int CONSTRUIR_EDIFICIOS = 1;
const int MOSTRAR_EDIFICIOS_CONSTRUIDOS = 2;
const int MOSTRAR_EDIFICIOS = 3;
const int DEMOLER_EDIFICIO = 4;
const int MOSTRAR_MAPA = 5;
const int CONSULTAR_COORDENADA = 6;
const int MOSTRAR_INVENTARIO = 7;
const int RECOLECTAR = 8;
const int LLUVIA_DE_RECUROS = 9;
const int SALIR = 10;
const int ENTRAR = -1;

using namespace std;

class Menu
{

private:

    Edificios* punteroEdificios = nullptr;
    Materiales* punteroMateriales = nullptr;
    Mapa* punteroMapa = nullptr;
    Matriz *punteroMatriz = nullptr;
    Constructora* punteroConstructora = nullptr;
    Ubicaciones* punteroUbicaciones = nullptr;

public:

    Menu();

    //pre: -
    //post: Imprime por pantalla el menu
    void mostrarMenu();

    //pre: -
    //post: Guarda la opcion del usuario
    int elegirOpcion();

    void leerUbicaciones();

    void coordenadasConsultar();

    void crearConstructora();

    //pre: -
    //post: Imprime por pantalla que fue invalido la opcion elegida.
    void mostrarMensajeError();

    int validarArranque();

    //pre: -
    //post: Realiza la opcion pedida
    void procesarOpcion(int opcion_elegida);

    //pre:-
    //post: Frena el programa hasta recibir un input
    void presioneEnter();

    //pre: -
    //post: devuelve true si la opcion recibida esta en el rango valido y sino devuelve false.
    bool esOpcionValida(int elegida);

    ~Menu();

};

#endif //TP1_MENU_H
