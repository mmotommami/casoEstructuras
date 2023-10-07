#include <string>
#include "Colchon.h"
#include "Stack.h"
#include "Configloader.cpp"
#include <vector>

using namespace std;

class TarimaGroup
{
private:
    int cantidadColchones;
    string tipoColchon;
<<<<<<< HEAD
    typedef Stack<Colchon *> ColchonStack; // Alias para Stack<Colchon *>

    metodos<ColchonStack *> tarimas; // Almacena Stacks que guardan Colchones
=======
    metodos<Stack<Colchon *> *> tarimas; //Considero que esta definición es incorrecta, ya que lo ideal sería una
                                         //definicion de Stack que guarde Stacks que guardan Colchones
>>>>>>> bf8eb10e6acccf1baf9e52cd97b29303a7b412b2
    Configloader configuracion;

public:
    TarimaGroup()
    {
<<<<<<< HEAD
        // Configurar y llenar las tarimas al crear un objeto TarimaGroup

=======
>>>>>>> bf8eb10e6acccf1baf9e52cd97b29303a7b412b2
        ConfigBodega infoBodega = configuracion.getConfigBodega();
        ConfigColchones infoColchones = configuracion.getConfigColchones();
        vector<int> sizes;
        int maxColchonesPorTarima = infoBodega.tarimasize;
<<<<<<< HEAD
        
        // Llenar el vector "sizes" con la cantidad de tarimas de cada tipo
        int cantidadTarimasFull = infoBodega.fullquantity;
        sizes.push_back(cantidadTarimasFull);
        int cantidadTarimasQueen = infoBodega.queenquantity;
        sizes.push_back(cantidadTarimasQueen);
        int cantidadTarimasTwin = infoBodega.twinquantity;
        sizes.push_back(cantidadTarimasTwin);
        int cantidadTarimasKing = infoBodega.kingquantity;
        sizes.push_back(cantidadTarimasKing);
        
=======
        int cantidadTarimasFull = infoBodega.fullquantity;
        sizes.push:back(cantidadTarimasFull);
        int cantidadTarimasQueen = infoBodega.queenquantity;
        sizes.push:back(cantidadTarimasQueen);
        int cantidadTarimasTwin = infoBodega.twinquantity;
        sizes.push:back(cantidadTarimasTwin);
        int cantidadTarimasKing = infoBodega.kingquantity;
        sizes.push:back(cantidadTarimasKing);
>>>>>>> bf8eb10e6acccf1baf9e52cd97b29303a7b412b2
        vector<string> name = infoColchones.name;
        vector<int> peso = infoColchones.pesoColchon;
        vector<int> alto = infoColchones.altoColchon;
        vector<int> ancho = infoColchones.anchoColchon;
        vector<int> largo = infoColchones.largoColchon;
<<<<<<< HEAD
        
        // Llenar las tarimas con colchones según las cantidades y características
        for(int j = 0; j < 4; j++) {
=======
        for(int j = 0; i < 4; i++) {
>>>>>>> bf8eb10e6acccf1baf9e52cd97b29303a7b412b2
            for(int i = 0; i < sizes[j]; i++){
                tarimas.push(llenarInventario(name[j], peso[j], alto[j], ancho[j], largo[j], maxColchonesPorTarima));
            }
        }
    }

    void rellenar() {
        ConfigBodega infoBodega = configuracion.getConfigBodega();
        ConfigColchones infoColchones = configuracion.getConfigColchones();
        vector<int> sizes;
        int cantidadTarimasFull = infoBodega.fullquantity;
        sizes.push:back(cantidadTarimasFull);
        int cantidadTarimasQueen = infoBodega.queenquantity;
        sizes.push:back(cantidadTarimasQueen);
        int cantidadTarimasTwin = infoBodega.twinquantity;
        sizes.push:back(cantidadTarimasTwin);
        int cantidadTarimasKing = infoBodega.kingquantity;
        sizes.push:back(cantidadTarimasKing);
        vector<string> name = infoColchones.name;
        vector<int> peso = infoColchones.pesoColchon;
        vector<int> alto = infoColchones.altoColchon;
        vector<int> ancho = infoColchones.anchoColchon;
        vector<int> largo = infoColchones.largoColchon;
        for(int j = 0; i < 4; i++) {
            for(int i = 0; i < sizes[j]; i++){
                tarimas.push(llenarInventario(name[j], peso[j], alto[j], ancho[j], largo[j]));
            }
        } 
    }

<<<<<<< HEAD
    Stack<Colchon *> llenarInventario(string pName, int pPeso, int pAlto, int pAncho, int pLargo, int maxColchonesPorTarima)
    {
        Stack<Colchon *> tarima;  // Definimos un Stack para una tarima que contendrá objetos Colchon
        ConfigBodega infoBodega = configuracion.getConfigBodega();
        for(int i = 0; i < maxColchonesPorTarima; i++)
        {
            Colchon *colchon = new Colchon(pName, pPeso, pAlto, pAncho, pLargo);
            tarima.push(colchon);
        }
        return tarima;
    }

    metodos<Colchon *> sacarColchones(int pCantidad){
        metodos<Colchon *> colchonesSacados;  // Crear una lista para almacenar los colchones sacados
    
        // Supongamos que deseas sacar colchones de la primera tarima
        if (!tarimas.isEmpty()) {
            ColchonStack tarima = tarimas.removeFirst();  // Obtener la primera tarima de la lista
    
            // Sacar pCantidad de colchones de la tarima
            for (int i = 0; i < pCantidad; i++) {
                Colchon *colchon = tarima.pop();  // Sacar un colchon de la tarima
                if (colchon != nullptr) {
                    colchonesSacados.addToEnd(colchon);  // Agregar el colchon a la lista de colchones sacados
                } else {
                    // Si no hay más colchones en la tarima, salir del bucle
                    break;
                }
            }
    
            // Si quedan colchones en la tarima, devolverla a la lista de tarimas
            if (!tarima.isEmpty()) {
                tarimas.addToBegining(tarima);
            }
        }
    
        return colchonesSacados;  // Devolver la lista de colchones sacados
    }

    
}
=======
    Stack<Colchon *> llenarInventario(string pName, int pPeso, int pAlto, int pAncho, int pLargo)
    {
        Stack<Colchon *> tarimas;  //Esta definicion es incorrecta, ya que el Stack<Colchon *> es la manera de definir
                                   //un vector, para crear un Stack que guarde objetos tipo Colchon nada más se define
                                   //un Stack y se hace push a objetos tipo Colchon, ya que el Stack recibe tipo void
                                   //por lo que se puede insertar cualquier tipo de dato
        ConfigBodega infoBodega = configuracion.getConfigBodega();
        int maxColchonesPorTarima = infoBodega.tarimasize;
            for(int i=0; i < maxColchonesPorTarima; i++)
            {
                Colchon colchon = new Colchon(pName, pPeso, pAlto, pAncho, pLargo);
                tarimas.push(colchon);
            }
            // inicializar la lista de tarimas y puedo meter los colchones
        return tarimas;
    }

    metodos<Colchon *> sacarColchones(int pCantidad)
    {
    }
}
>>>>>>> bf8eb10e6acccf1baf9e52cd97b29303a7b412b2
