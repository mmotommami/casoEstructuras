#ifndef _FLOTILLA_
#define _FLOTILLA_ 0

#include "lista.h"
#include "Camion.h"
#include <vector>
#include <thread>
#include <chrono>

using namespace std;

class Flotilla
{
private:
    vector<Camion> camionesEnviados;
    vector<Colchon> colchonesPorCargar;
    vector<Camion> camiones;  //metodos<Camion *> *camiones
    Configuracion config;

public:
    Flotilla() {
        config = ConfigLoader::LoadConfig();
    }

    void enviar(Camion pCamion, int pTiempo) //metodos<Colchon *> pColchones
    {
        std::this_thread::sleep_for(std::chrono::seconds(pTiempo));

        int sizeCajon = pCamion.getSizeCajon();

        for(int t = 0; t < sizeCajon; t++) {
            pCamion.removeCajon();
            std::this_thread::sleep_for(std::chrono::milliseconds(7));
            std::cout << "Un colchon ha sido descargado" << std::endl;
            if(pCamion.getSizeCajon() == 0) {
                break;
            }
        }

        camiones.push_back(pCamion);
        
    }

    void generarCamiones() {
//        vector<Camion> vectorCamion;
        for(int r = 0; r < config.camion.cantidadCamiones; r++) {
            int capacity = config.camion.capacidad;
            int width = config.camion.ancho;
            int length = config.camion.longitud;
            Camion* camionPtr = new Camion(r, capacity, width, length);
            Camion camion = *camionPtr;
            camiones.push_back(camion);
        }
//        camiones = vectorCamion;
    }

    void asignarCarga(vector<Colchon> pVector, int pTiempo) {
        for(int h = 0; h < pVector.size(); h++) {
            Colchon colchon = pVector.back();
            colchonesPorCargar.push_back(colchon);
        }
        std::vector<Camion> vectorAuxiliar;
        while(true) {
            if(camiones.size() != 0 && colchonesPorCargar.size() != 0) {
                Camion camion = camiones.back();
//                vectorAuxiliar.push_back(camion);
                camiones.pop_back();
                while(true) {
                    Colchon colchon = colchonesPorCargar.back();
                    colchonesPorCargar.pop_back();
                    camion.addCajon(colchon);
                    if(!camion.getState()) {
                        enviar(camion, pTiempo);
                        break;
                    }
                }
            } else {
/*
                while (vectorAuxiliar.size() != 0) 
                {
                    Camion camion = vectorAuxiliar.back();
                    vectorAuxiliar.pop_back();
                    camiones.push_back(camion);
                }
*/                
                break;

            }
        }
    }

/*
    Flotilla Flotilla::getInstancia() {
    // Verifica si la instancia ya ha sido creada
        if (flotilla == nullptr) {
            // Si no, crea una nueva instancia                int capacity = config.camion.capacidad;
            int width = config.camion.ancho;
            int length = config.camion.longitud;
            flotilla = new Flotilla(r, capacity, width, length);
        }
        return *flotilla;
    }



    Flotilla getInstancia() {
        if(flotilla == nullptr  ) {
            vector<Camion> vectorCamion;
            for(int r = 0; r < config.camion.cantidadCamiones; r++) {
                int capacity = config.camion.capacidad;
                int width = config.camion.ancho;
                int length = config.camion.longitud;
                Camion* camionPtr = new Camion(r, capacity, width, length);
                Camion camion = *camionPtr;
                vectorCamion.push_back(camion);
            }
                Flotilla* flotillaPtr = new Flotilla(vectorCamion);
                Flotilla flotilla = *flotillaPtr;
        } else {
            return flotilla;
        }
    }
*/
};

#endif