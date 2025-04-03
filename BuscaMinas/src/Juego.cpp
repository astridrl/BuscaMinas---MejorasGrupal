#include "Juego.h"
#include <fstream>
#include <unistd.h>

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

	Juego::Juego(Tablero tablero, int cantidadMinas, int vidas) //inicializar las vidas en el constructor
	{
		this->tablero = tablero;
		this->cantidadMinas = cantidadMinas;
		this->vidas = vidas; //puntero para guardar las vidas
		this->colocarMinasAleatoriamente();
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
			fila = this->solicitarFilaUsuario();
			columna = this->solicitarColumnaUsuario();
			bool respuestaAUsuario = this->tablero.descubrirMina(columna, fila);
			if (!respuestaAUsuario) //si descrubre una mina
			{
			    this->vidas--; //reducir una vida

			    if (this -> vidas <= 0) //cuando no queden vidas
                {
                cout <<"¡Te has quedado sin vidas! Perdiste el juego" << endl;
				this->tablero.setModoDesarrollador(true);
				this->tablero.imprimir();
				break;
			}
			else //si aun quedan vidas
            {
                cout << "¡Has descubierto una mina! Te quedan " << this->vidas << " vidas" << endl;
                system("pause");
                continue; //continuar el juego
            }
			}

			if (this->jugadorGana())
			{
				cout << "¡Ganaste el Juego!" << endl;
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
