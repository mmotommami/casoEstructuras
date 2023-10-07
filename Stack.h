#ifndef _STACK_
#define _STACK_ 0

#include "lista.h"
// #include "colchon.h"

// usar el generic
struct Stack
{
    struct metodos pila;

    /*
    "el camion como tal , podria verse tal vez como pila, como por ejemplo los camiones que son cerrados,
    tenes que llenarnos de adentro hacia afuera y cuando se descargan se sacan del frente hacia adentro"
    */

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