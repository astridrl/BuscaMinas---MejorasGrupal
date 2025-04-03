#ifndef CONFIG_H
#define CONFIG_H

class Config
{
    public:
        //Se agregaron los parametros para los puntos por celda y para la recuccion
        Config(int filasTablero, int columnasTablero, int minasTablero, bool modoDesarrolladorTablero,
               int vidasTablero, int reduccionPuntos);
        int getfilasTablero();
        int setfilasTablero(int filasTablero);
        int getcolumnasTablero();
        int setcolumnasTablero(int columnasTablero);
        int getminasTablero();
        int setminasTablero(int minasTablero);
        bool getmodoDesarrolladorTablero();
        bool setmodoDesarrolladorTablero(bool modoDesarrolladorTablero);
        int getvidasTablero();
        int setvidasTablero(int vidasTablero);

        void menuConfiguracion();

        //Metodos para obtener y establecer las recucciones de puntos
        int getReduccionPuntos();
        void setReduccionPuntos(int reduccionPuntos);

    protected:

    private:
        int filasTablero;
        int columnasTablero;
        int minasTablero;
        bool modoDesarrolladorTablero;
        int vidasTablero;
        //Valores de reduccion
        int reduccionPuntos;
};

#endif // CONFIG_H
