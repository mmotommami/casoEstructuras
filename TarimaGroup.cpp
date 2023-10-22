#ifndef _TARIMAGROUP_
#define _TARIMAGROUP_ 0

#include <string>
#include "Colchon.h"
#include "Stack.h"
#include "ConfigLoader.cpp"
#include <vector>
#include "lista.h"

using namespace std;

class TarimaGroup  //Convertir
{
private:
    int cantidadColchones;
    string tipoColchon;
//    typedef Stack<Colchon *> ColchonStack; // Alias para Stack<Colchon *>

    Stack tarimas;         //Stack<ColchonStack *> tarimas; // Almacena Stacks que guardan Colchones
    Configuracion config;
    std::vector<Stack> vectorTarimas;

//tarimas es una pila que guarda pilas de colchones

public:
    TarimaGroup()
    {
        config = ConfigLoader::LoadConfig();
        /*
        ConfigBodega infoBodega = configuracion.getConfigBodega();
        ConfigColchones infoColchones = configuracion.getConfigColchones();
        vector<int> sizes;
        int maxColchonesPorTarima = infoBodega.tarimasize;
        int cantidadTarimasFull = infoBodega.fullquantity;
        sizes.push_back(cantidadTarimasFull);
        int cantidadTarimasQueen = infoBodega.queenquantity;
        sizes.push_back(cantidadTarimasQueen);
        int cantidadTarimasTwin = infoBodega.twinquantity;
        sizes.push_back(cantidadTarimasTwin);
        int cantidadTarimasKing = infoBodega.kingquantity;
        sizes.push_back(cantidadTarimasKing);
        vector<string> name = infoColchones.name;
        vector<int> peso = infoColchones.pesoColchon;
        vector<int> alto = infoColchones.altoColchon;
        vector<int> ancho = infoColchones.anchoColchon;
        vector<int> largo = infoColchones.largoColchon;
        for(int j = 0; j < 4; j++) {
            for(int i = 0; i < sizes[j]; i++){
                tarimas.push(llenarInventario(name[j], peso[j], alto[j], ancho[j], largo[j]));
            }
        }
        */
    }

    void rellenar() {
        vector<int> sizes;
        int cantidadTarimasFull = config.bodega.Full;
        sizes.push_back(cantidadTarimasFull);
        int cantidadTarimasQueen = config.bodega.Queen;
        sizes.push_back(cantidadTarimasQueen);
        int cantidadTarimasTwin = config.bodega.Twin;
        sizes.push_back(cantidadTarimasTwin);
        int cantidadTarimasKing = config.bodega.King;
        sizes.push_back(cantidadTarimasKing);

//sizes = [10, 8, 20, 10]
//name = [King, Queen, Full, Twin]
//tarimas = [[{King}, {King}, {King}], [{Queen}, {Queen}, {Queen}]]
        vector<string> name = {config.king.name, config.queen.name, config.twin.name, config.full.name};
        vector<int> peso = {config.king.peso, config.queen.peso, config.twin.peso, config.full.peso};
        vector<int> alto = {config.king.alto, config.queen.alto, config.twin.alto, config.full.alto};
        vector<int> ancho = {config.king.ancho, config.queen.ancho, config.twin.ancho, config.full.ancho};
        vector<int> largo = {config.king.largo, config.queen.largo, config.twin.largo, config.full.largo};
        for(int p = 0; p < 4; p++) {
//            std::cout << "---a" << std::endl;
//            std::cout << sizes[p] << std::endl;
            //Hasta aquí todo bien
            for(int i = 0; i < sizes[p]; i++){
//                std::cout << "Marca para saber si el problema es con el size" << std::endl;
//                tarimas.pop();
//                std::cout << tarimas.largoPila() << std::endl;
                Stack datos = llenarInventario(name[p], peso[p], alto[p], ancho[p], largo[p]);
//                Stack* datosPtr = &datos;
//                tarimas.push(&datos);
//                std::cout << datos.largoPila() << std::endl;
//                agregarTarima(datos);
                tarimas.push(&datos);
                vectorTarimas.push_back(datos);
                std::cout << vectorTarimas.size() << std::endl;
//                std::cout << "marca" << std::endl;
//                std::cout << sizeOfTarima() << std::endl;
//                std::cout << "marca" << std::endl;
            }
        }
        
        Stack* prueba = static_cast<Stack*>(tarimas.pop());
        std::cout << "..." << std::endl;
        Stack pila = *prueba;
        std::cout << pila.largoPila() << std::endl;
        std::cout << "..." << std::endl;
        Colchon* colchonPtr4 = static_cast<Colchon*>(pila.pop());
        std::cout << "..." << std::endl;
        Colchon jsjs = *colchonPtr4;
        std::cout << "..." << std::endl;
        int k = jsjs.getPeso();
        std::cout << k << std::endl;
        string ar = colchonPtr4->getName();
        std::cout << ar << std::endl;
        std::cout << "..." << std::endl;
        std::cout << "Cantidad de elementos de tarimas" << std::endl;
        std::cout << tarimas.largoPila() << std::endl;
        std::cout << "Cantidad de elementos de tarimas" << std::endl;
        
    }

// tarimas = [[{objetoColchon<Tipo Específico(King, Queen, etc)>}, {objetoColchon<Tipo Específico(King, Queen, etc)>}], [{objetoColchon<Tipo Específico(King, Queen, etc)>}], [{objetoColchon<Tipo Específico(King, Queen, etc)>}]]
// Al acceder a "tarimas", se accede inicialmente a un Stack que guarda objetos de tipo "Colchon", si se accede a dicho
// objeto, se puede usar el nombre del objeto como la key name para obtener cual tipo de colchón es, si el colchón es el
// correcto, se puede verificar si la cantidad es la correcta

    Stack llenarInventario(string pName, int pPeso, int pAlto, int pAncho, int pLargo)  //Stack<Colchon *> llenarInventario(string pName, int pPeso, int pAlto, int pAncho, int pLargo)
    {
        Stack tarimas2;   
        //Stack<Colchon *> tarimas2; //Esta definicion es incorrecta, ya que el Stack<Colchon *> es la manera de definir
                                     //un vector, para crear un Stack que guarde objetos tipo Colchon nada más se define
                                     //un Stack y se hace push a objetos tipo Colchon, ya que el Stack recibe tipo void
                                     //por lo que se puede insertar cualquier tipo de dato
        int maxColchonesPorTarima = config.bodega.tarimaSize;
            for(int i=0; i < maxColchonesPorTarima; i++)
            {
//                std::cout << "Se creó elemento" << std::endl;
/*
                Colchon* colchonPtr = new Colchon(pName, pPeso, pAlto, pAncho, pLargo);
                Colchon colchon = *colchonPtr;
                colchon.getName();
*/
                Colchon* colchon = generarColchon(pName, pPeso, pAlto, pAncho, pLargo);
                tarimas2.push(colchon);
            }
            // inicializar la lista de tarimas y puedo meter los colchones
//        std::cout << tarimas2.largoPila() << std::endl;  //Siempre es 100 debido a que es lo que trae el json
//        std::cout << "!2#$%&/()=?¡134567890" << std::endl;
/*
        std::cout << "Cantidad de elementos Colchon" << std::endl;
        std::cout << tarimas2.largoPila() << std::endl;
        std::cout << "Cantidad de elementos Colchon" << std::endl;
*/
        return tarimas2;
    }

    Colchon* generarColchon(string pName, int pPeso, int pAlto, int pAncho, int pLargo) 
    {
        Colchon *nuevoColchon = new Colchon(pName, pPeso, pAlto, pAncho, pLargo);
        return nuevoColchon;
    }

//Este método está bien, se aplicaría sacarColchones a tarimas y lo que se saque se deja en una pila de camión
    metodos sacarColchones(int pCantidad)  //metodos<Colchon *> sacarColchones(int pCantidad){
    {
        metodos colchonesSacados;  // metodos<Colchon *> colchonesSacados;  // Crear una lista para almacenar los colchones sacados
    
        // Supongamos que deseas sacar colchones de la primera tarima
        if (!tarimas.estaVacio()) {
            void* tarimaPtr1 = tarimas.pop();    //ColchonStack tarima = tarimas.pop();  // Obtener la primera tarima de la lista
            Stack* tarimaPtr = static_cast<Stack*>(tarimaPtr1);
            Stack tarima = *tarimaPtr;
    
            // Sacar pCantidad de colchones de la tarima
            for (int i = 0; i < pCantidad; i++) {
                Colchon* colchonPtr = static_cast<Colchon*>(tarima.pop());  // Sacar un colchon de la tarima
                Colchon colchon = *colchonPtr;
                colchonesSacados.addToEnd(&colchon);  // Agregar el colchon a la lista de colchones sacados
                if (tarimaPtr == nullptr) {
                    break;
                }
            }
    
            // Si quedan colchones en la tarima, devolverla a la lista de tarimas
            if (!tarima.estaVacio()) {
                void* tarimaV = static_cast<void*>(&tarima);
                tarimas.push(tarimaV);
            }
        }
    
        return colchonesSacados;  // Devolver la lista de colchones sacados
    }

    //Este método retorna la pila "tarimas", por lo que si es modificada desde otra clase,
    //dicha pila será modificada de igual manera, cuando se trabaja con este método hay
    //que tener cuidado, esto debido a que la información que se extraiga debería ser agregada
    //nuevamente, para no estar perdiendo información a lo largo del programa.

    Stack &getTarimas() {  //Stack<ColchonStack *> &getTarimas()
        return tarimas;
    }

    //Este método a diferencia del anterior, genera un copia, por lo que puedo
    //acceder a los datos de este sin necesidad de tener que volverlos a meter
    Stack getTarimasCopy() const {  //Stack<ColchonStack *> getTarimasCopy() const
        return tarimas; // Devuelve una copia de la pila "tarimas"
    }

    void agregarTarima(Stack tarima)
    {
        void* tarimaV = static_cast<void*>(&tarima);
        tarimas.push(tarimaV);
    }

    // Método para sacar una tarima de la pila "tarimas"
    Stack* sacarTarima()
    {
        Stack* ptrStack = static_cast<Stack*>(tarimas.pop());
        return ptrStack;
    }

    int sizeOfTarima()
    {
        return tarimas.largoPila();
    }

    void hacerPop()
    {
        tarimas.pop();
    }

    void prueba()
    {
        /*
        std::cout << "!2#$%&/()=?¡134567890" << std::endl;
        Stack* prueba = static_cast<Stack*>(tarimas.pop());
        std::cout << "..." << std::endl;
        Stack pila = *prueba;
        std::cout << pila.largoPila() << std::endl;
        std::cout << "..." << std::endl;
        Colchon* colchonPtr4 = static_cast<Colchon*>(pila.pop());
        std::cout << "..." << std::endl;
        Colchon jsjs = *colchonPtr4;
        std::cout << "..." << std::endl;
        int k = jsjs.getPeso();
        std::cout << k << std::endl;
        string ar = colchonPtr4->getName();
        std::cout << ar << std::endl;
        std::cout << "..." << std::endl;
        std::cout << "Cantidad de elementos de tarimas" << std::endl;
        std::cout << tarimas.largoPila() << std::endl;
        std::cout << "Cantidad de elementos de tarimas" << std::endl;
        std::cout << "!2#$%&/()=?¡134567890" << std::endl;
        */
    }
};

#endif