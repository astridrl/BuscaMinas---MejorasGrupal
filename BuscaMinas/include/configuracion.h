#ifndef CONFIGURACION_H
#define CONFIGURACION_H
//Esta clase permitira llevar el control de configuracion de las opciones del juego
//19 de marzo del 2025

class Configuracion
{
    public:
        //Constructores
        Configuracion();
        Configuracion(int filasTablero, int columnasTablero, bool modoDesarrollador, int minasTablero, int vidasTablero);
        //Metodos
        int getFilasTablero();
        void setFilasTablero(int filasTablero);
        int getColumnasTablero();
        void setColumnasTablero(int columnasTablero);
        bool getModoDesarrollar();
        void setModoDesarrollar(bool modoDesarrollador);
        int getMinasTablero();
        void setMinasTablero(int minasTablero);
        int getVidasTablero();
        void setVidasTablero(int vidasTablero);

        virtual ~Configuracion();

    protected:

    private:
        //Atributos
        int filasTablero;
        int columnasTablero;
        bool modoDesarrollador;
        int minasTablero;
        int vidasTablero;
};

#endif // CONFIGURACION_H
