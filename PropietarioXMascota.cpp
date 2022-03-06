#include "PropietarioXMascota.h"


PropietarioXMascota::PropietarioXMascota(Propietario propietario, Mascota mascota){
    this->propietario = propietario;
    this->mascota = mascota;
}

void PropietarioXMascota::mostrarDatos(){
    propietario.mostrarDatosPropietario();
    mascota.mostrarDatosMascota();
}

Propietario PropietarioXMascota::getPropietario(){
    return propietario;
}

Mascota PropietarioXMascota::getMascota(){
    return mascota;
}

