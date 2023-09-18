#ifndef _STACK_
#define _STACK_ 0

#include "lista.h"

struct stack {
    struct pilaCamion listaCamion;
    struct pilaTarimaSalida listaSalida;
    struct pilaTarimaLlegada listaLlegada;

    /*
    "el camion como tal , podria verse tal vez como pila, como por ejemplo los camiones que son cerrados,
    tenes que llenarnos de adentro hacia afuera y cuando se descargan se sacan del frente hacia adentro"
    */

    bool isEmpty() {
        //Métodos aplicados sobre listaCamion
    };

    void push(void* pElement) {
        //Métodos aplicados sobre listaCamion
    };

    void* pop() {
        //Métodos aplicados sobre listaCamion
    }

    //------------------------------------
    /*
    "tambien algo que pueden jugar o pensar, es que a veces las bodegas lo que hay son tarimas
    y lo que subo al camion y bajo de el son tarimans con un montacarga
    si fuera así, vos podes tener pilas de articulos o productos en tarima dentro de la boda"
    */
    //------------------------------------
    
    bool isEmpty() {
        //Métodos aplicados sobre listaSalida
    };

    void push(void* pElement) {
        //Métodos aplicados sobre listaSalida
    };

    void* pop() {
        //Métodos aplicados sobre listaSalida
    }

    //------------------------------------
    /*
    "tambien algo que pueden jugar o pensar, es que a veces las bodegas lo que hay son tarimas
    y lo que subo al camion y bajo de el son tarimans con un montacarga
    si fuera así, vos podes tener pilas de articulos o productos en tarima dentro de la boda"
    */
    //------------------------------------

    bool isEmpty() {
        //Métodos aplicados sobre listaLlegada
    };

    void push(void* pElement) {
        //Métodos aplicados sobre listaLlegada
    };

    void* pop() {
        //Métodos aplicados sobre listaLlegada
    }

};

#endif