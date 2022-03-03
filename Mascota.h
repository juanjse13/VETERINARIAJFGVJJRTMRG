#ifndef MASCOTA_H
#define MASCOTA_H

#include<iostream>

using std::string;

class Mascota{
    private:
        string typePet;
        float weight;
        int age;
        string typeBlood;
        string name;
        double identification;
        bool status;
        string dateFall;
    public:
    //Mascota(string name, int identificacion, string typePet, float weight, int age, string typeBlood, bool status)
        Mascota();
        Mascota(string, int, string, float, int, string, bool);
        void mostrarDatosMascota();
        string getStatusPet();
};





#endif