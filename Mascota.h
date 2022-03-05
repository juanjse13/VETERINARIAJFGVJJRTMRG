#ifndef MASCOTA_H
#define MASCOTA_H

#include <iostream>

using std::string;
using std::cout;
using std::cin;

class Mascota{
    private:
        //Atributos respectivos
        string tipoMascota;
        string raza;
        float peso;
        int edad;
        string tipoSangre;
        string nombre;
        int identificacion
        bool estado;
        string fechaDefuncion;
    public:
        //Constructores de Mascota
        Mascota();
        Mascota(string, int, string, float, int, string, bool, string);
        //Sets y gets de la clase
        int getIdentificacion();
        string getEstadoMascota();
        //Otras funciones
        void cambiarEstadoMascota();
        void mostrarDatosMascota();
};

#endif