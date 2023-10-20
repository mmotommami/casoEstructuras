#ifndef _SIMULADOR_
#define _SIMULADOR_ 0

#include "Bodega.cpp"
#include "ConfigLoader.cpp"
#include "Flotilla.cpp"

#include <chrono>
#include <thread>

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
//        config = ConfigLoader::LoadConfig();
        tarimaGroup = new TarimaGroup();
        flotilla = new Flotilla();
        tarimaGroup->rellenar();
        labogeda = new Bodega(tarimaGroup);
//        tarimaGroup->rellenar(); 
        //tarimaGroup->rellenar();
        
//        std::thread hiloRellenar(thread_rellenar);

//        hiloRellenar.join();
        
        std::cout << "pi" << std::endl;  //Lo ideal sería poder pasar tarimaGroup dentro de labodega,
                                         //porque al parecer tarima group si tiene las cosas bien
        std::cout << tarimaGroup->sizeOfTarima() << std::endl;
        std::cout << "pi" << std::endl;

        labogeda->generarPedidos();
//        std::thread thread_generarP;
        labogeda->atenderPedido();
//        std::thread thread_atenderP;
    }

    void thread_rellenar() {
        
        while(true)
        {
            tarimaGroup->rellenar();
            std::this_thread::sleep_for(std::chrono::seconds(config.bodega.refillTime));
        }
        
    }

    void thread_generarP() {
        
        while(true)
        {
            labogeda->generarPedidos();
            std::this_thread::sleep_for(std::chrono::seconds(config.pedidos.tiempoEntreGeneracion));
        }
        
    }

    void thread_atenderP() {
        
        while(true)
        {
            labogeda->atenderPedido();
            std::this_thread::sleep_for(std::chrono::seconds(config.pedidos.tiempoEntreEnvioDePedidos));
        }
        
    }
};

#endif