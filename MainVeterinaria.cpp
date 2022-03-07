#include "Directorio.h"


using std::cout;
using std::cin;
using std::string;

void menu(Directorio directorio){
    int opc = 0;
    int identificacion;
    int identificacionMascota;
    string fechaDeFuncion;

    do
    {
        cout << "Bienvenido a la veterinaria clinica veterinaria del sud, totti's e ramirez restrepo, su veterinaria de confianza"<<endl;
        cout << "Seleccione la opcion que desee ejecutar"<<endl;
        cout << endl;
        cout << "1.  Agregar nuevo propietario\n";
        cout << "2.  Agregar nueva mascota\n";
        cout << "3.  Modificar propietario\n";
        cout << "4.  Eliminar propietario\n";
        cout << "5.  Listar propietarios\n";
        cout << "6.  Mostrar cantidad de propietarios registrados\n";
        cout << "7.  Listar Mascotas\n";
        cout << "8.  Consultar los propietarios de una mascota\n";
        cout << "9.  Consultar las mascotas de un propietario\n";
        cout << "10. Asociar una mascota con un propietario\n";
        cout << "11. Asociar un propietario con una mascota\n";
        cout << "12. Cambiar el estado de una mascota\n";
        cout << "13. Eliminar un propietario de una mascota\n";
        cout << "14. Eliminar una mascota de un propietario"<< endl;
        cin >> opc;

        switch (opc)
        {
        case 1:
            directorio.pedirDatosPropietario();
            break;

        case 2:
            directorio.pedirDatosMascota();
            break;
        
        case 3:
            cout << "Cual es su identificacion?\n";
            cin >> identificacion;
            directorio.modificarPropietario(identificacion);
            break;

        case 4:
            cout << "Escriba la identificacion del propietario que desea eliminar\n";
            cin >> identificacion;
            directorio.eliminarPropietario(identificacion);
            break;
        
        case 5:
            directorio.listarPropietarios();
            break;
        
        case 6:
            cout << "La cantidad de propietarios registrados es " << directorio.getCantidadPropietarios() << "\n";
            break;
        
        case 7:
            directorio.listarMascotas();
            break;
        
        case 8:
            cout << "Ingrese la identificacion de la mascota\n";
            cin >> identificacionMascota;
            directorio.consultarPropietariosParaMascota(identificacionMascota);

            break;
        
        case 9:
            cout << "Ingrese la identificacion del propietario\n";
            directorio.consultarMascotasParaPropietario(identificacion);

            break;

        case 10:
            cout << "Ingrese la identificacion del propietario\n";
            cin >> identificacion;
            cout << "Ingrese la identificacion de la mascota\n";
            cin >> identificacionMascota;
            directorio.agregarPropietariosxMascota(identificacionMascota, identificacion);
            break;

        case 11:
            cout << "Ingrese la identificacion de la mascota\n";
            cin >> identificacionMascota;
            cout << "Ingrese la identificacion del propietario\n";
            cin >> identificacion;
            directorio.agregarPropietariosxMascota(identificacion, identificacionMascota);
            break;
        
        case 12:
            cout << "Ingrese la indentificacion de la mascota"<<endl;
            cin >> identificacionMascota;
            cout << "Escriba la fecha de defuncion(AAA/MMM/DDD)\n";
            cin >> fechaDeFuncion;
            directorio.cambiarEstadoMascota(identificacionMascota, fechaDeFuncion);
            
            break;

        case 13:
            cout << "Ingrese la identificacion de la mascota\n";
            cin >> identificacionMascota;
            directorio.eliminarPropietarioAunaMascota(identificacionMascota);
            break;
            
        case 14:
            cout << "Ingrese la identificacion del propietario\n";
            cin >> identificacion;
            directorio.eliminarMascotaAunPropietario(identificacion);
            break;
        
        default:
            cout << "La opcion seleccionada no es valida\n";
            break;
            
        }
    
    } while (opc != 0);

}

int main(){
 Directorio directorio;
 menu(directorio);
 return 0;
}

