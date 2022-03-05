#ifndef PROPIETARIOXMASCOTA_H
#define PROPIETARIOXMASCOTA_H
#include "PropietarioVeterinario.h"
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
        //Otras funciones
        void mostrarDatos();
};
#endif
