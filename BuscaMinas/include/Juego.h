#ifndef JUEGO_H
#define JUEGO_H
#include "Tablero.h"

class Juego
{
private:
	Tablero tablero;
	int cantidadMinas;
	int vidas; //variable para las vidas
	std::string usuarioActual; //almacena el usuario actual

	int aleatorio_en_rango(int minimo, int maximo);
	int filaAleatoria();
	int columnaAleatoria();

public:
    Juego(Tablero tablero, int cantidadMinas, int vidas = 3); //Se agrega al constructor con un valor predeterminado de 3 (3 vidas inicialmente)
	void colocarMinasAleatoriamente();
	int solicitarFilaUsuario();
	int solicitarColumnaUsuario();
	bool jugadorGana();
	void iniciar();
	void dibujarPortada(string nombreArchivo);

	//Integrar variables para registro de ususario
	bool registrarUsuario(const std::string& nombre);
	void mostrarMenuPrincipal();
	void setUsuarioActual(const std::string& nombre);
	std::string getUsuarioActual() const;
	void setNombreJugador(const std::string& nombre);
};

#endif // JUEGO_H
