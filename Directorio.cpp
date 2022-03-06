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
    estado = true;
    Mascota mascota(nombre,identificacion,tipoMascota,peso,edad,tipoSangre,estado,raza);
    agregarMascota(mascota);
}

void Directorio::agregarPropietariosxMascota(int identificacionPropietario,int identificacionMascota){
    if(mapaPropietario.find(identificacionPropietario)== mapaPropietario.end()){
        cout << "La identificacion " << identificacionPropietario << "no estan registrada"<<endl;
        if(mapaMascota.find(identificacionMascota)== mapaMascota.end()){
            cout << "La identificacion " << identificacionMascota << "no estan registrada"<<endl;
        }
    }
    else{
        PropietarioXMascota propxmas(mapaPropietario[identificacionPropietario],mapaMascota[identificacionMascota]);
        propietariosYmascotas.push_back(propxmas);
    }
}

void Directorio::agregarPropietario(Propietario propietario){
    if(mapaPropietario.find(propietario.getIdentificacion())== mapaPropietario.end()){
        mapaPropietario[propietario.getIdentificacion()] = propietario;
    }
    else{
        cout << "La identificacion para propietario " << propietario.getIdentificacion() << " ya esta registrada, no se puede añadir"<<endl;
    }
}

void Directorio::agregarMascota(Mascota mascota){
    if(mapaMascota.find(mascota.getIdentificacion())== mapaMascota.end()){
        mapaMascota[mascota.getIdentificacion()] = mascota;
    }
    else{
        cout << "La identificacion para mascota " << mascota.getIdentificacion() << " ya esta registrada, no se puede añadir"<<endl;
    }
}


void Directorio::eliminarPropietarioAunaMascota(int identificacion){
    for(int i = 0; i < propietariosYmascotas.size(); i++){
        if(propietariosYmascotas[i].getPropietario().getIdentificacion() == identificacion){
            propietariosYmascotas.erase(propietariosYmascotas.begin()+i);
        }
    }
}

void Directorio::eliminarMascotaAunPropietario(int identificacion){
    for(int i = 0; i < propietariosYmascotas.size(); i++){
        if(propietariosYmascotas[i].getMascota().getIdentificacion() == identificacion){
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

void Directorio::listarMascotas(){
    for(q = mapaMascota.begin(); q != mapaMascota.end(); q++ ){
        cout<<"Para la mascota identificada con el numero;"<< p->first<<endl;
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

void Directorio::cambiarEstadoMascota(int identificacionMascota){
    if(mapaMascota.find(identificacionMascota)!= mapaMascota.end()){
        mapaMascota[identificacionMascota].setEstadoMascota(false);
    }
    else{
        cout<<"La identificacion" << identificacionMascota << "no esta registrada" << endl;
    }
}