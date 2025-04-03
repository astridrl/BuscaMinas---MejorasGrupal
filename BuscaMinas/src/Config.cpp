#include <iostream>
#include <unistd.h>
#include "Config.h"
using namespace std;

//Consructor con las reducciones
Config::Config(int filasTablero, int columnasTablero, int minasTablero, bool modoDesarrolladorTablero,int vidasTablero, int reduccionPuntos)
{
    this->filasTablero = filasTablero; // this puntero a memoria al objeto  //apunta a la direccion a memoria RAM donde esta el objeto tablero ahi me permite // diferenciar pe pq tienen los mismos nombres
    this->columnasTablero = columnasTablero; // this este es el atributo del objeto // apunta al atributo del objeto
    this->minasTablero = minasTablero;
    this->modoDesarrolladorTablero = modoDesarrolladorTablero;
    this->vidasTablero = vidasTablero;
    //Se agregaron los atributos de  las reducciones
    this->reduccionPuntos = reduccionPuntos;
}
void Config::menuConfiguracion()
{
    int opciones;
    int valorIngresado;
    bool repetir = true;
    do
    {
        system("cls");
        cout << "\n\n\t\tCONFIGURACION ACTUAL -Menu-" << endl;
        cout << "\t\t-------------------"<< endl;
        cout << "\t\t1. Filas del Tablero ----> " << this->getfilasTablero() << endl; //ese metodo le pertenece al objeto el this es para colocar y extraer
        cout << "\t\t2. Columnas del Tablero -> " << this->getcolumnasTablero() << endl;
        cout << "\t\t3. Minas del Tablero ----> " << this->getminasTablero() << endl;
        cout << "\t\t4. Modo del Juego -------> " << this->getmodoDesarrolladorTablero() << endl;
        cout << "\t\t5. Vidas del Jugador ----> " << this->getvidasTablero() << endl;
        //Se agregaron las opcciones para configurar las reducciones por celda (Britany)
        cout << "\t\t6. Reduccion por mina ---> " << this->getReduccionPuntos() << endl;
        cout << "\t\t7. Regresar al menu general" << endl;
        cout << "\n\t\tIngrese una opcion: ";

        cin >> opciones;
        if (opciones!=7)
        {
            cout << "\n\tIngrese el valor que desea cambiar: ";
            cin >> valorIngresado;
        }
        switch (opciones)
        {
        case 1:
            {
                this->setfilasTablero(valorIngresado);
                cout << "\tFilas del Tablero actualizadas" << endl;
                break;
            }
        case 2:
            {
                this->setcolumnasTablero(valorIngresado);
                cout << "\tColumnas del Tablero actualizadas" << endl;
                break;
            }
        case 3:
            {
                this->setminasTablero(valorIngresado);
                cout << "\tMinas del Tablero actualizadas" << endl;
                break;
            }
        case 4:
            {
                this->setmodoDesarrolladorTablero(valorIngresado);
                //Se agrego el verificador para el modo desarrollador (Britany)
                if (valorIngresado !=0 && valorIngresado !=1){
                    cout << "\n\tValor fuera de los parametros ingrece 1 o 0\n" <<endl;
                }
                else{
                    cout << "\tModo del Juego actualizado" << endl;
                }
                break;
            }
        case 5:
            {
                this->setvidasTablero(valorIngresado);
                cout << "\tVidas del Juego actualizadas" << endl;
                break;
            }
        //Se agregaron los Case 6  para las reducciones
        case 6:
            {
                this->setReduccionPuntos(valorIngresado);
                cout << "\tReduccion de puntos actualizado" << endl;
                break;
            }
        //Se cambio la salida a case 8
        case 7: repetir = false;
                break;
        }
        system("pause");
    } while (repetir);
}
int Config::getfilasTablero()
{
    return this->filasTablero;
}
int Config::setfilasTablero(int filasTablero)
{
    this->filasTablero=filasTablero;
}
int Config::getcolumnasTablero()
{
    return this->columnasTablero;
}
int Config::setcolumnasTablero(int columnasTablero)
{
    this->columnasTablero=columnasTablero;
}
int Config::getminasTablero()
{
    return this->minasTablero;
}
int Config::setminasTablero(int minasTablero)
{
    this->minasTablero=minasTablero;
}
bool Config::getmodoDesarrolladorTablero()
{
    return this->modoDesarrolladorTablero;
}
bool Config::setmodoDesarrolladorTablero(bool modoDesarrolladorTablero)
{
    this->modoDesarrolladorTablero=modoDesarrolladorTablero;
}
int Config::getvidasTablero()
{
    return this->vidasTablero;
}
int Config::setvidasTablero(int vidasTablero)
{
    this->vidasTablero=vidasTablero;
}
//Se agrege garon los metodos para la reduccion y los puntos por celda (Britany)
//Metodos para la reduccion en caso de mina
int Config::getReduccionPuntos()
{
    return this->reduccionPuntos;
}
void Config::setReduccionPuntos(int reduccionPuntos)
{
    //Verificador para establecer un minimo y maximo de puntos reducidos
    if (reduccionPuntos < 0 || reduccionPuntos > 50){
        cout << "\n\t\tLos numeros estalbecidos estan fuera del rango...\n";
        reduccionPuntos= 3;
    }
    this->reduccionPuntos=reduccionPuntos;
}


