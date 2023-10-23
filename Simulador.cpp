#ifndef _SIMULADOR_
#define _SIMULADOR_ 0

#include "Bodega.cpp"
#include "ConfigLoader.cpp"
#include "Flotilla.cpp"
#include "TarimaGroup2.cpp"
#include "Bodega2.cpp"

#include <chrono>
#include <thread>

using namespace std;

class Simulador
{
private:
    Configuracion config;
    TarimaGroup *tarimaGroup;
    TarimaGroup2 *tarima;
    Flotilla *flotilla;
    Pedido *pedido;
    Bodega2 *labodega2;
    Bodega2 *bodegaCarga;
    

public:
    Simulador()
    {
        initSimulation();
    }

    void initSimulation()
    {
//        config = ConfigLoader::LoadConfig();
//        tarimaGroup = new TarimaGroup();
        tarima = new TarimaGroup2();
        Bodega2 *labodega2 = new Bodega2();
        flotilla = new Flotilla(generarCamiones());
        tarima->rellenar2();
//        tarima->prueba();
        
        
//        labodega2->pruebaBodega();
        labodega2->generarPedidos();
        labodega2->atenderPedido();
        
//        tarimaGroup->rellenar();
//        labogeda = new Bodega(tarimaGroup);
//        tarimaGroup->rellenar(); 
        //tarimaGroup->rellenar();
        
//        std::thread hiloRellenar(thread_rellenar);

//        hiloRellenar.join();
        
        std::cout << "pi" << std::endl;  //Lo ideal sería poder pasar tarimaGroup dentro de labodega,
                                         //porque al parecer tarima group si tiene las cosas bien
//        std::cout << tarimaGroup->sizeOfTarima() << std::endl;
        std::cout << "pi" << std::endl;

/*
        Stack* stack = tarimaGroup->sacarTarima();
        std::cout << stack->largoPila() << std::endl;
*/

//        labogeda->generarPedidos();
//        std::thread thread_generarP;
//        labogeda->atenderPedido();
//        std::thread thread_atenderP;
    }

    vector<Camion> generarCamiones() {
        vector<Camion> vectorCamion;
        for(int r = 0; r < config.camion.cantidadCamiones; r++) {
            int capacity = config.camion.capacidad;
            int width = config.camion.ancho;
            int length = config.camion.longitud;
            Camion camion = new Camion(r, capacity, width, length);
            vectorCamion.push_back(camion);
        }
        return vectorCamion;
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
            labodega2->generarPedidos();
            std::this_thread::sleep_for(std::chrono::seconds(config.pedidos.tiempoEntreGeneracion));
        }
        
    }

    void thread_atenderP() {
        
        while(true)
        {
            labodega2->atenderPedido();
            std::this_thread::sleep_for(std::chrono::seconds(config.pedidos.tiempoEntreEnvioDePedidos));
        }
        
    }
};

#endif