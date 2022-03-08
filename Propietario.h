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
        string telefono; // Se define el telefono como un string para que el usuario pueda ver claramente el numero que tiene cada propietario
    public:
        // Sets y gets de la clase
        void setNombre(string nombre);
        void setEmail(string email);
        void setTelefono(string telefono);
        void setIdentificacion(int identificacion);
        int getIdentificacion();
        //Constructores de propietario
        Propietario(); 
        Propietario(string, int, string, string);
        //Otras funciones
        void mostrarDatosPropietario();
};

#endif // PROPIETARIOVETERINARIO_H