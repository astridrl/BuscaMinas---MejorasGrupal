#include "Juego.h"
#include <fstream>
#include <unistd.h>

//Inicializacion de victorias y perdidas
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
    //Se agregaron las reducciones (Britany)
	Juego::Juego(Tablero tablero, int cantidadMinas, int vidas, int puntosPorMina) //inicializar las vidas en el constructor
	{
		this->tablero = tablero;
		this->cantidadMinas = cantidadMinas;
		this->vidas = vidas; //puntero para guardar las vidas
		this->colocarMinasAleatoriamente();
		//Valores para la reduccion y aumento de puntos
		this->puntuacion = 0; //Puntuacion en 0
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
		if (conteo == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

//mejora de vidas (Astrid)
	void Juego::iniciar()
	{
		int fila, columna;
		while (true)
		{
			this->tablero.imprimir();
			cout << "Te quedan: " << this->vidas << " vidas" << endl;
			//Marcador de puntos
			cout << "Puntuacion actual: " << this->puntuacion << endl << endl;//Puntuacion inicial

			fila = this->solicitarFilaUsuario();
			columna = this->solicitarColumnaUsuario();
			bool respuestaAUsuario = this->tablero.descubrirMina(columna, fila);

			if (!respuestaAUsuario) //si descrubre una mina
			{
			    this->vidas--; //reducir una vida

			    this->puntuacion -= this->puntosPorMina;//Resta los puntos por mina encontrada

			    cout << "\n¡Has descubierto una mina!"<< endl << endl;
			    cout <<  "--Pierdes: " << this->puntosPorMina << " puntos" << endl;//Muestra los puntos perdidos

			    if (this -> vidas <= 0) //cuando no queden vidas
                {
                this->perdidas++; //Suma las perdidas
                cout <<"\n¡Te has quedado sin vidas! Perdiste el juego" << endl;

                cout << "\nPuntuacion final: " << this->puntuacion << endl;//Muestra la puntuacion final

				this->tablero.setModoDesarrollador(true);
				this->tablero.imprimir();
				break;
                }
                else //si aun quedan vidas
                {
                cout << "--Te quedan " << this->vidas << " vidas\n" << endl;
                system("pause");
                continue; //continuar el juego
                }
			}
			else //Si se descubre una mina sin celda
            {
                int puntosPorCelda = this->tablero.getMinasCercanas(fila,columna);
                this->puntuacion += puntosPorCelda; //Aumentar la puntuacion
                cout << "\n!Ganas " << puntosPorCelda << " puntos!\n\n";
            }

			if (this->jugadorGana())
			{
			    this->victorias++; //Suma las victorias
				cout << "¡Ganaste el Juego!" << endl;
				cout << "\Puntuación final: " << this->puntuacion << endl<< endl;
				this->tablero.setModoDesarrollador(true);
				this->tablero.imprimir();
				break;
			}

		}
	}

	//Implementacion de registro de usuario
	bool Juego::registrarUsuario(const std::string& nombre) {
    if (nombre.empty()) {
        return false;
    }
    usuarioActual = nombre;
    return true;
    }

    void Juego::setUsuarioActual(const std::string& nombre) {
        this->usuarioActual = nombre;
    }

    std::string Juego::getUsuarioActual() const {
        return usuarioActual;
    }
//Se obtiene el total de victorias y de perdidas
int Juego::obtenerVictorias() {
    return this->victorias;
}

int Juego::obtenerPerdidas() {
    return this->perdidas;
}
