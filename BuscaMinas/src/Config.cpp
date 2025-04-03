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

// Método para establecer el número de filas con validación de límites
int Config::setfilasTablero(int filasTablero)
{
    //Constantes para los límites de tamaño del tablero
    const int MIN_FILAS = 2;  // Valor mínimo
    const int MAX_FILAS = 10; // Valor máximo

    // Validar el valor ingresado
    if (filasTablero < MIN_FILAS) {
        // Si el valor es menor al mínimo, establecí el valor mínimo
        cout << "Valor demasiado pequeño. Se establecera el minimo de " << MIN_FILAS << " filas." << endl;
        this->filasTablero = MIN_FILAS;
        return MIN_FILAS; // Retornamos el valor
    }
    else if (filasTablero > MAX_FILAS) {
        // Si el valor es mayor al máximo, establecer el valor máximo
        cout << "Valor demasiado grande. Se establecera el maximo de " << MAX_FILAS << " filas." << endl;
        this->filasTablero = MAX_FILAS;
        return MAX_FILAS;
    }
    else {
        // Si el valor está dentro de los límites,se establece
        this->filasTablero = filasTablero;
        return filasTablero; // Retornamos el mismo valor que se recibió
    }
}

int Config::getcolumnasTablero()
{
    return this->columnasTablero;
}

// Método para establecer el número de columnas con validación de límites
int Config::setcolumnasTablero(int columnasTablero)
{
    //Constantes para los límites de tamaño del tablero
    const int MIN_COLUMNAS = 2;  // Valor mínimo
    const int MAX_COLUMNAS = 10; // Valor máximo

    // Validar valor
    if (columnasTablero < MIN_COLUMNAS) {
        // Si el valor es menor al mínimo, establer el valor mínimo
        cout << "Valor demasiado pequeño. Se establecera el minimo de " << MIN_COLUMNAS << " columnas." << endl;
        this->columnasTablero = MIN_COLUMNAS;
        return MIN_COLUMNAS;
    }
    else if (columnasTablero > MAX_COLUMNAS) {
        // Si el valor es mayor al máximo, establecer el valor máximo
        cout << "Valor demasiado grande. Se establecera el maximo de " << MAX_COLUMNAS << " columnas." << endl;
        this->columnasTablero = MAX_COLUMNAS;
        return MAX_COLUMNAS;
    }
    else {
        // Si el valor está dentro de los límites, se establece
        this->columnasTablero = columnasTablero;
        return columnasTablero;
    }
}

int Config::getminasTablero()
{
    return this->minasTablero;
}

// Método para establecer el número de minas con validación basada en el tamaño del tablero
int Config::setminasTablero(int minasTablero)
{
    // Calculamos el área total del tablero (filas × columnas)
    int areaTablero = this->filasTablero * this->columnasTablero;

    //límites para la cantidad de minas
    const int MIN_MINAS = 1; // al menos una mina para que el juego tenga sentido
    //minas a 10% del área total
    const int MAX_MINAS = static_cast<int>(areaTablero * 0.1);

    // Validar valor
    if (minasTablero < MIN_MINAS) {
        // Si el valor es menor al mínimo, establecer el valor mínimo
        cout << "Debe haber al menos " << MIN_MINAS << " mina en el tablero." << endl;
        this->minasTablero = MIN_MINAS;
        return MIN_MINAS;
    }
    else if (minasTablero > MAX_MINAS) {
        // Si el valor es mayor al máximo, establecer el valor máximo
        cout << "Demasiadas minas para el tablero. Se establecera el maximo de " << MAX_MINAS << " minas." << endl;
        this->minasTablero = MAX_MINAS;
        return MAX_MINAS;
    }else {
        this->minasTablero = minasTablero;
        return minasTablero;
    }
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
    // Definir límites para las vidas
    const int MIN_VIDAS = 1;  // Al menos debe tener 1 vida
    const int MAX_VIDAS = 10; //

    // Validar el valor
    if (vidasTablero < MIN_VIDAS) {
        cout << "El número de vidas no puede ser menor a " << MIN_VIDAS << ". Se usará el valor mínimo." << endl;
        this->vidasTablero = MIN_VIDAS;
    } else if (vidasTablero > MAX_VIDAS) {
        cout << "El número de vidas no puede ser mayor a " << MAX_VIDAS << ". Se usará el valor máximo." << endl;
        this->vidasTablero = MAX_VIDAS;
    } else {
        this->vidasTablero = vidasTablero;
    }

    return this->vidasTablero;
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


