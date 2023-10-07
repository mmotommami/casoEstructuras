#ifndef CAMION_H
#define CAMION_H

#include "lista.h"

using namespace std;

class Camion
{
private:
    int capacidad;
    int ancho;
    int largo;
    Stack<Colchon *> cajon;
    int id;
    bool available;

public:
    Camion(int pCapacidad, int pAncho, int pLargo)
    {
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
};

#endif