#ifndef PROPIETARIOXMASCOTA_H
#define PROPIETARIOXMASCOTA_H
#include "Propietario.h"
#include "Mascota.h"
#include <map>


class PropietarioXMascota{
    private:
        //Atributos de la clase
        Propietario propietario;
        Mascota mascota;

    public:
        //Constructor de PropietarioXMascota
        PropietarioXMascota(Propietario, Mascota);
        //Sets y gets de la clase
        Propietario getPropietario();
        Mascota getMascota();
        void setPropietario(Propietario);
        void setMascota(Mascota);
        //Otras funciones
        void mostrarDatos();
};
#endif