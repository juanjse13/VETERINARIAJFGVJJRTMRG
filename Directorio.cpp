#include "Directorio.h"

void Directorio::pedirDatosPropietario(){
    string nombre; 
    int identificacion; 
    string email; 
    int telefono;
    cout << "Cual es su nombre? : ";
    cin >> nombre;
    cout << "Cual es su identificacion? : ";
    cin >> identificacion;
    cout << "Cual es su email?: ";
    cin >> email;
    cout << "Cual es su telefono? : ";
    cin >> telefono;
    Propietario propietario1(nombre,identificacion,email,telefono);
    agregarPropietario(propietario1);
}

 
void Directorio::pedirDatosMascota(){
    string tipoMascota;
    string raza;
    float peso;
    int edad;
    string tipoSangre;
    string nombre;
    int identificacion;
    bool estado;
    string fechaDefuncion;
    cout << "Su mascota es un : ";
    cin >> tipoMascota;
    cout << "Que raza es su " << tipoMascota << " : ";
    cin >> raza;
    cout << "Cual es el peso de su mascota : ";
    cin >> peso;
    cout << "Cual es la edad de su " << tipoMascota << " : ";
    cin >> edad;
    cout << "Cual es el tipo de sangre de su " << tipoMascota << " : ";
    cin >> tipoSangre;
    cout << "Cual es el nombre de su mascota " << tipoMascota << " : ";
    cin >> nombre;
    cout << "Cual es la identificacion de su " << tipoMascota << " : ";
    cin >> identificacion;
    status = true;
    Mascota mascota(nombre,identificacion,tipoMascota,peso,edad,tipoSangre,estado,raza);
    agregarMascota(mascota);
}

void Directorio::agregarPropietariosxMascota(int identificacionPropietario,int identificacionMascota){
    if(mapaPropietario.find(identificacion) == mapaPropietario.end() || mapaPropietario.find(identificacion) == mapaPropietario.end() ){ 
        mapaPropietario[propietario.getIdentificacion()] = propietario;
    }
    PropietarioXMascota propxmas(mapaPropietario[identificacionPropietario],mapaMascota[identificacionMascota]);
    propietariosYmascotas.push_back(propxmas);
}

void Directorio::agregarPropietario(Propietario propietario){
    if(mapaPropietario.find(identificacion) == mapaPropietario.end()){ 
        mapaPropietario[propietario.getIdentificacion()] = propietario;
    }
    else{
        cout << "El propietario ya existe en el sistema. No se puede ingresar\n";
    }
}

void Directorio::agregarMascota(Mascota mascota){
    if(mapaMascota.find(identificacion) == mapaMascota.end()){ 
        mapaMascota[mascota.getIdentificacion()] = mascota;
    }
    else{
        cout << "La mascota ya existe en el sistema. No se puede ingresar\n";
    }
    
}


void Directorio::eliminarPropietarioAunaMascota(int identificacion){
    for(int i = 0; i < propietariosYmascotas.size(); i++){
        if(propietariosYmascotas[i].getPropietario().getIdentificacion() == identificacion){
            propietariosYmascotas.erase(propietariosYmascotas.begin()+i);
        }
    }
}

void Directorio::eliminarPropietario(int identificacion){
    if(mapaPropietario.find(identificacion)!= mapaPropietario.end()){ // Buscamos la llave en el mapa (identificacion)
        mapaPropietario.erase(identificacion);
    }
}

void Directorio::modificarPropietario(int identificacionAntigua){

    //indentificacionAntigua corresponde a la identificacion vieja--identificacion corresponde a la nueva identificacion
    Propietario propModificar = mapaPropietario[identificacionAntigua];
    string nombre; 
    int identificacion; 
    string email; 
    bool verificador;
    int telefono;

    cout << "Quiere modificar su nombre? : "<<endl;
    cin >> verificador;
    if(verificador == true){
        cout << "Cual es su nombre : ";
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

    cout << "Quiere modificar su identificacion? : "<<endl;
    cin >> verificador;
    if(verificador == true){
        cout << "cual es su nueva identificacion? : ";
        cin >> identificacion;
        propModificar.setIdentificacion(identificacion);
        mapaPropietario.erase(identificacionAntigua);
        mapaPropietario[identificacion] = propModificar;

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
        if(propietariosYmascotas[i].getMascota().getIdentificacion() == identificacion){
            propietariosYmascotas[i].getPropietario().mostrarDatosPropietario();
        }
    }
}