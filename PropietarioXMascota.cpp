#include "PropietarioXMascota.h"


PropietarioXMascota::PropietarioXMascota(Propietario propietario, Mascota mascota){
    this->propietario = propietario;
    this->mascota = mascota;
}

void PropietarioXMascota::mostrarDatos(){
    //Para mostrar los datos se aprovechan los métodos públicos a los que tiene acceso tanto para propietario como para mascota
    propietario.mostrarDatosPropietario();
    mascota.mostrarDatosMascota();
}

Propietario PropietarioXMascota::getPropietario(){
    return propietario;
}

Mascota PropietarioXMascota::getMascota(){
    return mascota;
}

void PropietarioXMascota::setPropietario(Propietario propietario){
    this ->propietario = propietario;

}
void PropietarioXMascota::setMascota(Mascota mascota){
    this ->mascota = mascota;

}

