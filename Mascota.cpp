
#include "Mascota.h" //string included
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

Mascota::Mascota(){
    tipoMascota = "";
    peso = 0.0;
    edad = 0;
    tipoSangre = "";
    nombre = "";
    identificacion = 0;
    estado = true;
    fechaDefuncion = "";
    raza = "";
}

Mascota::Mascota(string nombre, int identificacion, string tipoMascota, float peso, int edad, string tipoSangre, bool estado, string raza){
    this->nombre = nombre;
    this->identificacion = identificacion;
    this->tipoMascota = tipoMascota;
    this->peso = peso;
    this->edad = edad;
    this->tipoSangre = tipoSangre;
    this->estado = estado;
    this->raza = raza;
}

string Mascota::getEstadoMascota(){
    if (estado){
        return "Viva";
    } 
    else{
        return "Fallecida";
    }
}

void Mascota::mostrarDatosMascota(){
    cout << "Los datos de la mascota son : "<<endl;
    cout <<"La mascota es un : "<< tipoMascota <<endl;
    cout << "El peso de la mascota es : " << peso << endl;
    cout << "La edad de la mascota es : " << edad << endl;
    cout << "El tipo de sangre de la mascota es : " << tipoSangre << endl;
    cout << "El nombre de la mascota es : " << nombre << endl;
    cout << "La identificacion de la mascota es : " << identificacion << endl;
    cout << "El estado de la mascota es : " << estado << endl;
    cout << "La raza de la mascota es : " << raza << endl;
    if (estado == false){
        cout << "La fecha de defuncion de la mascota es : "<<endl;
    } 
}

int Mascota::getIdentificacion(){
    return this->identificacion;
}

void Mascota::cambiarEstadoMascota(){
    //False corresponde a mascota fallecida
    this->estado = false;
}




