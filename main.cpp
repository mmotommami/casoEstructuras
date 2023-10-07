#include "lista.h"
#include "Queue.h"
#include "Stack.h"
#include "colchon.h"
#include "camion.h"
#include <iostream>
#include <thread>


using namespace std;

//Se crearon las pilas y colas necesarias

struct Stack listaAlmacenS;
struct Stack listaAlmacenL;
struct Stack pilaCamion;
struct Queue colaCarga;
struct Queue colaDescarga;

//Se crea el objeto camion, el único dato importante de este objeto es la capacidad máxima, ya que si el peso
//del pedido excede dicha capacidad, el pedido no se puede realizar
camion camion1 = new camion(1000, 2.45, 4.10);

//Valor booleano usado para saber cuando partir con el transporte de productos
bool estadoCarga = false;


void t_carga()
{
    this_thread::sleep_for(1s);  //Este segundo es solo temporal, el tiempo de carga de cada objeto tiene que ser
                                 //sacado con el parser del archivo .json
}

int main(){
//Estos for son para meter colchones a la lista, por ahora desconozco de que manera debería hacerlo
//-------------------------------------------------------------------------------------------------
    for(int i=0; i<10; i++) {
        colchon* miColchon = new colchon("King", 54, "193CMx203CM");
        listaAlmacenS.push(miColchon);
    }

    for(int i=0; i<10; i++) {
        colchon* miColchon = new colchon("Queen", 41, "152CMx203CM");
        listaAlmacenS.push(miColchon);
        
    }

    for(int i=0; i<10; i++) {
        colchon* miColchon = new colchon("Full", 28, "137CMx191CM");
        listaAlmacenS.push(miColchon);
    }

    for(int i=0; i<10; i++) {
        colchon* miColchon = new colchon("Twin", 16, "99CMx191CM");
        listaAlmacenS.push(miColchon);
    }
//-------------------------------------------------------------------------------------------------

//Tengo que definir de que manera se va a solicitar el pedido

//Buscar como sacar la información con un parser

    //Antes de la carga se podría crear una comprobación, en caso de que el peso de los productos del pedido excedan
    //la capacidad máxima del camión

    for(int i=0; i<20; i++) { //En este caso, el 10 se refiere a 10 items, aquí tengo que buscar la manera de hacer que
                              //se cargue según lo que el usuario solicita, por otra parte, lo ideal sería tener una pila
                              //auxiliar a la pila del almacen, esto para poder recorrer la pila del alamacen y buscar con
                              //un getName de cada objeto colchon, para así revisar si el objeto es el que se quiere meter
                              //tipo si se tiene que se quieren meter 10 colchones tipo "King", entonces se va a sacar uno
                              //a uno cada elemento para así aplicarles un getName, si el nombre es el correcto, se añade
                              //a la pila del camion y se pregunta si el pedido está completo, para esto se puede tener un
                              //contador de la cantidad de colchones de cada tipo, una vez está completo, con un parámetro
                              //bool se puede dar arranque al transporte de los productos
        colchon* colchonActual = listaAlmacenS.pop();
        thread carga(t_carga);
        carga.join();
        colaCarga.enqueue(colchonActual);
    }
    //Esto también podría hacerse con un while, mientras la carga esté incompleta (false), repetir el ciclo, una vez se
    //completa, salir de dicho ciclo

    
    
}