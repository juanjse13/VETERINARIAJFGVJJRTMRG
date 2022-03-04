#include "Directorio.h"

void Directorio::pedirDatosPropietario(){
    string nombre; 
    int identificacion; 
    string email; 
    int telefono;
    cout << "cual es su nombre : ";
    cin >> nombre;
    cout << "cual es su identificacion : ";
    cin >> identificacion;
    cout << "cual es su email : ";
    cin >> email;
    cout << "cual es su telefono : ";
    cin >> telefono;
    Propietario propietario1(nombre,identificacion,email,telefono);
    agregarPropietario(propietario1);
}

 
void Directorio::pedirDatosMascota(){
    string typePet;
    string raza;
    float weight;
    int age;
    string typeBlood;
    string name;
    int identification;
    bool status;
    string dateFall;
    cout << "Su mascota es un : ";
    cin >> typePet;
    cout << "Que raza es su " << typePet << " : ";
    cin >> raza;
    cout << "Cual es el peso de su mascota : ";
    cin >> weight;
    cout << "Cual es la edad de su " << typePet << " : ";
    cin >> age;
    cout << "Cual es el tipo de sangre de su mascota : ";
    cin >> typeBlood;
    cout << "Cual es el nombre de su mascota : ";
    cin >> name;
    cout << "Cual es la identificacion de su mascota : ";
    cin >> identification;
    status = false;
    Mascota mascota(name,identification,typePet,weight,age,typeBlood,status,raza);
    agregarMascota(mascota);
}

void Directorio::agregarPropietariosxMascota(int identificacionPropietario,int identificacionMascota){
    PropietarioXMascota propxmas(mapaPropietario[identificacionPropietario],mapaMascota[identificacionMascota]);
    propietariosYmascotas.push_back(propxmas);
}

void Directorio::agregarPropietario(Propietario propietario){
    mapaPropietario[propietario.getIdentificacion()] = propietario;
}

void Directorio::agregarMascota(Mascota mascota){
    mapaMascota[mascota.getIdentification()] = mascota;
}


void Directorio::eliminarPropietarioAunaMascota(int identification){
    for(int i = 0; i < propietariosYmascotas.size(); i++){
        if(propietariosYmascotas[i].getPropietario().getIdentificacion() == identification){
            propietariosYmascotas.erase(propietariosYmascotas.begin()+i);
        }
    }
}

void Directorio::eliminarPropietario(int identification){
    if(mapaPropietario.find(identification)!= mapaPropietario.end()){ // Buscamos la llave en el mapa (identificacion)
        mapaPropietario.erase(identification);
    }
}

void Directorio::modificarPropietario(int identification){
    Propietario propModificar = mapaPropietario[identification];
    string nombre; 
    int identificacion; 
    string email; 
    bool verificador;
    int telefono;
    cout << "Quiere modificar su nombre? : "<<endl;
    cin >> verificador;
    if(verificador == true){
        cout << "cual es su nombre : ";
        cin >> nombre;
        propModificar.setNombre(nombre);
    }
    cout << "Quiere modificar su email? : "<<endl;
    cin >> verificador;
    if(verificador == true){
        cout << "cual es su email : ";
        cin >> email;
        propModificar.setEmail(email);
    }
    cout << "Quiere modificar su telefono? : "<<endl;
    cin >> verificador;
    if(verificador == true){
        cout << "cual es su telefono : ";
        cin >> telefono;
        propModificar.setTelefono(telefono);
    }
}

int Directorio::getCantidadPropietarios(){
    return mapaPropietario.size();
}

void Directorio::listarPropietarios(){
    for(p = mapaPropietario.begin(); p != mapaPropietario.end(); p++ ){
        cout<<"Para el usuario identificado con el numero;"<< p->first<< endl;
        p->second.mostrarDatosPropietario();
    }
}

void Directorio::consultarMascotasParaPropietario(int identificacion){
    for(int i = 0; i < propietariosYmascotas.size(); i++){
        if(propietariosYmascotas[i].getPropietario().getIdentificacion() == identificacion){
            propietariosYmascotas[i].getMascota().mostrarDatosMascota();
        }
    }
}

void Directorio::consultarPropietariosParaMascota(int identificacion) {  
    for(int i = 0; i < propietariosYmascotas.size(); i++){
        if(propietariosYmascotas[i].getMascota().getIdentification() == identificacion){
            propietariosYmascotas[i].getPropietario().mostrarDatosPropietario();
        }
    }
}