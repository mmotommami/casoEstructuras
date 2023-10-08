#include <string>
#include "Colchon.h"
#include "Stack.h"
#include "Configloader.cpp"
#include <vector>
#include "lista.h"

using namespace std;

class TarimaGroup
{
private:
    int cantidadColchones;
    string tipoColchon;
    typedef Stack<Colchon *> ColchonStack; // Alias para Stack<Colchon *>

    Stack<ColchonStack *> tarimas; // Almacena Stacks que guardan Colchones
    Configloader configuracion;

//tarimas es una pila que guarda pilas de colchones

public:
    TarimaGroup()
    {
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
    }

    void rellenar() {
        ConfigBodega infoBodega = configuracion.getConfigBodega();
        ConfigColchones infoColchones = configuracion.getConfigColchones();
        vector<int> sizes;
        int cantidadTarimasFull = infoBodega.fullquantity;
        sizes.push_back(cantidadTarimasFull);
        int cantidadTarimasQueen = infoBodega.queenquantity;
        sizes.push_back(cantidadTarimasQueen);
        int cantidadTarimasTwin = infoBodega.twinquantity;
        sizes.push_back(cantidadTarimasTwin);
        int cantidadTarimasKing = infoBodega.kingquantity;
        sizes.push_back(cantidadTarimasKing);

//sizes = [30, 20, 10, 15]

//name = [King, Queen, Full, Twin]

//tarimas = [[{King}, {King}, {King}], [{Queen}, {Queen}, {Queen}]]
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

// tarimas = [[{objetoColchon<Tipo Específico(King, Queen, etc)>}, {objetoColchon<Tipo Específico(King, Queen, etc)>}], [{objetoColchon<Tipo Específico(King, Queen, etc)>}], [{objetoColchon<Tipo Específico(King, Queen, etc)>}]]
// Al acceder a "tarimas", se accede inicialmente a un Stack que guarda objetos de tipo "Colchon", si se accede a dicho
// objeto, se puede usar el nombre del objeto como la key name para obtener cual tipo de colchón es, si el colchón es el
// correcto, se puede verificar si la cantidad es la correcta

    Stack<Colchon *> llenarInventario(string pName, int pPeso, int pAlto, int pAncho, int pLargo)
    {
        Stack<Colchon *> tarimas2; //Esta definicion es incorrecta, ya que el Stack<Colchon *> es la manera de definir
                                   //un vector, para crear un Stack que guarde objetos tipo Colchon nada más se define
                                   //un Stack y se hace push a objetos tipo Colchon, ya que el Stack recibe tipo void
                                   //por lo que se puede insertar cualquier tipo de dato
        ConfigBodega infoBodega = configuracion.getConfigBodega();
        int maxColchonesPorTarima = infoBodega.tarimasize;
            for(int i=0; i < maxColchonesPorTarima; i++)
            {
                Colchon colchon = new Colchon(pName, pPeso, pAlto, pAncho, pLargo);
                tarimas2.push(colchon);
            }
            // inicializar la lista de tarimas y puedo meter los colchones
        return tarimas2;
    }

//Este método está bien, se aplicaría sacarColchones a tarimas y lo que se saque se deja en una pila de camión
    metodos<Colchon *> sacarColchones(int pCantidad){
        metodos<Colchon *> colchonesSacados;  // Crear una lista para almacenar los colchones sacados
    
        // Supongamos que deseas sacar colchones de la primera tarima
        if (!tarimas.isEmpty()) {
            ColchonStack tarima = tarimas.pop();  // Obtener la primera tarima de la lista
    
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
            if (!tarima.estaVacio()) {
                tarimas.push(tarima);
            }
        }
    
        return colchonesSacados;  // Devolver la lista de colchones sacados
    }

    //Este método retorna la pila "tarimas", por lo que si es modificada desde otra clase,
    //dicha pila será modificada de igual manera, cuando se trabaja con este método hay
    //que tener cuidado, esto debido a que la información que se extraiga debería ser agregada
    //nuevamente, para no estar perdiendo información a lo largo del programa.
    Stack<ColchonStack *> &getTarimas() {
        return tarimas;
    }

    //Este método a diferencia del anterior, genera un copia, por lo que puedo
    //acceder a los datos de este sin necesidad de tener que volverlos a meter
    Stack<ColchonStack *> getTarimasCopy() const {
        return tarimas; // Devuelve una copia de la pila "tarimas"
    }

}