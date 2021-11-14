#include <string>
#include "materiales.h"
#include "edificios.h"
#include "mapa.h"
#include "menu.h"

using namespace std;

int main()
{
    Menu* menu = new Menu();
    menu->leerUbicaciones();

    int opcionElegida = menu->validarArranque();

    if(opcionElegida != SALIR) {
        cout << "Bienvenido a Andypolis!" << endl;
        menu->crearConstructora();
    }

    while (opcionElegida != SALIR)
    {
        menu->mostrarMenu();
        opcionElegida = menu->elegirOpcion();

        if (!menu->esOpcionValida(opcionElegida))
            menu->mostrarMensajeError();
        else
        {
           menu->procesarOpcion( opcionElegida);
        }
    }

    delete menu;

    return 0;
}
