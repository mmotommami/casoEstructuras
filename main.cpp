#include "Simulador.cpp"
#include "ConfigLoader.cpp"

#include <iostream>

int main()
{
    // Crear una instancia de Simulador
    Simulador simulador;

    Configuracion config = ConfigLoader::LoadConfig();

    Stack pila;
    int numero = 1;
    pila.push(&numero);
    int* ayudaPtr = static_cast<int*>(pila.pop());
    int  ayuda = *ayudaPtr;
    std::cout << ayuda << std::endl;
    std::cout << pila.largoPila() << std::endl;
    std::cout << "ayudaaaaaaaaaa" << std::endl;


    // Imprimir los valores de la configuración de la bodega
    std::cout << "Configuración de la bodega:" << std::endl;
    std::cout << "Twin Quantity: " << config.bodega.Twin << std::endl;
    std::cout << "Full Quantity: " << config.bodega.Full << std::endl;
    std::cout << "Queen Quantity: " << config.bodega.Queen << std::endl;
    std::cout << "King Quantity: " << config.bodega.King << std::endl;
    std::cout << "Tarima Size: " << config.bodega.tarimaSize << std::endl;
    std::cout << "Refill Time: " << config.bodega.refillTime << std::endl;
    
    vector<string> name = {config.king.name, config.queen.name, config.twin.name, config.full.name};
    vector<int> peso = {config.king.peso, config.queen.peso, config.twin.peso, config.full.peso};
    vector<int> alto = {config.king.alto, config.queen.alto, config.twin.alto, config.full.alto};
    vector<int> ancho = {config.king.ancho, config.queen.ancho, config.twin.ancho, config.full.ancho};
    vector<int> largo = {config.king.largo, config.queen.largo, config.twin.largo, config.full.largo};

    std::cout << "Configuración de colchones:" << std::endl;
    for (size_t i = 0; i < 4; ++i) {
        std::cout << "Nombre: " << name[i] << std::endl;
        std::cout << "Peso: " << peso[i] << std::endl;
        std::cout << "Ancho: " << ancho[i] << std::endl;
        std::cout << "Largo: " << largo[i] << std::endl;
        std::cout << "Alto: " << alto[i] << std::endl;
        std::cout << std::endl; // Separador entre colchones
    }

/*
    // Obtener la configuración de la bodega y almacenarla en un objeto
    ConfigBodega configBodega = Configloader.getConfigBodega();

    // Obtener la configuración de colchones y almacenarla en un objeto
    ConfigColchones configColchones = configLoader.getConfigColchones();

    // Imprimir los valores de la configuración de la bodega
    std::cout << "Configuración de la bodega:" << std::endl;
    std::cout << "Twin Quantity: " << configBodega.twinquantity << std::endl;
    std::cout << "Full Quantity: " << configBodega.fullquantity << std::endl;
    std::cout << "Queen Quantity: " << configBodega.queenquantity << std::endl;
    std::cout << "King Quantity: " << configBodega.kingquantity << std::endl;
    std::cout << "Tarima Size: " << configBodega.tarimasize << std::endl;
    std::cout << "Refill Time: " << configBodega.refilltime << std::endl;

    // Imprimir los valores de la configuración de colchones
    std::cout << "Configuración de colchones:" << std::endl;
    for (size_t i = 0; i < configColchones.name.size(); ++i) {
        std::cout << "Nombre: " << configColchones.name[i] << std::endl;
        std::cout << "Peso: " << configColchones.pesoColchon[i] << std::endl;
        std::cout << "Ancho: " << configColchones.anchoColchon[i] << std::endl;
        std::cout << "Largo: " << configColchones.largoColchon[i] << std::endl;
        std::cout << "Alto: " << configColchones.altoColchon[i] << std::endl;
        std::cout << std::endl; // Separador entre colchones
    }

    // Ejecutar la simulación
 //   simulador.initSimulation();

    // Puedes agregar aquí la lógica adicional si es necesario
*/
    std::cout << "Hola, mundo!" << std::endl;
    return 0;
};
