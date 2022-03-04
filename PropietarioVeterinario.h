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
        // Respect Atributes
        string nombre;
        string email;
        int identificacion;
        int telefono;
    public:
        // Buildings by Propietarios classes
        void setNombre(string nombre);
        void setEmail(string email);
        void setTelefono(int telefono);
        Propietario(); 
        Propietario(string, int, string, int);
        int getIdentificacion();
        void mostrarDatosPropietario();
};

#endif // PROPIETARIOVETERINARIO_H