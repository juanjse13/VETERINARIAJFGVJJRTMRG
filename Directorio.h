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
        unordered_map <int, Mascota>::iterator q;
    public:
        //Otras funciones
        void agregarPropietario(Propietario);
        void agregarMascota(Mascota);
        void modificarPropietario(int);
        void eliminarPropietario(int);
        void listarPropietarios(); 
        int getCantidadPropietarios();
        void consultarMascotasParaPropietario(int);
        void consultarPropietariosParaMascota(int);
        void eliminarPropietarioAunaMascota(int);
        void pedirDatosMascota();
        void pedirDatosPropietario();
        void agregarPropietariosxMascota(int, int);
        void cambiarEstadoMascota(int, string);
        void listarMascotas();
        void eliminarMascotaAunPropietario(int);
};

#endif