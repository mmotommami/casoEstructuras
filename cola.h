#ifndef _QUEUE_
#define _QUEUE_ 0

#include "lista.h"

struct queue {
    struct colaCarga listaCarga;
    struct colaDescarga listaDescarga;

    //"la cola de carga para subir al camion podríamos pensar en ordenes de cosas que hay que subir a un camion"

    bool isEmpty() {
        //metodos aplicados a listaCarga
    };

    void agregarACola(void* pElement) {
        //metodos aplicados a listaCarga
    };

    void* sacarDeCola() {
        //metodos aplicados a listaCarga
    }

    //---------------------------------

        bool isEmpty() {
        //metodos aplicados a listaDescarga
    };

    void agregarACola(void* pElement) {
        //metodos aplicados a listaDescarga
    };

    void* sacarDeCola() {
        //metodos aplicados a listaDescarga
    }


};

#endif