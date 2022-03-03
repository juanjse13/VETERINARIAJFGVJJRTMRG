#include "Directorio.h"
#include "PropietarioXMascota.h"

int main(){

    Propietario prop1("Juan",12345,"Juan@javerianacali.edu.co",30084);
    Mascota pet1("Teo", 114, "perro", 12.5,3,"O+",false);
    PropietarioXMascota junt1(prop1,pet1);
    Propietario prop2("Julian",17892,"Julian@javerianacali.edu.co",10063);
    Mascota pet2("kanibal", 150, "gato", 34.7,3,"A+",true);
    PropietarioXMascota junt2(prop2,pet2);
    Propietario prop3("Jairo",18903,"Jairo@javerianacali.edu.co",10063);
    PropietarioXMascota junt3(prop3,pet2);
    //junt1.mostrarData();
    //junt2.mostrarData();
    Directorio directorio;
    //directorio.agregarPropietarios(junt1);
    //directorio.agregarPropietarios(junt2);
    //directorio.agregarPropietarios(junt3);
    //directorio.listarPropietarios();
    //directorio.eliminarPropietario(150);
    //directorio.listarPropietarios();
    //cout<<directorio.getCantidadPropietarios()<<endl;
}
