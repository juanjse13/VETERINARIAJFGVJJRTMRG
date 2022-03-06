
#include"PropietarioVeterinario.h"

 Propietario::Propietario(){   // No Parameters, defect constructor
    nombre = "";
    email = "";
    identificacion = 0;
    telefono = 0;
 } 

 Propietario::Propietario(string nombre, int identificacion,string email,int telefono){
     this->nombre = nombre;
     this->identificacion = identificacion;
     this->email = email;
     this->telefono = telefono;
 } 

 void Propietario::mostrarDatosPropietario(){
     cout << "Los datos de propietario son: " << endl;
     cout << "El nombre del propietario es : " << nombre << endl;
     cout << "La dirección de correo electronico del propietario es : " << email << endl;
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

void Propietario::setTelefono(int telefono){
     this->telefono = telefono;
 }

 void Propietario::setIdentificacion(int identificacion){
     this->identificacion = identificacion;
 }