#include "ConfigLoader.cpp"
#include "TarimaGroup.cpp"
#include <time.h>
#include <stdlib.h>
#include "Queue.h"
#include "lista.h"
#include <vector>

using namespace std;

struct Pedido {
    int cantidadColchonesFull;
    int cantidadColchonesQueen;
    int cantidadColchonesKing;
    int cantidadColchonesTwin;
};

class Bodega
{
private:
    Configbodega configBodega;
    ConfigPedidos configPedidos;
    metodos<TarimaGroup> inventario; // crearia un objeto mejor
    TarimaGroup tarimaGroup;
    Configloader configuracion;
    Queue<Pedido *> *pedidos;
    Pedido nuevoPedido;
    std::vector<Pedido> listaDePedidos;

public:
    Bodega(Configbodega pConfiguracionBodega, ConfigPedidos pConfigPedidos, Flotilla *flotillaManager)
    {
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
        while(true){
            //Manera de llenar inventario
            this_thread::sleep_for(configBodega.refilltime);
            tarimaGroup.rellenar();
            //En el main de simulador deberá haber algún tipo de creación de
            //thread que llame este método, para hacerlo nada más se debe
            //debe escribir thread <nombre del thread>(<nombre de este método>);
        }
        // ir a revisar la lista de TarimaGroups para rellenar las pilas con colchones nuevos
    }

    // puede ser un hilo
    // o podria ser que haya solo un hilo y ese hilo controle a refill y al generar
    void generarPedidos()
    {
        ConfigPedidos infoPedidos = configuracion.getConfigPedidos();

        int minPedidos = infoPedidos.minPedidos;
        int maxPedidos = infoPedidos.maxPedidos;
/*
        int tiempoGeneracion = infoPedidos.tiempoEntreGeneracion; 
        Este tiempo de generacion no va aquí, este debe ser sacado en el simulador,
        para que el thread llame este método cada cantidad de segundos que esta variable diga
*/
        int minColchones = infoPedidos.minColchonesPorPedido;
        int maxColchones = infoPedidos.maxColchonesPorPedido;
/*
        int tiempoEntreEnvioDePedidos = infoPedidos.tiempoEntrePedidos;
        Al igual que el tiempo de generacion, este dato no debe ser sacado aquí, este dato debe
        ser sacado en el simulador para que cada cantidad de segundos que esta variable diga
        se llame al método atenderPedidos
*/
        srand(time(NULL));

        int randomCantidadPedidos = minPedidos + rand() % (maxPedidos + 1 - minPedidos);

        for(int i = 0; i < randomCantidadPedidos; i++) {
            int randomCantidadColchonesFull = minColchones + rand() % (maxColchones + 1 minColchones);
            int randomCantidadColchonesQueen = minColchones + rand() % (maxColchones + 1 minColchones);
            int randomCantidadColchonesTwin = minColchones + rand() % (maxColchones + 1 minColchones);
            int randomCantidadColchonesKing = minColchones + rand() % (maxColchones + 1 minColchones);

            nuevoPedido.cantidadColchonesFull = randomCantidadColchonesFull;
            nuevoPedido.cantidadColchonesKing = randomCantidadColchonesKing;
            nuevoPedido.cantidadColchonesQueen = randomCantidadColchonesQueen;
            nuevoPedido.cantidadColchonesTwin = randomCantidadColchonesTwin;
            
            this->listaDePedidos.push_back(nuevoPedido);
        }


        //Esta lista de pedidos va a ser revisada con un pop_back, que obtiene el último
        //elemento ingresado al vector por el push_back, el elemento que se saque

        //Hacer hilo que cada cierto tiempo de generacion genere la cantidad
        //aleatoria de pedidos con la cantidad aleatoria de colchones

        // while true
        // genero el random en el rango para saber la cantidad de pedidos a generar
        // para cada pedido a generar, genero el random en el rango para saber cuantos colchones van en el pedido
        // crear el pedido, nuevoPedido
        //
        // una vez que termino
        // hago sleep de ConfigPedidos.tiempoEntreGeneracion
    }

    // thread o bien todo dentro de un thread en bodega
    void atenderPedidos()
    {
        Pedido pedidoAnalizado = this->listaDePedidos.pop_back(nuevoPedido);

        //Aquí con pedidoAnalizado.<cantidad de colchones del pedido> se debe verificar si esa cantidad puede
        //ser sacada del almacen, si no puede ser sacada, en un vector auxiliar se va a meter el pedido, para probar
        //con el siguiente, cabe aclarar que se deben revisar todas las cantidades de colchones que pide el pedido
        //antes de hacer los pop del almacen/bodega, esto porque si se hacen los pop cada que se verifica que una
        //cantidad de colchones es posible de ser sacada, en caso de que una de las siguientes cantidades no pueda
        //ser sacada se jodería el sistema.
        
        //Cada pedido va a decir algo similar a:
        //40 Twins, 20, Kings, 10 Full, 15 Queen
        //Una vez con el pedido, se va a sacar los elementos de la lista tarima,
        // Pedido currentPedido = pedidos->dequeue();
        // revisar mi lista de tarimasgroup para los tipos de colchon que hay en el pedido puedo armar el pedido
        // si no puedo armar el pedido, lo vuelvo a encolar
        // si si lo puedo armar
        // saco los colchones que sean necesario de los TarimaGroup
        // segun la cantidad asi los voy tirando a los camiones
        // flotillaManager->enviar(lista de colchones que arme de la orden);
        // sleep de tiempoEntreEnvioDePedidos
    }
};