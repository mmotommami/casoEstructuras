#ifndef _CONFIG_LOADER_H_
#define _CONFIG_LOADER_H_

#include <iostream>
#include <fstream>
#include "json.hpp"
#include <vector>
#include <string>

using namespace std;

struct ConfigColchones
{
    vector<string> name;
    vector<int> peso;
    vector<int> ancho;
    vector<int> largo;
    vector<int> alto;
};

struct ConfigFull
{
    string name;
    int peso;
    int ancho;
    int largo;
    int alto;
};

struct ConfigRuta1
{
    string name;
    string velocidad;
    int distancia;
    int tiempo;
};

struct ConfigRuta2
{
    string name;
    string velocidad;
    int distancia;
    int tiempo;
};

struct ConfigRuta3
{
    string name;
    string velocidad;
    int distancia;
    int tiempo;
};
struct ConfigRuta4
{
    string name;
    string velocidad;
    int distancia;
    int tiempo;
};

struct ConfigTwin
{
    string name;
    int peso;
    int ancho;
    int largo;
    int alto;
};

struct ConfigQueen
{
    string name;
    int peso;
    int ancho;
    int largo;
    int alto;
};

struct ConfigKing
{
    string name;
    int peso;
    int ancho;
    int largo;
    int alto;
};

struct ConfigRutas
{
    vector<string> name;
    vector<string> velocidad;
    vector<string> distancia;
    vector<int> tiempo;
};

struct ConfigCamion
{
    int cantidadCamiones;
    int capacidad;
    int longitud;
    int altura;
    float ancho;
};

struct ConfigBodega
{
    int Twin;
    int Full;
    int Queen;
    int King;
    int tarimaSize;
    int refillTime;
};

struct ConfigPedidos
{
    int minPedidos;
    int maxPedidos;
    int tiempoEntreGeneracion;
    int minColchonesPorPedido;
    int maxColchonesPorPedido;
    int tiempoEntreEnvioDePedidos;
};

struct Configuracion {
    int hora;
    ConfigCamion camion;
    ConfigBodega bodega;
    ConfigPedidos pedidos;
    ConfigColchones colchones;
    ConfigRutas rutas;
    ConfigFull full;
    ConfigTwin twin;
    ConfigQueen queen;
    ConfigKing king;
    ConfigRuta1 ruta1;
    ConfigRuta2 ruta2;
    ConfigRuta3 ruta3;
    ConfigRuta4 ruta4;
};

class ConfigLoader {
public:
    static Configuracion LoadConfig() {
        Configuracion config;

        ifstream file("configuracion.json");
        if (!file.is_open()) {
            cerr << "Error al abrir el archivo JSON." << endl;
            exit(1);
        }

        nlohmann::json json_data;
        file >> json_data;
        file.close();

//        cout << "JSON data:\n" << json_data.dump(4) << endl;


        config.hora = json_data["hora"];
        config.camion.cantidadCamiones = json_data["cantidadCamiones"];

        // Cargar datos de camion
        const auto& camionData = json_data["camion"];
//        config.camion.cantidadCamiones = camionData["cantidadCamiones"];
        config.camion.capacidad = camionData["capacidad"];
        config.camion.longitud = camionData["longitud"];
        config.camion.altura = camionData["altura"];
        config.camion.ancho = camionData["ancho"];

        const auto& fullData = json_data["Full"];
        config.full.name = fullData["name"];
        config.full.alto = fullData["alto"];
        config.full.ancho = fullData["ancho"];
        config.full.largo = fullData["largo"];
        config.full.peso = fullData["peso"];

        const auto& twinData = json_data["Twin"];
        config.twin.name = twinData["name"];
        config.twin.alto = twinData["alto"];
        config.twin.ancho = twinData["ancho"];
        config.twin.largo = twinData["largo"];
        config.twin.peso = twinData["peso"];

        const auto& queenData = json_data["Queen"];
        config.queen.name = queenData["name"];
        config.queen.alto = queenData["alto"];
        config.queen.ancho = queenData["ancho"];
        config.queen.largo = queenData["largo"];
        config.queen.peso = queenData["peso"];

        const auto& kingData = json_data["King"];
        config.king.name = kingData["name"];
        config.king.alto = kingData["alto"];
        config.king.ancho = kingData["ancho"];
        config.king.largo = kingData["largo"];
        config.king.peso = kingData["peso"];

        const auto& ruta1Data = json_data["ruta1"];
        config.ruta1.name = ruta1Data["name"];
        config.ruta1.velocidad = ruta1Data["velocidad"];
        config.ruta1.distancia = ruta1Data["distancia"];
        config.ruta1.tiempo = ruta1Data["tiempo"];

        const auto& ruta2Data = json_data["ruta2"];
        config.ruta2.name = ruta2Data["name"];
        config.ruta2.velocidad = ruta2Data["velocidad"];
        config.ruta2.distancia = ruta2Data["distancia"];
        config.ruta2.tiempo = ruta2Data["tiempo"];

        const auto& ruta3Data = json_data["ruta3"];
        config.ruta3.name = ruta3Data["name"];
        config.ruta3.velocidad = ruta3Data["velocidad"];
        config.ruta3.distancia = ruta3Data["distancia"];
        config.ruta3.tiempo = ruta3Data["tiempo"];

        const auto& ruta4Data = json_data["ruta4"];
        config.ruta4.name = ruta4Data["name"];
        config.ruta4.velocidad = ruta4Data["velocidad"];
        config.ruta4.distancia = ruta4Data["distancia"];
        config.ruta4.tiempo = ruta4Data["tiempo"];

        config.rutas.tiempo.push_back(config.ruta1.tiempo);
        config.rutas.tiempo.push_back(config.ruta2.tiempo);
        config.rutas.tiempo.push_back(config.ruta3.tiempo);
        config.rutas.tiempo.push_back(config.ruta4.tiempo);

        // Cargar datos de bodega
        const auto& bodegaData = json_data["bodega"];
        config.bodega.Twin = bodegaData["Twin"];
        config.bodega.Full = bodegaData["Full"];
        config.bodega.Queen = bodegaData["Queen"];
        config.bodega.King = bodegaData["King"];
        config.bodega.tarimaSize = bodegaData["tarimaSize"];
        config.bodega.refillTime = bodegaData["refillTime"];

        // Cargar datos de pedidos
        const auto& pedidosData = json_data["pedidos"];
        config.pedidos.minPedidos = pedidosData["minPedidos"];
        config.pedidos.maxPedidos = pedidosData["maxPedidos"];
        config.pedidos.tiempoEntreGeneracion = pedidosData["tiempoEntreGeneracion"];
        config.pedidos.minColchonesPorPedido = pedidosData["minColchonesPorPedido"];
        config.pedidos.maxColchonesPorPedido = pedidosData["maxColchonesPorPedido"];
        config.pedidos.tiempoEntreEnvioDePedidos = pedidosData["tiempoEntreEnvioDePedidos"];

        return config;
    }
};

#endif