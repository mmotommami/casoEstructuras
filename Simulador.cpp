#include "Bodega.cpp"
#include "Configloader.cpp"

using namespace std;

class Simulador
{
private:
    Configloader configloader;
    Bodega *labogeda;

public:
    Simulador()
    {
        initSimulation();
    }

    void initSimulation()
    {

        labogeda = new Bodega(configloader.getConfiguracionDeBodega());
    }
}