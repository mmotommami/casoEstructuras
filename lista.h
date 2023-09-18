#ifndef _LISTAGENERICA_
#define _LISTAGENERICA_ 1

#include "nodo.h"
#include <stdlib.h>

struct pilaTarimaSalida {
    struct pilaTarimaSalida* start = nullptr;
    struct pilaTarimaSalida* end = nullptr;
    int size =0;


    bool isEmpty() {
//        return size == 0;
    }

    int getSize() {
//        return size;
    }

    void agregarFinal(void* pData) {
//        size++;
    }

    void agregarInicio(void* pData) {
//        size++;
    }

    void* removerInicio() {
//        return result;
    }   
};

struct colaCarga {
    struct colaCarga* start = nullptr;
    struct colaCarga* end = nullptr;
    int size =0;


    bool isEmpty() {
//        return size == 0;
    }

    int getSize() {
//        return size;
    }

    void agregarFinal(void* pData) {
//        size++;
    }

    void agregarInicio(void* pData) {
//        size++;
    }

    void* removerInicio() {
//        return result;
    }   
};

struct pilaCamion {
    struct pilaCamion* start = nullptr;
    struct pilaCamion* end = nullptr;
    int size =0;


    bool isEmpty() {
//        return size == 0;
    }

    int getSize() {
//        return size;
    }

    void agregarFinal(void* pData) {
//        size++;
    }

    void agregarInicio(void* pData) {
//        size++;
    }

    void* removerInicio() {
//        return result;
    }   
};

struct colaDescarga {
    struct colaDescarga* start = nullptr;
    struct colaDescarga* end = nullptr;
    int size =0;


    bool isEmpty() {
//        return size == 0;
    }

    int getSize() {
//        return size;
    }

    void agregarFinal(void* pData) {
//        size++;
    }

    void agregarInicio(void* pData) {
//        size++;
    }

    void* removerInicio() {
//        return result;
    }   
};

struct pilaTarimaLlegada {
    struct pilaTarimaLlegada* start = nullptr;
    struct pilaTarimaLlegada* end = nullptr;
    int size =0;


    bool isEmpty() {
//        return size == 0;
    }

    int getSize() {
//        return size;
    }

    void agregarFinal(void* pData) {
//        size++;
    }

    void agregarInicio(void* pData) {
//        size++;
    }

    void* removerInicio() {
//        return result;
    }   
};
#endif