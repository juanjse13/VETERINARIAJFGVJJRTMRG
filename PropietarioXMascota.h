#ifndef PROPIETARIOXMASCOTA_H
#define PROPIETARIOXMASCOTA_H
#include "PropietarioVeterinario.h"
#include "Mascota.h"
#include <map>

using namespace std;

class PropietarioXMascota{
    private:
        Propietario propietario;
        Mascota mascota;

    public:
        PropietarioXMascota();
        PropietarioXMascota(Propietario, Mascota);
        Propietario getPropietario();
        Mascota getMascota();
        void mostrarData();
};


#endif
