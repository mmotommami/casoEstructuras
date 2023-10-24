#ifndef _BODEGA2_
#define _BODEGA2_ 0

#include "ConfigLoader.cpp"
#include "TarimaGroup2.cpp"
#include "Pedido.cpp"
#include <time.h>
#include <stdlib.h>
#include "Queue.h"
#include "lista.h"
#include <vector>
#include "Stack.h"
#include <string>
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

class Bodega2
{
private:
//    metodos<TarimaGroup> inventario; // crearia un objeto mejor //En segunda instancia me parece inútil
    TarimaGroup* tarimaGroup;
    Configuracion config;
    Queue *pedidos;  // Queue<Pedido *> *pedidos

    //Modificar la listaDePedidos para utilizar "la funcionalidad" de una cola
    vector<Pedido> listaDePedidos;

public:
    Bodega2()
    {
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

    // seguro esto va a ser un thread
    void refillInventory()
    {
//        while(true){
            //Manera de llenar inventario
            
//            this_thread::sleep_for(config.bodega.refillTime);
        tarimaGroup->rellenar();
            //En el main de simulador deberá haber algún tipo de creación de
            //thread que llame este método, para hacerlo nada más se debe
            //debe escribir thread <nombre del thread>(<nombre de este método>);
  //      }
        // ir a revisar la lista de TarimaGroups para rellenar las pilas con colchones nuevos
    }

    void pruebaBodega()  //Para trabajar con vectorTarimas no es necesario sacar una copia ni nada similar,
                         //se llama a vectorTarimas y se le aplica el método que se desee aplicar como si
                         //fuese un vector normal declarado de manera local
    {
        std::vector<std::vector<Colchon>> &tarimas = vectorTarimas;   //Tener en cuenta que si tarimas tiene un "&",
                                                                      //cuando modifiquemos los datos de tarimas, los
                                                                      //datos de vectorTarimas también serán modificados
        std::cout << vectorTarimas.size() << std::endl;
        std::vector<Colchon> vectorColchones1 = vectorTarimas.back();
//        vectorTarimas.pop_back();
        std::cout << vectorColchones1.size() << std::endl;
        Colchon colchon2 = vectorColchones1.back();
        std::cout << colchon2.getName() << std::endl;
        std::cout << "QWERTYUIOPASDFGHJKLÑZXCVBNM" << std::endl;
        std::cout << tarimas.size() << std::endl;
        std::cout << "QWERTYUIOPASDFGHJKLÑZXCVBNM" << std::endl;
        std::vector<Colchon> vectorColchones = tarimas.back();
        std::cout << vectorColchones.size() << std::endl;
        std::cout << "QWERTYUIOPASDFGHJKLÑZXCVBNM" << std::endl;
        Colchon colchon = vectorColchones.back();
        std::cout << colchon.getName() << std::endl;
        std::cout << "QWERTYUIOPASDFGHJKLÑZXCVBNM" << std::endl;
    }

    // puede ser un hilo
    // o podria ser que haya solo un hilo y ese hilo controle a refill y al generar
    void generarPedidos()
    {
        Pedido nuevoPedido;

        vector<int> tiempoPedido = config.rutas.tiempo;

        int minPedidos = config.pedidos.minPedidos;
        int maxPedidos = config.pedidos.maxPedidos;

/*
        int tiempoGeneracion = infoPedidos.tiempoEntreGeneracion; 
        Este tiempo de generacion no va aquí, este debe ser sacado en el simulador,
        para que el thread llame este método cada cantidad de segundos que esta variable diga
*/
        int minColchones = config.pedidos.minColchonesPorPedido;
        int maxColchones = config.pedidos.maxColchonesPorPedido;
        
/*
        int tiempoEntreEnvioDePedidos = infoPedidos.tiempoEntrePedidos;
        Al igual que el tiempo de generacion, este dato no debe ser sacado aquí, este dato debe
        ser sacado en el simulador para que cada cantidad de segundos que esta variable diga
        se llame al método atenderPedidos
*/
        srand(time(NULL));

        int randomCantidadPedidos = minPedidos + rand() % (maxPedidos + 1 - minPedidos);
        
        int num=rand()%4;

        std::cout << num << std::endl;
        

        int ruta = tiempoPedido.at(num);

        std::cout << "." << std::endl;

        nuevoPedido.setTiempo(ruta);

        std::cout << "." << std::endl;

        for(int i = 0; i < randomCantidadPedidos; i++) {
            int randomCantidadColchonesFull = minColchones + rand() % (maxColchones + 1 - minColchones);
            int randomCantidadColchonesQueen = minColchones + rand() % (maxColchones + 1 - minColchones);
            int randomCantidadColchonesTwin = minColchones + rand() % (maxColchones + 1 - minColchones);
            int randomCantidadColchonesKing = minColchones + rand() % (maxColchones + 1 - minColchones);

            nuevoPedido.setCantidadColchonesFull(randomCantidadColchonesFull);
            nuevoPedido.setCantidadColchonesKing(randomCantidadColchonesKing);
            nuevoPedido.setCantidadColchonesQueen(randomCantidadColchonesQueen);
            nuevoPedido.setCantidadColchonesTwin(randomCantidadColchonesTwin);
            
            listaDePedidos.push_back(nuevoPedido);
        }

        std::cout << "QWERTYUIOPASDFGHJKLÑZXCVBNM" << std::endl;
    }

    void atenderPedido()
    {

        std::vector<Colchon> pedidoGeneral;

        std::vector<Pedido> listaAuxiliar;

        std::cout << listaDePedidos.size() << std::endl;
        while(!listaDePedidos.empty()){

            Pedido pedidoAnalizado = listaDePedidos.back();
            listaDePedidos.pop_back();

            int tiempo = pedidoAnalizado.getTiempo();
            int cantidadFull = pedidoAnalizado.getCantidadColchonesFull();
            int cantidadKing = pedidoAnalizado.getCantidadColchonesKing();
            int cantidadQueen = pedidoAnalizado.getCantidadColchonesQueen();
            int cantidadTwin = pedidoAnalizado.getCantidadColchonesTwin();

            if(comprobarCantidad("Full", cantidadFull) && comprobarCantidad("King", cantidadKing) && comprobarCantidad("Queen", cantidadQueen) && comprobarCantidad("Twin", cantidadTwin)){                            
                //vector<Colchon> cargaDeFull = cargarCamion("Full", cantidadFull);
                
                std::cout << "Hola, mundo!!!!" << std::endl;

                std::cout << vectorTarimas.size() << std::endl;
                
                vector<Colchon> carga1 = cargarCamion("Full", cantidadFull);
                std::cout << "QWERTYUIOPASDFGHJKLÑZXCVBNM" << std::endl;
                vector<Colchon> carga2 = cargarCamion("King", cantidadKing);
                vector<Colchon> carga3 = cargarCamion("Queen", cantidadQueen);
                vector<Colchon> carga4 = cargarCamion("Twin", cantidadTwin);
                
                std::vector<Colchon> vectorColchones1 = vectorTarimas.back();
                std::cout << "Hola, mundo!!!!" << std::endl;
                std::cout << "Hola, mundo!!!!" << std::endl;
                std::cout << "Hola, mundo!!!!" << std::endl;
                std::cout << vectorColchones1.size() << std::endl;
                std::cout << vectorTarimas.size() << std::endl;
                std::cout << "Hola, mundo!!!!" << std::endl;
                std::cout << carga1.size() << std::endl;
                int carga1s = carga1.size();
                for(int p = 0; p < carga1s; p++) {
                    Colchon colchon = carga1.back();
                    pedidoGeneral.push_back(colchon);
                }
                std::cout << carga2.size() << std::endl;
                int carga2s = carga2.size();
                for(int p = 0; p < carga2s; p++) {
                    Colchon colchon = carga2.back();
                    pedidoGeneral.push_back(colchon);
                }
                std::cout << carga3.size() << std::endl;
                int carga3s = carga3.size();
                for(int p = 0; p < carga3s; p++) {
                    Colchon colchon = carga3.back();
                    pedidoGeneral.push_back(colchon);
                }
                std::cout << carga4.size() << std::endl;
                int carga4s = carga4.size();
                for(int p = 0; p < carga4s; p++) {
                    Colchon colchon = carga4.back();
                    pedidoGeneral.push_back(colchon);
                }
                
                std::cout << "Hola, mundo!!!!" << std::endl;
//              asignarCarga(pedidoGeneral, tiempo);
                std::cout << "Hola, mundo!!!!" << std::endl;

                //Si un pedido es realizado, se revisa si listaAuxiliar.size() == 0, si es el caso todo bien, pero
                //si no lo es debemos de sacar el tamaño con el .size y generar un for que saque tantos elementos
                //como el tamaño de la listaAuxiliar diga y lo meta al vector de pedidos.
                //Una vez que el pedido es realizado, se utiliza break; para salir del while
            } else {
                std::cout << "No funcionó2" << std::endl;
                listaAuxiliar.push_back(pedidoAnalizado);
            }
        }
        int cantidadElementosA = listaAuxiliar.size();
        for(int k = 0; k < cantidadElementosA; k++) {
            Pedido pedidoSacado = listaAuxiliar.back();
            listaAuxiliar.pop_back();
            this->listaDePedidos.push_back(pedidoSacado);
        }

    }

    bool comprobarCantidad(std::string pNombre, int pCantidadColchon) {
        
        std::vector<std::vector<Colchon>> tarimas2 = vectorTarimas;
        /*
        std::cout << "Tamaño" << std::endl;
        std::cout << tarimas2.size() << std::endl;
        std::cout << "Tamaño" << std::endl;
        */
        int cantidadTarimas = tarimas2.size();
        for(int h = 0; h < cantidadTarimas ; h++) {
            std::vector<Colchon> vectorColchones = tarimas2.back();
            tarimas2.pop_back();
            /*
            std::cout << "Tamaño10" << std::endl;
            std::cout << tarimas2.size() << std::endl;
            std::cout << vectorTarimas.size() << std::endl;
            std::cout << "Tamaño10" << std::endl;
            */
            int vectorSize = vectorColchones.size();
            Colchon colchonAnalizado = vectorColchones.back();
            std::string colchonInicial = colchonAnalizado.getName();
            /*
            std::cout << "Nombres" << std::endl;
            std::cout << "Nombres" << std::endl;
            std::cout << pNombre << std::endl;
            std::cout << colchonInicial << std::endl;
            std::cout << "Nombres" << std::endl;
            std::cout << "Nombres" << std::endl;
            */
            if(colchonInicial == pNombre) 
            {
//                std::cout << vectorSize << std::endl;
//                std::cout << pCantidadColchon << std::endl;
                if(vectorSize >= pCantidadColchon) {
                    return true;
                    break;
                }
            }
        }

        return false;
    }
        
    
//          tarimas = [[{King}, {King}, {King}], [{Queen}, {Queen}, {Queen}]]

    vector<Colchon> cargarCamion(std::string pNombre, int pCantidadColchon) {
        std::vector<Colchon> camion;
        std::vector<std::vector<Colchon>> listaAuxiliar;
        std::vector<std::vector<Colchon>> tarimas = vectorTarimas;
        int sizeVectorTarimas = tarimas.size();
        for(int t = 0; t < sizeVectorTarimas; t++){
            std::vector<Colchon> &vectorColchones = vectorTarimas.back();
            int sizeVectorColchones = vectorColchones.size();
            Colchon colchonSacado = vectorColchones.back();
            std::string nombre = colchonSacado.getName();
            if(nombre == pNombre && sizeVectorColchones >= pCantidadColchon){
                for(int k = 0; k < pCantidadColchon; k++) {
                    std::cout << "Un colchon ha sido cargado" << std::endl;
                    std::this_thread::sleep_for(std::chrono::milliseconds(7));
                    camion.push_back(colchonSacado);
                    vectorColchones.pop_back();
                }
                while(listaAuxiliar.size() != 0) {
                    vectorTarimas.push_back(listaAuxiliar.back());
                    listaAuxiliar.pop_back();
                }
                return camion;
            } else {
                listaAuxiliar.push_back(vectorColchones);
                vectorTarimas.pop_back();
            }
        }
    }
/*
    vector<Colchon> cargarCamion(std::string pNombre, int pCantidadColchon) {
        int a = 321;
        std::vector<Colchon> camion;
        std::vector<std::vector<Colchon>> listaAuxiliar;
        std::cout << "QWERTYUIOPASDFGHJKLÑZXCVBNM" << std::endl;
        int sizeVector = vectorTarimas.size();
        std::cout << "QWERTYUIOPASDFGHJKLÑZXCVBNM" << std::endl;
        for(int h = 0; h < sizeVector; h++) {
            std::vector<Colchon> vectorColchones = vectorTarimas.back();
            vectorTarimas.pop_back();
            int sizeVectorC = vectorColchones.size();
            if(sizeVectorC > pCantidadColchon) {
                std::cout << a << std::endl;
                for(int k = 0; k < pCantidadColchon; k++) {
                    std::cout << pCantidadColchon << std::endl;
                    Colchon colchonARevisar = vectorColchones.back();
                    std::cout << k << std::endl;
                    std::string nombreColchon = colchonARevisar.getName();
                    if(nombreColchon != pNombre) {
                        listaAuxiliar.push_back(vectorColchones);
                        std::vector<Colchon> vectorColchones = vectorTarimas.back();
                        vectorTarimas.pop_back();
                    } else {
                        camion.push_back(colchonARevisar);
                        vectorColchones.pop_back();
                    }
                }
                
                int pushes = listaAuxiliar.size();
                std::cout << a << std::endl;
                while(pushes != 0) {
                    std::cout << a << std::endl;
                    vectorTarimas.push_back(vectorColchones);
                    std::vector<Colchon> vectorColchones = listaAuxiliar.back();
                    listaAuxiliar.pop_back();
                    pushes--;
                }
                
            }else {
                std::cout << a << std::endl;
                listaAuxiliar.push_back(vectorColchones);
            }
        }
        int cantidadElementos = listaAuxiliar.size();
        while(cantidadElementos != 0) {
            std::vector<Colchon> vectorColchones = listaAuxiliar.back();
            vectorTarimas.push_back(vectorColchones);
            listaAuxiliar.pop_back();
            cantidadElementos--;
        }

        return camion;
    }


    Colchon* sacarColchonDeTarima(Stack pTarima)
    {
        Colchon* colchonSacado = static_cast<Colchon*>(pTarima.pop());
        return colchonSacado;
    }

    void manipulateTarimas() {
        std::cout << "Hola, prueba" << std::endl;
    
    // Access the tarimas Stack directly
        Stack tarimas = tarimaGroup->getTarimas();

    // Example: Pop an element from tarimas
        if (!tarimas.estaVacio()) {
            /*
            std::cout << tarimas.largoPila() << std::endl;
            void* voidPtr = tarimas.pop();
            std::cout << "El puntero no apunta vacio" << std::endl;
            if (voidPtr != nullptr)
            {
                Colchon* colchon = static_cast<Colchon*>(tarimas.pop());
            } else {
                std::cout << "El puntero apunta vacio" << std::endl;
            }
        /*
        std::cout << "metodo manipulateTarimas" << std::endl;
        Colchon colchonSinPtr = *colchon;
        std::cout << "metodo manipulateTarimas" << std::endl;
        std::cout << colchonSinPtr.getPeso() << std::endl;
        std::cout << "metodo manipulateTarimas" << std::endl;
        // Perform any operations you need with colchon
        
        }

    }
*/
    
};

#endif