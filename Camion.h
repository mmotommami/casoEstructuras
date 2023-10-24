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
    int currentCapacity;
    int ancho;
    int largo;
    vector<Colchon> cajon;
    int id;
    bool available;

public:
    Camion(int pID, int pCapacidad, int pAncho, int pLargo)
    {
        currentCapacity = 0;
        available = true;
        id = pID;
        capacidad = pCapacidad;
        ancho = pAncho;
        largo = pLargo;
    }

    int getCapacity() {
        return capacidad;
    }

    int getCurrentCapacity() {
        return currentCapacity;
    }
    
    bool getState() {
        return available;
    }

    void setStateTrue() {
        available = true;
    }

    void setStateFalse() {
        available = false;
    }

    void setCajon(vector<Colchon> pVector) {
        this->cajon = pVector;
    }

    int getSizeCajon() {
        int size = cajon.size();
        return size;
    }

    bool cajonVacio() {
        if(cajon.size() == 0) {
            setStateTrue();
            return true;
        } else {
            return false;
        }
    }

    void addCajon(Colchon pColchon) {
        cajon.push_back(pColchon);
        int peso = pColchon.getPeso();
        this->currentCapacity = currentCapacity + peso;
        if(currentCapacity >= capacidad) {
            setStateFalse();
        }
    }

    Colchon removeCajon() {
        Colchon colchon = cajon.back();
        cajon.pop_back();
        if(cajonVacio()){
            setStateTrue();
        }
        return colchon;
    }
};

#endif