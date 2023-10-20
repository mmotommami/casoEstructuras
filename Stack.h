#ifndef _STACK_
#define _STACK_ 0

#include "lista.h"

struct Stack
{
    struct metodos pila;

    /*
    "el camion como tal , podria verse tal vez como pila, como por ejemplo los camiones que son cerrados,
    tenes que llenarnos de adentro hacia afuera y cuando se descargan se sacan del frente hacia adentro"
    */
    int largoPila()
    {
        return pila.getSize();
    }

    bool estaVacio()
    {
        return pila.isEmpty();
    };

    void push(void *pElement)
    {
        pila.addToBegining(pElement);
    };

    void *pop()
    {
        return pila.removeFirst();
    }
};

#endif