#ifndef _SIMULADOR_
#define _SIMULADOR_ 0

#include "Bodega.cpp"
#include "ConfigLoader.cpp"
#include "Flotilla.cpp"

using namespace std;

class Simulador
{
private:
    Configuracion config;
    TarimaGroup *tarimaGroup;
    Flotilla *flotilla;
    Pedido *pedido;
    Bodega *labogeda;

public:
    Simulador()
    {
        initSimulation();
    }

    void initSimulation()
    {
        config = ConfigLoader::LoadConfig();
        tarimaGroup = new TarimaGroup();
        tarimaGroup->rellenar();
        flotilla = new Flotilla();
        labogeda = new Bodega();
        labogeda->generarPedidos();
        labogeda->atenderPedido();
        
        

    }

    void thread_rellenar(){
        //Thread para rellenar tarimas
    }

    void thread_generarP() {
        //Thread para generar pedidos
    }

    void thread_atenderP() {
        //Thread para atender pedidos
    }
};