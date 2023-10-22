#ifndef COLCHON_H
#define COLCHON_H

#include "lista.h"
#include <string>

using namespace std;

class Colchon
{
private:
    string name;
    int peso;
    int alto;
    int ancho;
    int profundidad;

public:
    Colchon(string pName, int pPeso, int pAlto, int pAncho, int pProfundidad)
    {
        name = pName;
        peso = pPeso;
        alto = pAlto;
        ancho = pAncho;
        profundidad = pProfundidad;
    }

    string getName()
    {
        return this->name;
    }

    int getPeso()
    {
        return this->peso;
    }
};

#endif