
#ifndef DIRECTORIO_H
#define DIRECTORIO_H
#include <iostream>
#include "PropietarioXMascota.h"
#include <unordered_map>
#include <vector>

using namespace std;

class Directorio{
    private:
        vector <PropietarioXMascota> propietariosYmascotas;
        unordered_map <int, Propietario> mapaPropietario;
        unordered_map <int, Mascota> mapaMascota;
        unordered_map <int, Propietario>::iterator p;
    public:
        void eliminarPropietarioAunaMascota(int identification);
        void pedirDatosMascota();
        void agregarMascota(Mascota mascota);
        void pedirDatosPropietario();
        void agregarPropietariosxMascota(int, int);
        void agregarPropietario(Propietario propietario);
        void eliminarPropietario(int identification);
        void modificarPropietario(int identification);
        void listarPropietarios(); 
        int getCantidadPropietarios();
        void consultarMascotasParaPropietario(int identificacion);
        void consultarPropietariosParaMascota(int identificacion);
};

#endif