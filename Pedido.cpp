#include <string>
#include "lista.h"     // Incluye el archivo de encabezado "lista.h", que contiene definiciones relacionadas con listas.
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;   // Utiliza el espacio de nombres "std" para que las clases y funciones estándar de C++ se puedan usar sin anteponer "std::".

class Pedido
{
private:
    int number;         // Almacena el número de pedido.
    struct t_date fecha;    // Almacena una estructura de fecha (la definición no se proporciona en este código).
    metodos<Colchon *> colchones;   // Almacena una lista de punteros a objetos de la clase "Colchon".

public:
    Pedido(int pCantidad)
    {
        // Inicializa el generador de números aleatorios con la hora actual.
        std::srand(static_cast<unsigned>(std::time(nullptr)));
        
        // Genera un número aleatorio de 9 dígitos.
        number = std::rand() % 900000000 + 100000000;
        
        // Crea una nueva instancia de la lista "metodos" para almacenar punteros a objetos "Colchon".
        colchones = new metodos<Colchon *>();
    }

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
}