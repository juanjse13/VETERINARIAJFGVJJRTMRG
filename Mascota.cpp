#include "Mascota.h" //string included
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

Mascota::Mascota(){
    tipoMascota = "";
    peso = 0.0;
    edad = 0;
    tipoSangre = "";
    nombre = "";
    identificacion = 0;
    estado = true;
    fechaDeFuncion = ""; //Inicialmente la mascota se crea en el sistema con un estado "viva" y este atributo no tendría ningún valor
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
    //Para mostrar los datos simplmente se imprimen en pantalla los valores que contengan cada uno de los atributos de la instancia
    string estadoVivoMuerto; //Se define esta variable para almacenar el valor de un string que indique el estado de la mascota
    cout << "Los datos de la mascota son : "<<endl;
    cout <<"La mascota es un : "<< tipoMascota <<endl;
    cout << "El peso de la mascota es : " << peso << endl;
    cout << "La edad de la mascota es : " << edad << endl;
    cout << "El tipo de sangre de la mascota es : " << tipoSangre << endl;
    cout << "El nombre de la mascota es : " << nombre << endl;
    cout << "La identificacion de la mascota es : " << identificacion << endl;

    //Pensando en la comodidad del usuario, se crea este if para que la persona puede ver de manera más clara el estado de la mascota
    if (estado == 1)
    {
        estadoVivoMuerto = "Vivo(a)";
    }else{
        estadoVivoMuerto = "Fallecido(a)";
    }
    
    cout << "El estado de la mascota es : " << estadoVivoMuerto << endl;
    cout << "La raza de la mascota es : " << raza << endl;
    if (estado == false){
        cout << "La fecha de defuncion de la mascota es : "<< fechaDeFuncion;
    } 
}

int Mascota::getIdentificacion(){
    return this->identificacion;
}

void Mascota::setEstadoMascota(bool estado){
    this->estado = estado;
}

void Mascota::setFechaDeFuncion(string fechaDeFuncion){
    this ->fechaDeFuncion = fechaDeFuncion;
}



