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
    Configbodega configBodega;
    ConfigPedidos configPedidos;
    metodos<TarimaGroup> inventario; // crearia un objeto mejor
    TarimaGroup tarimaGroup;
    Configloader configuracion;
    Queue<Pedido *> *pedidos;
    Pedido nuevoPedido;
    vector<Pedido> listaDePedidos;

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
    // Este método atiende un pedido cada cierta cantidad de tiempo, por lo que se debe tener un thread
    // que llame a este método dependiendo de cada cuanto se quiera atender un pedido.
    void atenderPedidos()
    {
        bool estado = false;

        std::vector<Pedido> listaAuxiliar;

        //Este while puede generar problemas, debido a que puede querer
        //realizar un pop_back a una lista que no posee elementos
        while(estado == false){

            Pedido pedidoAnalizado = this->listaDePedidos.pop_back(nuevoPedido);

//listaDePedidos = [30, 20, 10, 15]

            int cantidadFull = pedidoAnalizado.cantidadColchonesFull;
            int cantidadKing = pedidoAnalizado.cantidadColchonesKing;
            int cantidadQueen = pedidoAnalizado.cantidadColchonesQueen;
            int cantidadTwin = pedidoAnalizado.cantidadColchonesTwin;
            //Comprueba si se puede realizar el pedido, en caso de que sí se pueda se entra dentro del if,
            //y dentro de este se cambia el valor booleano de "estado" a true.
            if(comprobarCantidad("Full", cantidadFull) && comprobarCantidad("King", cantidadKing) && comprobarCantidad("Queen", cantidadQueen) && comprobarCantidad("Twin", cantidadTwin)){

                //Si un pedido es realizado, se revisa si listaAuxiliar.size() == 0, si es el caso todo bien, pero
                //si no lo es debemos de sacar el tamaño con el .size y generar un for que saque tantos elementos
                //como el tamaño de la listaAuxiliar diga y lo meta al vector de pedidos.
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
            Pedido pedidoSacado = listaAuxiliar.pop_back();
            this->listaDePedidos.push_back(pedidoSacado);
        }

    }

    bool comprobarCantidad(std::string pNombre, int pCantidadColchon) {
        Stack<ColchonStack *> copiaTarima = tarimaGroup.getTarimasCopy();
        for(int h = 0; h < copiaTarima.largoPila(); h++) {
            Stack<Colchon *> tarimaUnica = copiaTarima.pop();
            for(int k = 0; k < tarimaUnica.largoPila(); k++) {
                Colchon colchonGuardado = tarimaUnica.pop();
                std::string colchonInicial = colchonGuardado.getName();
                if(colchonInicial != pNombre) {
                    //Este espacio vacío es porque no quiero que ocurra 
                    //nada en caso de que el tipo de colchón sea incorrecto
                } else {
                    if(tarimaUnica.largoPila() > pCantidadColchon) {
                        return true;
                        //En este punto, el método podría empezar a sacar
                        //elementos de dicha tarima y meterlo en el camion
                    }
                }
            }
        }
        return false;
    }
//          tarimas = [[{King}, {King}, {King}], [{Queen}, {Queen}, {Queen}]]
    void cargarCamion(std::string pNombre, int pCantidadColchon) {
        //vector temporal mientras se define una pila para camion
        std::vector<Colchon> camion;
        std::vector<ColchonStack *> listaAuxiliar;
        //Lista auxiliar que será usada para guardar los elementos que no correspondan al tipo correcto de datos,
        //una vez el método finaliza, dicha lista auxiliar tendrá que volver a meter los elementos que sacó a la
        //copia directa de tarimas
        Stack<ColchonStack *> copiaDirectaTarimas = tarimaGroup.getTarimas();
        //Con esto se saca un puntero directo a tarimas, si dicha copia es modificada, tarimas también lo hace
        for(int h = 0; h < copiaDirectaTarimas.largoPila(); h++) { //2
            //Se empieza a recorrer la pila tarimas
            Stack<Colchon *> tarimaUnica = copiaDirectaTarimas.pop();
            //Tarima con colchones del mismo tipo
            if(tarimaUnica.largoPila() > pCantidadColchon) {
                for(int k = 0; k < pCantidadColchon; k++) { //3
                    Colchon colchonGuardado = tarimaUnica.pop();
                    std::string nombreColchon = colchonGuardado.getName();
                    if(nombreColchon != pNombre) {
                        tarimaUnica.push(colchonGuardado);
                        listaAuxiliar.push_back(tarimaUnica);
                        Stack<Colchon *> tarimaUnica = copiaDirectaTarimas.pop();
                    } else {
                        camion.push_back(colchonGuardado);
                    }
                }
                int pushes = listaAuxiliar.size();
                for(int g = 0; g < pushes; g++) {
                    copiaDirectaTarimas.push(tarimaUnica)
                    Stack<Colchon *> tarimaUnica = listaAuxiliar.pop_back();
                }
            }else {
                listaAuxiliar.push_back(tarimaUnica);
            }
        }
        int cantidadElementos = listaAuxiliar.size();
        for(int p = 0; p < cantidadElementos; p++) {
            copiaDirectaTarimas.push(tarimaUnica);
            Stack<Colchon *> tarimaUnica = listaAuxiliar.pop_back();
        }
    }
};