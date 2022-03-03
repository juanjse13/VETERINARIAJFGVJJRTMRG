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
    Propietario propietario(nombre,identificacion,email,telefono);
    agregarPropietarios(propietario);
}

 
void Directorio::pedirDatosMascota(){
    string typePet;
    string raza;
    float weight;
    int age;
    string typeBlood;
    string name;
    int identification;
    bool status1;
    string status;
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
    Mascota mascota(typePet,weight,age,typeBlood,name,identification,status,raza);
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
    }
    cout << "Quiere modificar su email? : "<<endl;
    cin >> verificador;
    if(verificador == true){
        cout << "cual es su email : ";
        cin >> email;
    }
    cout << "Quiere modificar su telefono? : "<<endl;
    cin >> verificador;
    if(verificador == true){
        cout << "cual es su telefono : ";
        cin >> telefono;
    }
    propModificar.setNombre(nombre);
    propModificar.setEmail(email);
    propModificar.setTelefono(telefono);
}

int Directorio::getCantidadPropietarios(){
    return mapaPropietario.size();
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
