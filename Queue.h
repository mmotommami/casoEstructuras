#ifndef _QUEUE_
#define _QUEUE_ 0

#include "lista.h"
//#include "colchon.h"

using namespace std;

struct Queue {
    struct metodos cola;

    //"la cola de carga para subir al camion podríamos pensar en ordenes de cosas que hay que subir a un camion"

    bool estaVacio() {
        return cola.isEmpty();
    };

    void enqueue(void* pElement) {
        cola.addToEnd(pElement);
    };

    void* dequeue() {
        return cola.removeFirst();
    };

};

#endif