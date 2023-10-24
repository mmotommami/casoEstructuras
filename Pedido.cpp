#ifndef _PEDIDO_
#define _PEDIDO_

#include <string>
#include "lista.h"     // Incluye el archivo de encabezado "lista.h", que contiene definiciones relacionadas con listas.
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Pedido
{
private:
    int tiempo;
    int number;
    int cantidadColchonesFull;
    int cantidadColchonesKing;
    int cantidadColchonesQueen;
    int cantidadColchonesTwin;

    //Crear arrayDeEnteros para guardar todas las cantidades de colchones

//    metodos<Colchon *> colchones;   // Almacena una lista de punteros a objetos de la clase "Colchon".

public:
    Pedido()
    {
        // Inicializa el generador de números aleatorios con la hora actual.
        std::srand(static_cast<unsigned>(std::time(nullptr)));
        
        // Genera un número aleatorio de 9 dígitos.
        int number2 = std::rand() % 900000000 + 100000000;

        number = number2;
        cantidadColchonesFull = 0;
        cantidadColchonesKing = 0;
        cantidadColchonesQueen = 0;
        cantidadColchonesTwin = 0;
        /*
        // Crea una nueva instancia de la lista "metodos" para almacenar punteros a objetos "Colchon".
        colchones = new metodos<Colchon *>();
        */
    }

    // Getter para el tiempo
    int getTiempo() const
    {
        return tiempo;
    }

    // Getter para la cantidad de colchones Full.
    int getCantidadColchonesFull() const
    {
        return cantidadColchonesFull;
    }

    // Getter para la cantidad de colchones King.
    int getCantidadColchonesKing() const
    {
        return cantidadColchonesKing;
    }

    // Getter para la cantidad de colchones Queen.
    int getCantidadColchonesQueen() const
    {
        return cantidadColchonesQueen;
    }

    // Getter para la cantidad de colchones Twin.
    int getCantidadColchonesTwin() const
    {
        return cantidadColchonesTwin;
    }

    void setTiempo(int pTiempo)
    {
        tiempo = pTiempo;
    }

    void setCantidadColchonesFull(int cantidad)
    {
        cantidadColchonesFull = cantidad;
    }

    void setCantidadColchonesKing(int cantidad)
    {
        cantidadColchonesKing = cantidad;
    }

    void setCantidadColchonesQueen(int cantidad)
    {
        cantidadColchonesQueen = cantidad;
    }

    void setCantidadColchonesTwin(int cantidad)
    {
        cantidadColchonesTwin = cantidad;
    }
/*
    void addColchon(Colchon *pColchon)
    {
        // Agrega un objeto "Colchon" a la lista "colchones" al principio de la lista.
        colchones.addToBegining(pColchon);
    }

    int getCantidadColchones()
    {
        // Devuelve el tamaño actual de la lista "colchones" (cantidad de objetos "Colchon" almacenados).
        return colchones->size();
    }
*/
};

#endif