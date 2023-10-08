#include <string>
#include "lista.h"     // Incluye el archivo de encabezado "lista.h", que contiene definiciones relacionadas con listas.
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Pedido
{
private:
    int number;         // Almacena el número de pedido.
    int cantidadColchonesFull;
    int cantidadColchonesKing;
    int cantidadColchonesQueen;
    int cantidadColchonesTwin;
//    metodos<Colchon *> colchones;   // Almacena una lista de punteros a objetos de la clase "Colchon".

public:
    Pedido()
    {
        // Inicializa el generador de números aleatorios con la hora actual.
        std::srand(static_cast<unsigned>(std::time(nullptr)));
        
        // Genera un número aleatorio de 9 dígitos.
        int number2 = std::rand() % 900000000 + 100000000;

        number = number2;
        /*
        // Crea una nueva instancia de la lista "metodos" para almacenar punteros a objetos "Colchon".
        colchones = new metodos<Colchon *>();
        */

        cantidadColchonesFull = 0;
        cantidadColchonesKing = 0;
        cantidadColchonesQueen = 0;
        cantidadColchonesTwin = 0;
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
}