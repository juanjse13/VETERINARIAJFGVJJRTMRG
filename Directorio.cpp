#include "Directorio.h"

void Directorio::pedirDatosPropietario(){
    string nombre; 
    int identificacion; 
    string email; 
    string telefono;
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
    cout << "La mascota es un : \n";
    cout << "1. perro  2. gato  3. otro\n";
    cin >> tipoMascota;
    if (tipoMascota == "1")
    {
        tipoMascota = "perro";

    }else if (tipoMascota =="2")
    {
        tipoMascota = "gato";
    }else
    {
        tipoMascota = "otro";
    }
    
    cout << "La raza del " << tipoMascota << " : ";
    cin >> raza;
    cout << "Cual es el peso de la mascota(en Kg) : ";
    cin >> peso;
    cout << "Cual es la edad de la " << tipoMascota << " : ";
    cin >> edad;
    cout << "Cual es el tipo de sangre de la " << tipoMascota << " : ";
    cin >> tipoSangre;
    cout << "Cual es el nombre del " << tipoMascota << " : ";
    cin >> nombre;
    cout << "Cual es la identificacion del " << tipoMascota << " : ";
    cin >> identificacion;
    estado = true;
    Mascota mascota(nombre,identificacion,tipoMascota,peso,edad,tipoSangre,estado,raza);
    agregarMascota(mascota);
}

void Directorio::agregarPropietariosxMascota(int identificacionPropietario,int identificacionMascota){
    bool agregarAsociacion; 
    //Se verifica que tanto el propietario como la mascota esten en el sistema
    if(mapaPropietario.find(identificacionPropietario)== mapaPropietario.end()){
        cout << "La identificacion del propietario " << identificacionPropietario << " no esta registrada"<<endl;
        if(mapaMascota.find(identificacionMascota)== mapaMascota.end()){
            cout << "La identificacion de la mascota " << identificacionMascota << " no esta registrada"<<endl;
        }
    }
    else{
        for(int i = 0; i < propietariosYmascotas.size(); i++){
            //Un if que permite revisar si la relacion ya esta creada en el sistema
            if (propietariosYmascotas[i].getPropietario().getIdentificacion() == identificacionPropietario && 
                propietariosYmascotas[i].getMascota().getIdentificacion() == identificacionMascota)
            {
                cout << "La relacion ya existe en el sistema\n";
                agregarAsociacion = false;
            }
        }
        //Si agregarAsociacon == true es porque la relacion no existe en el sistema, luego pasamos a crearla
        if (agregarAsociacion == true)
        {
            PropietarioXMascota propxmas(mapaPropietario[identificacionPropietario],mapaMascota[identificacionMascota]);
            propietariosYmascotas.push_back(propxmas);
            cout << "El procedimiento de asociacion ha sido exitoso\n";
        }
               
    }
        
}

void Directorio::agregarPropietario(Propietario propietario){
    if(mapaPropietario.find(propietario.getIdentificacion())== mapaPropietario.end()){
        mapaPropietario[propietario.getIdentificacion()] = propietario;
    }
    else{
        cout << "La identificacion para propietario " << propietario.getIdentificacion() << " ya esta registrada, no se puede agregar"<<endl;
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
        cout << "El propietario con identificacion " << identificacion << " ha sido eliminado\n";
    }else{
        cout << "El propietario con identificacion " << identificacion << " no existe en el sistema\n";
    }

        
}

void Directorio::modificarPropietario(int identificacionAntigua){
    if(mapaPropietario.find(identificacionAntigua)!= mapaPropietario.end()){ // Buscamos la llave en el mapa (identificacionAntigua)
         //indentificacionAntigua corresponde a la identificacion vieja--identificacion corresponde a la nueva identificacion
        Propietario propModificar = mapaPropietario[identificacionAntigua];
        string nombre; 
        int identificacion; 
        string email; 
        bool verificador;
        string telefono;

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

    }else{
        cout << "El propietario con numero de identificacion " << identificacionAntigua << " no existe\n";
    }

}

int Directorio::getCantidadPropietarios(){
    return mapaPropietario.size();
}

void Directorio::listarPropietarios(){
    for(p = mapaPropietario.begin(); p != mapaPropietario.end(); p++ ){
        cout<<"Para el usuario identificado con el numero: "<< p->first<< endl;
        p->second.mostrarDatosPropietario();
        cout << "\n";
    }
        
}

void Directorio::listarMascotas(){
    for(q = mapaMascota.begin(); q != mapaMascota.end(); q++ ){
        cout<<"Para la mascota identificada con el numero: "<< q->first<<endl;
        q->second.mostrarDatosMascota();
        cout << "\n";
    }
}

void Directorio::consultarMascotasParaPropietario(int identificacion){
    //Esta variable ayudara en crear un if que desplegara un mensaje si el propietario no tiene mascotas asociadas
    bool tieneMascotas;
    if(mapaPropietario.find(identificacion)!= mapaPropietario.end()){
        cout << "Las mascotas que tiene el propietario con identificacion " << identificacion << " son:\n";
        for(int i = 0; i < propietariosYmascotas.size(); i++){
            if(propietariosYmascotas[i].getPropietario().getIdentificacion() == identificacion){
                propietariosYmascotas[i].getMascota().mostrarDatosMascota();
                cout << "\n";
                tieneMascotas = true;
            }
                
        }
        if (tieneMascotas == false)
        {
            cout << "El propietario no tiene mascotas asociadas\n";
        }   
    }else{
        cout << "El propietario con numero de identificacion " << identificacion << " no existe\n";
    }
    
}

void Directorio::consultarPropietariosParaMascota(int identificacion) {  
    //Esta variable ayudara en crear un if que desplegara un mensaje si la mascota no tiene propietarios asociados
    bool tienePropietarios;
    if(mapaMascota.find(identificacion)!= mapaMascota.end()){
        cout << "Los propietarios que tiene la mascota con identificacion " << identificacion << " son:\n";
        for(int i = 0; i < propietariosYmascotas.size(); i++){
            if(propietariosYmascotas[i].getMascota().getIdentificacion() == identificacion){
                propietariosYmascotas[i].getPropietario().mostrarDatosPropietario();
                 cout << "\n";
                tienePropietarios = true;
            }
        }
        if (tienePropietarios == false)
        {
            cout << "La mascota no tiene propietarios asociados\n";
        }   
    }else{
        cout << "La mascota con numero de identificacion " << identificacion << " no existe\n";
    }
}

void Directorio::cambiarEstadoMascota(int identificacionMascota, string fechaDeFuncion){
    if(mapaMascota.find(identificacionMascota)!= mapaMascota.end()){
        mapaMascota[identificacionMascota].setEstadoMascota(false);
        mapaMascota[identificacionMascota].setFechaDeFuncion(fechaDeFuncion);
        cout << "Estado de la mascota cambiado\n";

    }
        
    else{
        cout<<"La identificacion " << identificacionMascota << " no esta registrada" << endl;
    }
}