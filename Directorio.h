
#ifndef DIRECTORIO_H
#define DIRECTORIO_H
#include <iostream>
#include "PropietarioXMascota.h"
#include <unordered_map>
#include <vector>

using std::string;
using std::cin;
using std::cout;
using std::unordered_map;
using std::vector;

class Directorio{
    private:
        //Atributos de la clase
        vector <PropietarioXMascota> propietariosYmascotas;
        unordered_map <int, Propietario> mapaPropietario;
        unordered_map <int, Mascota> mapaMascota;
        unordered_map <int, Propietario>::iterator p;
    public:
        //Otras funciones
        void agregarPropietario(Propietario propietario);
        void agregarMascota(Mascota mascota);
        void modificarPropietario(int identificacion);
        void eliminarPropietario(int identificacion);
        void listarPropietarios(); 
        int getCantidadPropietarios();
        void consultarMascotasParaPropietario(int identificacion);
        void consultarPropietariosParaMascota(int identificacion);
        void eliminarPropietarioAunaMascota(int identificacion);
        void pedirDatosMascota();
        void pedirDatosPropietario();
        void agregarPropietariosxMascota(int, int);
        
        
        
        
        
        
       
};

#endif