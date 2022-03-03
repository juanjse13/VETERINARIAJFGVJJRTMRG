
#include "Mascota.h" //string included
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

Mascota::Mascota(){
    typePet = "";
    weight = 0.0;
    age = 0;
    typeBlood = "";
    name = "";
    identification = 0;
    status = false;
    dateFall = "";
}

Mascota::Mascota(string name, int identification, string typePet, float weight, int age, string typeBlood, bool status):Mascota(){
    this->name = name;
    this->identification = identification;
    this->typePet = typePet;
    this->weight = weight;
    this->age = age;
    this->typeBlood = typeBlood;
    this->status = status;
}

string Mascota::getStatusPet(){
    if (!status){
        return "viva";
    } 
    else{
        return "muerta";
    }
}

void Mascota::mostrarDatosMascota(){
    cout << "Los Datos de la mascota son : "<<endl;
    cout <<"La mascota es un : "<< typePet <<endl;
    cout << "El peso de la mascota es : " << weight << endl;
    cout << "La edad de la mascota es : " << age << endl;
    cout << "El tipo de sangre de la mascota es : " << typeBlood << endl;
    cout << "El nombre de la mascota ees : " << name << endl;
    cout << "La identificacion de la mascota es : " << identification << endl;
    cout << "El estado de la mascota es : " << getStatusPet() << endl;
    if (status == true){
        cout << "La fecha de defucion de la mascota es : "<<endl;
    } 
}




