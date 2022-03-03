#include "PropietarioXMascota.h"

PropietarioXMascota::PropietarioXMascota(){

}

PropietarioXMascota::PropietarioXMascota(Propietario propietario, Mascota mascota):PropietarioXMascota(){
    this->propietario = propietario;
    this->mascota = mascota;
}

void PropietarioXMascota::mostrarData(){
    propietario.mostrarDatosPropietario();
    mascota.mostrarDatosMascota();
}

Propietario PropietarioXMascota::getPropietario(){
    return propietario;
}

Mascota PropietarioXMascota::getMascota(){
    return mascota;
}