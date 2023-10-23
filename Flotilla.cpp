#ifndef _FLOTILLA_
#define _FLOTILLA_ 0

#include "lista.h"
#include "Camion.h"
#include <vector>

using namespace std;

class Flotilla
{
private:
    vector<Camion> camiones;  //metodos<Camion *> *camiones

public:
    Flotilla(vector<Camion> pCamiones) {
        camiones = pCamiones;
    }

    void enviar(Camion pCamion) //metodos<Colchon *> pColchones
    {
        // ver los camiones disponibles para enviar los colchones
    }

    void asignarCarga(vector<Colchon> pVector) {
        
    }
};

#endif