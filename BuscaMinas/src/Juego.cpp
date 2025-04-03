#include "Juego.h"
#include <fstream>
#include <unistd.h>
#include <chrono> // Agregue Biblioteca para que permite medir intervalos de tiempo con precisión.(Dulce Reyes)

// Inicializacion de victorias y perdidas
int Juego::victorias = 0;
int Juego::perdidas = 0;

int Juego::aleatorio_en_rango(int minimo, int maximo)
{
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}

int Juego::filaAleatoria()
{
    return this->aleatorio_en_rango(0, this->tablero.getAlturaTablero() - 1);
}

int Juego::columnaAleatoria()
{
    return this->aleatorio_en_rango(0, this->tablero.getAnchoTablero() - 1);
}

// Se agregaron las reducciones (Britany)
Juego::Juego(Tablero tablero, int cantidadMinas, int vidas, int puntosPorMina)
{
    this->tablero = tablero;
    this->cantidadMinas = cantidadMinas;
    this->vidas = vidas; // puntero para guardar las vidas
    this->colocarMinasAleatoriamente();
    // Valores para la reduccion y aumento de puntos
    this->puntuacion = 0; // Puntuacion en 0
    this->puntosPorMina = puntosPorMina;
}

void Juego::colocarMinasAleatoriamente()
{
    int x, y, minasColocadas = 0;
    while (minasColocadas < this->cantidadMinas)
    {
        x = this->columnaAleatoria();
        y = this->filaAleatoria();
        if (this->tablero.colocarMina(x, y))
        {
            minasColocadas++;
        }
    }
}

int Juego::solicitarFilaUsuario()
{
    int fila = 0;
    cout << "Ingresa la FILA en la que desea jugar: ";
    cin >> fila;
    return fila - 1;
}

int Juego::solicitarColumnaUsuario()
{
    int columna = 0;
    cout << "Ingresa la COLUMNA en la que desea jugar: ";
    cin >> columna;
    return columna - 1;
}

bool Juego::jugadorGana()
{
    int conteo = this->tablero.contarCeldasSinMinasYSinDescubrir();
    return conteo == 0;
}

// Mejora de vidas (Astrid)
void Juego::iniciar()
{
    tiempoInicio = std::chrono::steady_clock::now(); // Iniciar el cronómetro: guarda el tiempo actual al inicio del juego. (Dulce Reyes)
    std::cout << "El cronometro ha iniciado. ¡Buena suerte!" << std::endl;
    int fila, columna;
    while (true)
    {
        auto tiempoActual = std::chrono::steady_clock::now(); // Mostrar el tiempo transcurrido en cada iteración del juego (Dulce Reyes)
        std::chrono::duration<double> duracion = tiempoActual - tiempoInicio;
        std::cout << "Tiempo transcurrido: " << duracion.count() << " segundos." << std::endl;

        this->tablero.imprimir();
        cout << "Te quedan: " << this->vidas << " vidas" << endl;
        cout << "Puntuacion actual: " << this->puntuacion << endl << endl;

        fila = this->solicitarFilaUsuario();
        columna = this->solicitarColumnaUsuario();
        bool respuestaAUsuario = this->tablero.descubrirMina(columna, fila);

        if (!respuestaAUsuario)
        {
            this->vidas--;
            if (this->vidas <= 0)
            {
                cout << "\n Te has quedado sin vidas! Perdiste el juego" << endl;
                cout << "\nPuntuacion final: " << this->puntuacion << endl;
                this->tablero.setModoDesarrollador(true);
                this->tablero.imprimir();
                break;
            }
            else
            {
                cout << "--Te quedan " << this->vidas << " vidas\n" << endl;
                system("pause");
                continue;
            }
        }
        else
        {
            int puntosPorCelda = this->tablero.getMinasCercanas(fila, columna);
            this->puntuacion += puntosPorCelda;
            cout << "\n!Ganas " << puntosPorCelda << " puntos!\n\n";
        }

        if (this->jugadorGana())
        {
            cout << " Ganaste el Juego!" << endl;
            cout << "\nPuntuación final: " << this->puntuacion << endl;
            this->tablero.setModoDesarrollador(true);
            this->tablero.imprimir();
            break;
        }
    }
}

// Implementacion de registro de usuario
bool Juego::registrarUsuario(const std::string& nombre)
{
    if (nombre.empty())
    {
        return false;
    }
    usuarioActual = nombre;
    return true;
}

void Juego::setUsuarioActual(const std::string& nombre)
{
    this->usuarioActual = nombre;
}

std::string Juego::getUsuarioActual() const
{
    return usuarioActual;
}

// Se obtiene el total de victorias y de perdidas
int Juego::obtenerVictorias()
{
    return this->victorias;
}

int Juego::obtenerPerdidas()
{
    return this->perdidas;
}

// Implementé el método dibujarPortada() que estaba en el juego.h pero no se implementaba aquí (Astrid)
void Juego::dibujarPortada(string nombreArchivo)
{
    ifstream archivo(nombreArchivo);
    string linea;
    if (archivo.is_open())
    {
        while (getline(archivo, linea))
        {
            cout << linea << endl;
        }
        archivo.close();
    }
    else
    {
        cout << "El archivo de portada no se pudo abrir" << endl;
        cout << " Bienvenidos al buscaminas!" << endl;
    }
    cin.get();
}
