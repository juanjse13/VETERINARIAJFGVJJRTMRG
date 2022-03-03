
#ifndef DIRECTORIO_H
#define DIRECTORIO_H
#include "PropietarioXMascota.h"
#include <map>
#include <vector>

using namespace std;

class Directorio{
    private:
        int contadorPropietarios;
        vector <PropietarioXMascota> propietariosYmascotas;

    public:
        void agregarPropietarios(PropietarioXMascota);
        void eliminarPropietario(int identification);
        void modificarPropietario(int identification);
        void listarPropietarios(); 
        int getCantidadPropietarios();
};

#endif