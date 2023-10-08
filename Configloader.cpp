#include <iostream>
#include <fstream>
#include "json.hpp"
#include <vector>

using namespace std;

struct ConfigRutas
{
    vector<string> name;
    vector<string> velocidad;
    vector<string> distancia;
    vector<int> tiempo;
};

struct ConfigColchones
{
    vector<string> name;
    vector<int> pesoColchon;
    vector<int> anchoColchon;
    vector<int> largoColchon;
    vector<int> altoColchon;
};

struct ConfigBodega
{
    int twinquantity; //Cantidad de tarimas para este tipo de colchon
    int fullquantity;
    int queenquantity;
    int kingquantity;
    int tarimasize; //Cantidad de colchones por tarima
    int refilltime;
};

struct ConfigPedidos
{
    int minPedidos;
    int maxPedidos;
    int tiempoEntreGeneracion;
    int minColchonesPorPedido;
    int maxColchonesPorPedido;
    int tiempoEntrePedidos;
};

struct ConfigCamiones
{
    int cantidadCamiones;
    int capacidad;
    int largo;
    int ancho;
    int alto;
};

class Configloader
{
private:
    ConfigBodega configbodega;
    ConfigPedidos configpedidos;
    ConfigCamiones configcamiones;
    ConfigColchones configcolchones;
    ConfigRutas configrutas;

public:
    Configloader()
    {
        loadAllJson();
    }

    void loadAllJson()
    {
        // Open the JSON file for reading
        std::ifstream file("configuracion.json");
    
        if (!file.is_open()) {
            std::cerr << "Failed to open the JSON file." << std::endl;
            return 1;
        }

        // Parse the JSON data
        nlohmann::json json_data;
        file >> json_data;

        // Close the file
        file.close();

        // Access and use the JSON data
        std::string name = json_data["name"];
        nlohmann::json pedidos = json_data["pedidos"];

        int minPedidosJ = pedidos["minPedidos"];
        int maxPedidosJ = pedidos["maxPedidos"];

        //Tiempo de cada cuanto se generan los pedidos
        int tiempoEntreGeneracionJ = pedidos["tiempoEntreGeneracion"];
        int minColchonesPorPedidoJ = pedidos["minColchonesPorPedido"];
        int maxColchonesPorPedidoJ = pedidos["maxColchonesPorPedido"];

        //Tiempo de cada cuanto se envía el/los camión/camiones de un pedido
        int tiempoEntreEnvioDePedidosJ = pedidos["tiempoEntreEnvioDePedidos"];

        configpedidos.minPedidos = minPedidosJ;
        configpedidos.maxPedidos = maxPedidosJ;
        configpedidos.tiempoEntreGeneracion = tiempoEntreGeneracionJ;
        configpedidos.minColchonesPorPedido = minColchonesPorPedidoJ;
        configpedidos.maxColchonesPorPedido = maxColchonesPorPedidoJ;
        configpedidos.tiempoEntrePedidos = tiempoEntreEnvioDePedidosJ;

        //Cantidad de pilas de cada producto
        int twinQuantityJ = bodega["Twin"];
        int queenQuantityJ = bodega["Queen"];
        int kingQuantityJ = bodega["King"];
        int fullQuantityJ = bodega["Full"];

        //Cantidad de productos por fila/tarima
        int tarimaSizeJ = bodega["tarimaSize"];

        //Tiempo de relleno de pilas/tarimas
        int refillTimeJ = bodega["refillTime"];

        configbodega.twinquantity = twinQuantityJ;
        configbodega.queenquantity = queenQuantityJ;
        configbodega.kingquantity = kingQuantityJ;
        configbodega.fullquantity = fullQuantityJ;
        configbodega.tarimasize = tarimaSizeJ;
        configbodega.refilltime = refillTimeJ;

        //Datos de los camiones
        int camiones = json_data["cantidadCamiones"];
        nlohmann::json camion = json_data["camion"];

        int capacidadCamionJ = camion["capacidad"];
        int largoCamionJ = camion["longitud"];
        int altoCamionJ = camion["alto"];
        int anchoCamionJ = camion["ancho"];

        configcamiones.cantidadCamiones = camiones;
        configcamiones.capacidad = capacidadCamionJ;
        configcamiones.largo = largoCamionJ;
        configcamiones.alto = altoCamionJ;
        configcamiones.ancho = anchoCamionJ;

        nlohmann::json colchon = json_data["colchones"];

        for(auto colchones : colchon) 
        {
            configcolchones.name.push_back(colchon["name"]);
            configcolchones.pesoColchon.push_back(colchon["peso"]);
            configcolchones.anchoColchon.push_back(colchon["ancho"]);
            configcolchones.largoColchon.push_back(colchon["largo"]);
            configcolchones.altoColchon.push_back(colchon["alto"]);
        }

        nlohmann::json ruta = json_data["rutas"];

        for(auto rutas : ruta) 
        {
            configrutas.name.push_back(ruta["name"]);
            configrutas.velocidad.push_back(ruta["velocidad"]);
            configrutas.distancia.push_back(ruta["distancia"]);
            configrutas.tiempo.push_back(ruta["tiempo"]);
        }
/*
        // Print the parsed data
        std::cout << "Name: " << name << std::endl;
        std::cout << "Cantidad camiones: " << camiones << std::endl;
*/

        return 0;
    }

    ConfigBodega getConfigBodega() const 
    {
        return configbodega;
    }
    
    ConfigPedidos getConfigPedidos() const 
    {
        return configpedidos;
    }

    ConfigCamiones getConfigCamiones() const
    {
        return configcamiones;
    }

    ConfigRutas getConfigRutas() const
    {
        return configrutas;
    }

    ConfigColchones getConfigColchones() const
    {
        return configcolchones;
    }
};


/*
    //La mejor manera de sacar los datos de estos getters es a traves de un arrayList o un vector,
    //de manera que se agreguen todos los datos dentro del arrayList para luego meterlos
    //donde se necesiten, de esta manera no habría que hacer un getter para cada cosa.


    void getConfiguracionDeBodega(vector<int>& listaConfigBodega)
    {
        listaConfigBodega.push_back(configbodega.twinquantity);
        listaConfigBodega.push_back(configbodega.fullquantity);
        listaConfigBodega.push_back(configbodega.queenquantity);
        listaConfigBodega.push_back(configbodega.kingquantity);
        listaConfigBodega.push_back(configbodega.tarimasize);
        listaConfigBodega.push_back(configbodega.refilltime);
    }

    void getConfiguracionPedidos(vector<int>& listaConfigPedidos)
    {
        listaConfigPedidos.push_back(configpedidos.minPedidos);
        listaConfigPedidos.push_back(configpedidos.maxPedidos);
        listaConfigPedidos.push_back(configpedidos.minColchonesPorPedido);
        listaConfigPedidos.push_back(configpedidos.maxColchonesPorPedido);
        listaConfigPedidos.push_back(configpedidos.tiempoEntreGeneracion);
        listaConfigPedidos.push_back(configpedidos.tiempoEntrePedidos);
    }

    void getConfiguracionCamiones(vector<int>& listaConfigCamiones)
    {
        listaConfigCamiones.push_back(configcamiones.cantidadCamiones);
        listaConfigCamiones.push_back(configcamiones.capacidad);
        listaConfigCamiones.push_back(configcamiones.largo);
        listaConfigCamiones.push_back(configcamiones.ancho);
        listaConfigCamiones.push_back(configcamiones.alto);
    }

    void getConfiguracionRutas(vector<ConfigRutas>& vectorDeVectoresRuta)
    {
        vectorDeVectoresRuta.push_back(configrutas);
    }
    

 Manera de guardar en un vector distintos tipos de datos
#include <iostream>
#include <vector>
#include <string>

// Definición de una estructura que contiene diferentes tipos de datos
struct Registro {
    int entero;
    double flotante;
    std::string cadena;
};

int main() {
    // Crear un vector de estructuras Registro
    std::vector<Registro> vectorDeRegistros;

    // Crear objetos de la estructura Registro y agregarlos al vector
    Registro registro1 = {42, 3.14159, "Hola"};
    Registro registro2 = {123, 2.71828, "Mundo"};

    vectorDeRegistros.push_back(registro1);
    vectorDeRegistros.push_back(registro2);

    // Acceder a los elementos del vector y sus campos
    std::cout << "Entero del primer registro: " << vectorDeRegistros[0].entero << std::endl;
    std::cout << "Cadena del segundo registro: " << vectorDeRegistros[1].cadena << std::endl;

    return 0;
}
*/
