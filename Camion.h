#ifndef CAMION_H
#define CAMION_H

#include "lista.h"
#include "Stack.h"
#include "Colchon.h"
#include <vector>


using namespace std;

class Camion
{
private:
    int capacidad;
    int ancho;
    int largo;
    vector<Colchon> cajon;
    int id;
    bool available;

public:
    Camion(int pID, int pCapacidad, int pAncho, int pLargo)
    {
        id = pID;
        capacidad = pCapacidad;
        ancho = pAncho;
        largo = pLargo;
    }

    int getCapacity() {
        return capacidad;
    }
    
    bool getState() {
        return available;
    }

    void setCajon(vector<Colchon> pVector) {
        this.cajon = pVector;
    }
};

#endif