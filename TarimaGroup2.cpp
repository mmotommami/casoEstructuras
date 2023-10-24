#ifndef _TARIMAGROUP2_
#define _TARIMAGROUP2_ 0

#include <string>
#include "Colchon.h"
#include "Stack.h"
#include "ConfigLoader.cpp"
#include <vector>
#include "lista.h"
#include <thread>
#include <chrono>

using namespace std;

std::vector<std::vector<Colchon>> vectorTarimas;

class TarimaGroup2
{
private:
    string tipoColchon;

    Stack tarimas;
    Configuracion config;

public:
    TarimaGroup2()
    {
        config = ConfigLoader::LoadConfig();
//        std::thread hiloSecundario(thread_rellenar);
    }

    void rellenar2() {
        vector<int> sizes;
        int cantidadTarimasFull = config.bodega.Full;
        sizes.push_back(cantidadTarimasFull);
        int cantidadTarimasQueen = config.bodega.Queen;
        sizes.push_back(cantidadTarimasQueen);
        int cantidadTarimasTwin = config.bodega.Twin;
        sizes.push_back(cantidadTarimasTwin);
        int cantidadTarimasKing = config.bodega.King;
        sizes.push_back(cantidadTarimasKing);

        vector<string> name = {config.king.name, config.queen.name, config.twin.name, config.full.name};
        vector<int> peso = {config.king.peso, config.queen.peso, config.twin.peso, config.full.peso};
        vector<int> alto = {config.king.alto, config.queen.alto, config.twin.alto, config.full.alto};
        vector<int> ancho = {config.king.ancho, config.queen.ancho, config.twin.ancho, config.full.ancho};
        vector<int> largo = {config.king.largo, config.queen.largo, config.twin.largo, config.full.largo};
        for(int p = 0; p < 4; p++) {
            for(int i = 0; i < sizes[p]; i++){
                std::vector<Colchon> datos = llenarInventario2(name[p], peso[p], alto[p], ancho[p], largo[p]);
                tarimas.push(&datos);
                vectorTarimas.push_back(datos);
                std::cout << vectorTarimas.size() << std::endl;
            }
        }

        std::vector<Colchon> prueba = vectorTarimas.back();
        Colchon colchonPrueba = prueba.back();
        std::cout << colchonPrueba.getPeso() << std::endl;
    }

    vector<Colchon> llenarInventario2(string pName, int pPeso, int pAlto, int pAncho, int pLargo)  //Stack<Colchon *> llenarInventario(string pName, int pPeso, int pAlto, int pAncho, int pLargo)
    {
        std::vector<Colchon> vectorColchones;
        int maxColchonesPorTarima = config.bodega.tarimaSize;
            for(int i=0; i < maxColchonesPorTarima; i++)
            {
                Colchon *nuevoColchon = new Colchon(pName, pPeso, pAlto, pAncho, pLargo);
                Colchon colchonSinPtr = *nuevoColchon;
                vectorColchones.push_back(colchonSinPtr);
            }

        return vectorColchones;
    }

    void prueba() 
    {
        std::cout << "-ñ-ñ-ñ-" << std::endl;
        std::vector<Colchon> prueba = vectorTarimas.back();
        Colchon colchonPrueba = prueba.back();
        std::cout << colchonPrueba.getName() << std::endl;
        std::cout << "-ñ-ñ-ñ-" << std::endl;
    }

    void thread_rellenar() {
        
        while(true)
        {
            rellenar2();
            std::this_thread::sleep_for(std::chrono::seconds(config.bodega.refillTime));
            std::cout << "Se rellenó" << std::endl;
        }
        
    }

};

#endif