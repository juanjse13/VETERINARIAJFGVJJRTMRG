#ifndef PROPIETARIOVETERINARIO_H
#define PROPIETARIOVETERINARIO_H

#include <map>
#include <iostream>

using std::string;
using std::cout;
using std::cin;
using std::endl;


class Propietario{
    private:
        //Atributos respectivos
        string nombre;
        string email;
        int identificacion;
        int telefono;
    public:
        // Sets y gets de la clase
        void setNombre(string nombre);
        void setEmail(string email);
        void setTelefono(int telefono);
        void setIdentificacion(int identificacion);
        int getIdentificacion();
        //Constructores de propietario
        Propietario(); 
        Propietario(string, int, string, int);
        //Otras funciones
        void mostrarDatosPropietario();
};

#endif // PROPIETARIOVETERINARIO_H