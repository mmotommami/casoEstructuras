#ifndef _FLOTILLA_
#define _FLOTILLA_ 0

#include "lista.h"
#include "Camion.h"
#include <vector>

using namespace std;

class Flotilla
{
private:
    Flotilla flotilla;
    vector<Camion> camionesEnviados;
    vector<Colchon> colchonesPorCargar;
    vector<Camion> camiones;  //metodos<Camion *> *camiones
    Configuracion config;

public:
    Flotilla(vector<Camion> pCamiones) {
        config = ConfigLoader::LoadConfig();
        camiones = pCamiones;
        flotilla.null();
    }

    void enviar(Camion pCamion) //metodos<Colchon *> pColchones
    {
        camionesEnviados.push_back(pCamion);
    }

    void asignarCarga(vector<Colchon> pVector) {
        for(int h = 0; h < pVector.size(); h++) {
            Colchon colchon = pVector.back();
            colchonesPorCargar.push_back(colchon);
        }
        std::vector<Camion> vectorAuxiliar;
        while(true) {
            if(camiones.size() != 0 && colchonesPorCargar.size() != 0) {
                Camion camion = camiones.back();
                vectorAuxiliar.push_back(camion);
                camiones.pop_back();
                while(true) {
                    Colchon colchon = colchonesPorCargar.back();
                    colchonesPorCargar.pop_back();
                    camion.addCajon(colchon);
                    if(!camion.getState()) {
                        enviar(camion);
                        break;
                    }
                }
            } else {
                while (vectorAuxiliar.size() != 0) 
                {
                    Camion camion = vectorAuxiliar.back();
                    vectorAuxiliar.pop_back();
                    camiones.push_back(camion);
                }
                
                break;
            }
        }
    }

    Flotilla Flotilla::getInstancia() {
    // Verifica si la instancia ya ha sido creada
    if (flotilla == nullptr) {
        // Si no, crea una nueva instancia                int capacity = config.camion.capacidad;
            int width = config.camion.ancho;
                int length = config.camion.longitud;
        floilla = new Flotilla(r, capacity, width, length);
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
};

#endif