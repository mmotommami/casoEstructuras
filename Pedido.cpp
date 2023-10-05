#include <string>
#include "lista.h"

using namespace std;

class Pedido
{
private:
    int number;
    struct t_date fecha;
    metodos<Colchon *> colchones;

public:
    Pedido(int pCantidad)
    {
        // numero de orden puede ser un random grande
        colchones = new metodos<Colchon *>();
    }

    void addColchon(Colchon *pColchon)
    {
        // agrego colchones a la lista
    }

    int getCantidadColchones()
    {
        return colchones->size();
    }
}