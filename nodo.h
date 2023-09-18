#ifndef _NODOGENERICO_
#define _NODOGENERICO_ 1

struct pilaTarimaSalida {
    void* data = nullptr;  
    struct pilaTarimaSalida* next = nullptr;
    struct pilaTarimaSalida* previous = nullptr; 
};

struct colaCarga {
    void* data = nullptr;  
    struct colaCarga* next = nullptr;
    struct colaCarga* previous = nullptr; 
};

struct pilaCamion {
    void* data = nullptr;  
    struct pilaCamion* next = nullptr;
    struct pilaCamion* previous = nullptr; 
};

struct colaDescarga {
    void* data = nullptr;  
    struct colaDescarga* next = nullptr;
    struct colaDescarga* previous = nullptr; 
};

struct pilaTarimaLlegada {
    void* data = nullptr;  
    struct pilaTarimaLlegada* next = nullptr;
    struct pilaTarimaLlegada* previous = nullptr; 
};
#endif