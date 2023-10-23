#ifndef _BODEGALLEGADA_
#define _BODEGALLEGADA_ 0

#include "ConfigLoader.cpp"
#include "TarimaGroup.cpp"
#include "Pedido.cpp"
#include <time.h>
#include <stdlib.h>
#include "Queue.h"
#include "lista.h"
#include <vector>
#include "Stack.h"
#include <string>
#include <iostream>

using namespace std;

class Bodega
{
private:
//    metodos<TarimaGroup> inventario; // crearia un objeto mejor //En segunda instancia me parece inútil
    TarimaGroup* tarimaGroup;
    Configuracion config;
    Queue *pedidos;  // Queue<Pedido *> *pedidos

    //Modificar la listaDePedidos para utilizar "la funcionalidad" de una cola
    vector<Pedido> listaDePedidos;

public:
    Bodega(TarimaGroup* pTarima)
    {
        tarimaGroup = pTarima;
        config = ConfigLoader::LoadConfig();
        initBodega();
        // start al hilo de refill
        // start al hilo de generar pedidos
    }

    void initBodega()
    {
        // inicializar esas listas
        // inicializar las pilas de esas listas tambien segun la cantidad que dice configBodega
    }


};

#endif