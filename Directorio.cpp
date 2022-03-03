#include "Directorio.h"

void Directorio::agregarPropietarios(PropietarioXMascota proPet){
    propietariosYmascotas.push_back(proPet);
    contadorPropietarios++;
}

void Directorio::eliminarPropietario(int identification){
    for(int i = 0; i < propietariosYmascotas.size(); i++){
        if(propietariosYmascotas[i].getPropietario().getIdentificacion() == identification){
            propietariosYmascotas.erase(propietariosYmascotas.begin()+i);
        }
    }
}

void Directorio::modificarPropietario(int identification){
    for(int i = 0; i < propietariosYmascotas.size(); i++){
        if(propietariosYmascotas[i].getPropietario().getIdentificacion() == identification){
            cout<<"Modificar Valores"<<endl;
        }
    }
}

int Directorio::getCantidadPropietarios(){
    return contadorPropietarios;
}

void Directorio::listarPropietarios(){
    for(int i = 0; i < propietariosYmascotas.size(); i++){
        propietariosYmascotas[i].getPropietario().mostrarDatosPropietario();
        propietariosYmascotas[i].getMascota().mostrarDatosMascota();
        for(int j = 1; j < propietariosYmascotas.size(); j++){
            if(propietariosYmascotas[i].getPropietario().getIdentificacion() == propietariosYmascotas[j].getPropietario().getIdentificacion()){
                propietariosYmascotas[j].getMascota().mostrarDatosMascota();
            }
            else{
                propietariosYmascotas[i].getMascota().mostrarDatosMascota();
            }
        }
    }
}
