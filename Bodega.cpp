#ifndef _BODEGA_
#define _BODEGA_ 0

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

using namespace std;

class Bodega
{
private:
//    metodos<TarimaGroup> inventario; // crearia un objeto mejor //En segunda instancia me parece inútil
    TarimaGroup tarimaGroup;
    Configuracion config;
    Queue *pedidos;  // Queue<Pedido *> *pedidos
    vector<Pedido> listaDePedidos;

public:
    Bodega()
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
        tarimaGroup.rellenar();
            //En el main de simulador deberá haber algún tipo de creación de
            //thread que llame este método, para hacerlo nada más se debe
            //debe escribir thread <nombre del thread>(<nombre de este método>);
  //      }
        // ir a revisar la lista de TarimaGroups para rellenar las pilas con colchones nuevos
    }

    // puede ser un hilo
    // o podria ser que haya solo un hilo y ese hilo controle a refill y al generar
    void generarPedidos()
    {
        Pedido nuevoPedido;

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
    // Este método atiende un pedido cada cierta cantidad de tiempo, por lo que se debe tener un thread
    // que llame a este método dependiendo de cada cuanto se quiera atender un pedido.

    //Hilo que se ejecute cada cierto tiempo
    void atenderPedido()
    {
        bool estado = false;

        std::vector<Pedido> listaAuxiliar;

//listaDePedidos.empty(); retorna true cuando no tiene elementos, por lo que 
//!listaDePedidos.empty() retorna true siempre que hayan elementos
        while(!listaDePedidos.empty()){

            Pedido pedidoAnalizado = listaDePedidos.back();
            listaDePedidos.pop_back();

//listaDePedidos = [{}, {}, {}, {}] //Cada una de las llaves significa un objeto de tipo Pedido,
//para acceder a cada cantidad se hace con pedidoAnalizado.cantidadColchonesFull;

            int cantidadFull = pedidoAnalizado.getCantidadColchonesFull();
            int cantidadKing = pedidoAnalizado.getCantidadColchonesKing();
            int cantidadQueen = pedidoAnalizado.getCantidadColchonesQueen();
            int cantidadTwin = pedidoAnalizado.getCantidadColchonesTwin();
            //Comprueba si se puede realizar el pedido, en caso de que sí se pueda se entra dentro del if,
            //y dentro de este se cambia el valor booleano de "estado" a true.
            if(comprobarCantidad("Full", cantidadFull) && comprobarCantidad("King", cantidadKing) && comprobarCantidad("Queen", cantidadQueen) && comprobarCantidad("Twin", cantidadTwin)){
                //vector<Colchon> cargaDeFull = cargarCamion("Full", cantidadFull);
                std::cout << "Hola, mundo!" << std::endl;
                //Si un pedido es realizado, se revisa si listaAuxiliar.size() == 0, si es el caso todo bien, pero
                //si no lo es debemos de sacar el tamaño con el .size y generar un for que saque tantos elementos
                //como el tamaño de la listaAuxiliar diga y lo meta al vector de pedidos.
                //Una vez que el pedido es realizado, se utiliza break; para salir del while
            } else {
                listaAuxiliar.push_back(pedidoAnalizado);
            }

        //Si el método acaba sin que se haya realizado ningún pedido, también se deberán de ingresar los datos
        //nuevamente a listaDePedidos
        }

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
        // si sí lo puedo armar
        // saco los colchones que sean necesario de los TarimaGroup
        // segun la cantidad asi los voy tirando a los camiones
        // flotillaManager->enviar(lista de colchones que arme de la orden);
        // sleep de tiempoEntreEnvioDePedidos

        int cantidadElementosA = listaAuxiliar.size();
        for(int k = 0; k < cantidadElementosA; k++) {
            Pedido pedidoSacado = listaAuxiliar.back();
            listaAuxiliar.pop_back();
            this->listaDePedidos.push_back(pedidoSacado);
        }

    }

    bool comprobarCantidad(std::string pNombre, int pCantidadColchon) {
        Stack copiaTarima = tarimaGroup.getTarimasCopy();  //Stack<ColchonStack *> copiaTarima
        for(int h = 0; h < copiaTarima.largoPila(); h++) {
            //Stack tarimaUnica = copiaTarima.pop();  //Stack<Colchon *> tarimaUnica
            Stack* tarimaUnicaPtr = static_cast<Stack*>(copiaTarima.pop());
            Stack tarimaUnica = *tarimaUnicaPtr;
            for(int k = 0; k < tarimaUnica.largoPila(); k++) {
                Colchon* colchonPtr = static_cast<Colchon*>(tarimaUnica.pop());
                Colchon colchonGuardado = *colchonPtr;
                std::string colchonInicial = colchonGuardado.getName();
                if(colchonInicial != pNombre) {
                    //Este espacio vacío es porque no quiero que ocurra 
                    //nada en caso de que el tipo de colchón sea incorrecto
                } else {
                    if(tarimaUnica.largoPila() > pCantidadColchon) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
//          tarimas = [[{King}, {King}, {King}], [{Queen}, {Queen}, {Queen}]]

    vector<Colchon> cargarCamion(std::string pNombre, int pCantidadColchon) {
        //vector temporal mientras se define una pila para camion
        std::vector<Colchon> camion;
        std::vector<Stack> listaAuxiliar;  //vector<ColchonStack *> listaAuxiliar;
        Stack tarimaUnica;
        //Lista auxiliar que será usada para guardar los elementos que no correspondan al tipo correcto de datos,
        //una vez el método finaliza, dicha lista auxiliar tendrá que volver a meter los elementos que sacó a la
        //copia directa de tarimas
        Stack copiaTarimas = tarimaGroup.getTarimasCopy();  //Stack<ColchonStack *> copiaDirectaTarimas
        //Con esto se saca un puntero directo a tarimas, si dicha copia es modificada, tarimas también lo hace
        for(int h = 0; h < copiaTarimas.largoPila(); h++) { //2
            //Se empieza a recorrer la pila tarimas
            Stack* tarimaUnicaPtr = tarimaGroup.sacarTarima();
            Stack tarimaUnica = *tarimaUnicaPtr;
//            Stack* tarimaUnica = copiaDirectaTarimas.pop();  //Stack<Colchon *> tarimaUnica
            //Tarima con colchones del mismo tipo

            if(tarimaUnica.largoPila() > pCantidadColchon) {
                for(int k = 0; k < pCantidadColchon; k++) { //3
//                    Colchon* colchonGuardadoPtr = tarimaUnica.pop();
                    Colchon* colchonGuardadoPtr1 = static_cast<Colchon*>(tarimaUnica.pop());
                    Colchon colchonGuardadoSinPtr = *colchonGuardadoPtr1;
                    std::string nombreColchon = colchonGuardadoSinPtr.getName();
                    if(nombreColchon != pNombre) {
                        void* colchonGuardado = static_cast<void*>(&colchonGuardadoSinPtr);
                        tarimaUnica.push(colchonGuardado);
                        listaAuxiliar.push_back(tarimaUnica);
                        Stack* tarimaUnicaPtr = tarimaGroup.sacarTarima();
                        Stack tarimaUnica = *tarimaUnicaPtr;
                    } else {
                        camion.push_back(colchonGuardadoSinPtr);
                    }
                }
                int pushes = listaAuxiliar.size();
                while(pushes != 0) {
                    tarimaGroup.agregarTarima(tarimaUnica);
//                    copiaDirectaTarimas.push(tarimaUnica)
                    Stack tarimaUnica = listaAuxiliar.back();  //Stack<Colchon *> tarimaUnica
                    listaAuxiliar.pop_back();
                    pushes--;
                }
            }else {
                listaAuxiliar.push_back(tarimaUnica);
            }
        }
        int cantidadElementos = listaAuxiliar.size();
        while(cantidadElementos != 0) {
            tarimaGroup.agregarTarima(tarimaUnica);
            Stack tarimaUnica = listaAuxiliar.back();  //Stack<Colchon *> tarimaUnica
            listaAuxiliar.pop_back();
            cantidadElementos--;
        }

        return camion;
    }
};

#endif