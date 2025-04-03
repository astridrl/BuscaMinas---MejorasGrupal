#ifndef JUEGO_H
#define JUEGO_H
#include "Tablero.h"

class Juego
{
private:
	Tablero tablero;
	int cantidadMinas;
	int vidas; //variable para las vidas

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
	void dibujarPortada(string nombreArchivo); //metodo de la portada que no está implementado en el juego.cpp
};

#endif // JUEGO_H
