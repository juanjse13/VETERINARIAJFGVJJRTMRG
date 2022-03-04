#ifndef MASCOTA_H
#define MASCOTA_H

#include<iostream>

using std::string;

class Mascota{
    private:
        string typePet;
        string raza;
        float weight;
        int age;
        string typeBlood;
        string name;
        int identification;
        bool status;
        string dateFall;
    public:
        Mascota();
        Mascota(string, int, string, float, int, string, bool, string);
        int getIdentification();
        void mostrarDatosMascota();
        string getStatusPet();
        void cambiarStatusMascota();
};

#endif