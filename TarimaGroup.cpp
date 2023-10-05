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
    metodos<Stack<Colchon *> *> tarimas; //Considero que esta definición es incorrecta, ya que lo ideal sería una
                                         //definicion de Stack que guarde Stacks que guardan Colchones
    Configloader configuracion;

public:
    TarimaGroup()
    {
        ConfigBodega infoBodega = configuracion.getConfigBodega();
        ConfigColchones infoColchones = configuracion.getConfigColchones();
        vector<int> sizes;
        int maxColchonesPorTarima = infoBodega.tarimasize;
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