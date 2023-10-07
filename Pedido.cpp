#include <string>
<<<<<<< HEAD
#include "lista.h"     // Incluye el archivo de encabezado "lista.h", que contiene definiciones relacionadas con listas.
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;   // Utiliza el espacio de nombres "std" para que las clases y funciones estándar de C++ se puedan usar sin anteponer "std::".
=======
#include "lista.h"

using namespace std;
>>>>>>> bf8eb10e6acccf1baf9e52cd97b29303a7b412b2

class Pedido
{
private:
<<<<<<< HEAD
    int number;         // Almacena el número de pedido.
    struct t_date fecha;    // Almacena una estructura de fecha (la definición no se proporciona en este código).
    metodos<Colchon *> colchones;   // Almacena una lista de punteros a objetos de la clase "Colchon".
=======
    int number;
    struct t_date fecha;
    metodos<Colchon *> colchones;
>>>>>>> bf8eb10e6acccf1baf9e52cd97b29303a7b412b2

public:
    Pedido(int pCantidad)
    {
<<<<<<< HEAD
        // Inicializa el generador de números aleatorios con la hora actual.
        std::srand(static_cast<unsigned>(std::time(nullptr)));
        
        // Genera un número aleatorio de 9 dígitos.
        number = std::rand() % 900000000 + 100000000;
        
        // Crea una nueva instancia de la lista "metodos" para almacenar punteros a objetos "Colchon".
=======
        // numero de orden puede ser un random grande
>>>>>>> bf8eb10e6acccf1baf9e52cd97b29303a7b412b2
        colchones = new metodos<Colchon *>();
    }

    void addColchon(Colchon *pColchon)
    {
<<<<<<< HEAD
        // Agrega un objeto "Colchon" a la lista "colchones" al principio de la lista.
        colchones.addToBegining(pColchon);
=======
        // agrego colchones a la lista
>>>>>>> bf8eb10e6acccf1baf9e52cd97b29303a7b412b2
    }

    int getCantidadColchones()
    {
<<<<<<< HEAD
        // Devuelve el tamaño actual de la lista "colchones" (cantidad de objetos "Colchon" almacenados).
=======
>>>>>>> bf8eb10e6acccf1baf9e52cd97b29303a7b412b2
        return colchones->size();
    }
}