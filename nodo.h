#ifndef _NODOGENERICO_
#define _NODOGENERICO_ 1

struct nodo
{
    void *data = nullptr;
    struct nodo *next = nullptr;
    struct nodo *previous = nullptr;
};

#endif