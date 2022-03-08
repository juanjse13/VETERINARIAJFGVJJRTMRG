
#include"Propietario.h"

 Propietario::Propietario(){   // No Parameters, defect constructor
    nombre = "";
    email = "";
    identificacion = 0;
    telefono = "";
 } 

 Propietario::Propietario(string nombre, int identificacion, string email, string telefono){
     this->nombre = nombre;
     this->identificacion = identificacion;
     this->email = email;
     this->telefono = telefono;
 } 

 void Propietario::mostrarDatosPropietario(){
     //Para mostrar los datos simplmente se imprimen en pantalla los valores que contengan cada uno de los atributos de la instancia
     cout << "Los datos de propietario son: " << endl;
     cout << "El nombre del propietario es : " << nombre << endl;
     cout << "La direccion de correo electronico del propietario es : " << email << endl;
     cout << "La identificacion del propietario es : " << identificacion << endl;
     cout << "El numero de telefono del propietario es : " << telefono << endl;
 }

 int Propietario::getIdentificacion(){
     return identificacion;
 }

 void Propietario::setNombre(string nombre){
     this->nombre = nombre;
 }

 void Propietario::setEmail(string email){
     this->email = email;
 }

void Propietario::setTelefono(string telefono){
     this->telefono = telefono;
 }

 void Propietario::setIdentificacion(int identificacion){
     this->identificacion = identificacion;
 }