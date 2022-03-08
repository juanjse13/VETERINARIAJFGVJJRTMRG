#include "Directorio.h"

void Directorio::pedirDatosPropietario(){
    //Se piden los datos del propietario y se almacenan en variables
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
    //Se crea la instancia de propietario mediante el constructor con parámetros
    Propietario propietario1(nombre,identificacion,email,telefono);
    /*Mediante el método que tiene el directorio(agregarPropietario) se guarda la instancia previamente 
    creada en el mapa correspondiente a los propietarios*/
    agregarPropietario(propietario1);
}

 
void Directorio::pedirDatosMascota(){
    //Se piden los datos del propietario y se almacenan en variables
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
    //Este if permite almacenar y relacionar el tipo de Mascota con un string
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

    //Se crea la instancia de propietario mediante el constructor con parámetros
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
    //Se crea la instancia de propietario mediante el constructor con parámetros
    Mascota mascota(nombre,identificacion,tipoMascota,peso,edad,tipoSangre,estado,raza);
    /*Mediante el método que tiene el directorio(agregarMascota) se guarda la instancia previamente 
    creada en el mapa correspondiente a las mascotas*/
    agregarMascota(mascota);
}

void Directorio::agregarPropietariosxMascota(int identificacionPropietario,int identificacionMascota){
    bool agregarAsociacion = true; 
    //Se verifica que tanto el propietario como la mascota esten en el sistema
    if(mapaPropietario.find(identificacionPropietario)== mapaPropietario.end() || mapaMascota.find(identificacionMascota)== mapaMascota.end()){
        cout << "No es posible realizar la asociacion, porque una de las identificaciones no se encuentra en el sistema\n";
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
            /*Se crea la asociación y se almacena en el vector. Se guarda el propietario que 
            tenga la llave identificacionPropietario y la mascota que tenga la llave identificacionMascota*/
            PropietarioXMascota propxmas(mapaPropietario[identificacionPropietario],mapaMascota[identificacionMascota]);
            propietariosYmascotas.push_back(propxmas);
            cout << "El procedimiento de asociacion ha sido exitoso\n";
        }
               
    }
        
}

void Directorio::agregarPropietario(Propietario propietario){
    //Este if sirve para asegurarnos que el propietario no esté previamente creado y que dos propietarios no tengan la misma identificación
    if(mapaPropietario.find(propietario.getIdentificacion())== mapaPropietario.end()){
        mapaPropietario[propietario.getIdentificacion()] = propietario;
    }
    else{
        cout << "La identificacion para propietario " << propietario.getIdentificacion() << " ya esta registrada, no se puede agregar"<<endl;
    }
}

void Directorio::agregarMascota(Mascota mascota){
    //Este if sirve para asegurarnos que la mascota no esté previamente creada y que dos mascotas no tengan la misma identificación
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
            //Se le suma begin()+i, para llegar al indice en donde se desea borrar
            propietariosYmascotas.erase(propietariosYmascotas.begin()+i);
        }
    }
}

void Directorio::eliminarMascotaAunPropietario(int identificacion){
    for(int i = 0; i < propietariosYmascotas.size(); i++){
        //Se le suma begin()+i, para llegar al indice en donde se desea borrar
        if(propietariosYmascotas[i].getMascota().getIdentificacion() == identificacion){
            propietariosYmascotas.erase(propietariosYmascotas.begin()+i);
        }
    }
}

void Directorio::eliminarPropietario(int identificacion){
    //Este if permite verificar si el propietarios con la identificacion seleccionada, está registrado en el mapa o no
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
        Propietario propModificar = mapaPropietario[identificacionAntigua]; //Se realiza una copia a la instancia previamente almacenada en el mapa
        string nombre; 
        int identificacion; 
        string email; 
        int verificador;
        string telefono;

        cout << "Quiere modificar su nombre? : 1.Si 2. No "<<endl;
        cin >> verificador;
        if(verificador == 1){
            cout << "Cual es su nombre : ";
            cin >> nombre;
            //Para modificar la instancia
            propModificar.setNombre(nombre);
            //Para modificar en el mapa
            mapaPropietario[identificacionAntigua].setNombre(nombre);
            
        }

        cout << "Quiere modificar su email? : 1.Si 2. No"<<endl;
        cin >> verificador;
        if(verificador == 1){
            cout << "cual es su email : ";
            cin >> email;
            //Para modificar la instancia
            propModificar.setEmail(email);
            //Para modificar en el mapa
            mapaPropietario[identificacionAntigua].setEmail(email);
        }

        cout << "Quiere modificar su telefono? : 1.Si 2. No "<<endl;
        cin >> verificador;
        if(verificador == 1){
            cout << "cual es su telefono : ";
            cin >> telefono;
            //Para modificar la instancia
            propModificar.setTelefono(telefono);
            //Para modificar en el mapa
            mapaPropietario[identificacionAntigua].setTelefono(telefono);
        }

        cout << "Quiere modificar su identificacion? : 1.Si 2. No "<<endl;
        cin >> verificador;
        if(verificador == 1){
            cout << "Cual es su nueva identificacion? : ";
            cin >> identificacion;
            //Para modificar la instancia
            propModificar.setIdentificacion(identificacion);
            //Para modificar el mapa
            mapaPropietario.erase(identificacionAntigua); //Se borra del mapa el propietario que tenia asociado la llave identificacionAntigua
            mapaPropietario[identificacion] = propModificar; /*La instancia que se había copiado al principio es añadida al mapa 
            con el nuevo número de identificación*/
            //Esto nos ayuda a cambiar y modificar la identificacion del propietario en el vector de asociaciones
            identificacionAntigua = identificacion;
        }

        //Para modificar la información en el vector de las asociaciones entre Mascotas y Propietarios
        for (int i = 0; i < propietariosYmascotas.size(); i++)
        {
            // Se modifica el propietario que aparece en el vector por el propietario modificado(con los parámetros nuevos)
            if(propietariosYmascotas[i].getPropietario().getIdentificacion() == identificacionAntigua){
                propietariosYmascotas[i].setPropietario(propModificar);
            }
        }  

    }else{
        cout << "El propietario con numero de identificacion " << identificacionAntigua << " no existe\n";
    }

}

int Directorio::getCantidadPropietarios(){
    return mapaPropietario.size();
}

void Directorio::listarPropietarios(){
    //Se utiliza el iterador para recorrer el mapa
    for(p = mapaPropietario.begin(); p != mapaPropietario.end(); p++ ){
        cout<<"Para el usuario identificado con el numero: "<< p->first<< endl;
        p->second.mostrarDatosPropietario();
        cout << "\n";
    }
        
}

void Directorio::listarMascotas(){
    //Se utiliza el iterador para recorrer el mapa
    for(q = mapaMascota.begin(); q != mapaMascota.end(); q++ ){
        cout<<"Para la mascota identificada con el numero: "<< q->first<<endl;
        q->second.mostrarDatosMascota();
        cout << "\n";
    }
}

void Directorio::consultarMascotasParaPropietario(int identificacion){
    //Esta variable ayudara en crear un if que desplegara un mensaje si el propietario no tiene mascotas asociadas
    bool tieneMascotas;
    if(mapaPropietario.find(identificacion)!= mapaPropietario.end()){ //Se revisa si el propietario está registrado
        cout << "Las mascotas que tiene el propietario con identificacion " << identificacion << " son:\n";
        for(int i = 0; i < propietariosYmascotas.size(); i++){
            if(propietariosYmascotas[i].getPropietario().getIdentificacion() == identificacion){
                //Se accede al método público de la clase PropietarioXMascota y a su vez se accede al método público de la clase Propietario
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
    if(mapaMascota.find(identificacion)!= mapaMascota.end()){ //Se revisa si la mascota está registrada
        cout << "Los propietarios que tiene la mascota con identificacion " << identificacion << " son:\n";
        for(int i = 0; i < propietariosYmascotas.size(); i++){
            if(propietariosYmascotas[i].getMascota().getIdentificacion() == identificacion){
                //Se accede al método público de la clase PropietarioXMascota y a su vez se accede al método público de la clase Mascota
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
    if(mapaMascota.find(identificacionMascota)!= mapaMascota.end()){ //Se revisa si la mascota está registrada
        mapaMascota[identificacionMascota].setEstadoMascota(false); //Se le cambia al estado a "fallecida"
        mapaMascota[identificacionMascota].setFechaDeFuncion(fechaDeFuncion); //Se define la fecha de defunción de la mascota
        cout << "Estado de la mascota cambiado\n";

    }
        
    else{
        cout<<"La identificacion " << identificacionMascota << " no esta registrada" << endl;
    }
}