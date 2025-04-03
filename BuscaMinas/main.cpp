#include <iostream>
#include <unistd.h>
#include "Juego.h"
#include "Config.h"

using namespace std;

//Integración de vidas (Astrid)
int main()
{
    const int FILASTABLERO = 5;
    const int COLUMNASTABLERO = 5;
    const int MINASENTABLERO = 3;
    const bool MODODESARROLLADOR = true;
    const int VIDASTABLERO = 3;
    Config configuracionJuego(FILASTABLERO, COLUMNASTABLERO, MINASENTABLERO, MODODESARROLLADOR, VIDASTABLERO);
    Juego juego(Tablero(configuracionJuego.getfilasTablero(), configuracionJuego.getcolumnasTablero(), configuracionJuego.getmodoDesarrolladorTablero()), configuracionJuego.getminasTablero());
    srand(getpid());
    int opciones;
    bool repetir = true;
    do
    {
        system("cls");
        cout << "\n\n\t\tBUSCA MINAS -Menu-" << endl;
        cout << "\t\t-------------------"<< endl;
        cout << "\t\t1. Configuracion del Juego" << endl;
        cout << "\t\t2. Iniciar el Juego" << endl;
        cout << "\t\t3. Salir del Juego" << endl;
        cout << "\n\t\tIngrese una opcion: ";
        cin >> opciones;
        switch (opciones)
        {
        case 1:
            {
                configuracionJuego.menuConfiguracion();
                break;
            }
        case 2: //Agregué el parametro get de vidas ya que no estaba definido
                //Agregué el registro del usuario
            {
                string nombre;
                cout << "\t\tIngrese su nombre de usuario: ";
                cin.ignore();
                getline(cin, nombre);

                if (nombre.empty()) {
                    nombre = "Invitado";
                }
                juego.setUsuarioActual(nombre);


              	Juego juegoTemporal(Tablero(configuracionJuego.getfilasTablero(), configuracionJuego.getcolumnasTablero(), configuracionJuego.getmodoDesarrolladorTablero()), configuracionJuego.getminasTablero(), configuracionJuego.getvidasTablero()); //agregar vidas al tablero
                juegoTemporal.setUsuarioActual(nombre);
                juegoTemporal.iniciar();

                string resultado = juegoTemporal.jugadorGana() ? "Ganaste" : "Perdiste";
                cout << "\n\t\t" << nombre << ", " << resultado << " el Juego!\n";

                system("pause");
                break;
            }
        case 3: repetir = false;
                break;
        }
    } while (repetir);
    system("cls");
    return 0;
}

//mejorar las vidas, si tiene 3 que se cumplan las 3
