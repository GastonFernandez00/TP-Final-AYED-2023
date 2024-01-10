#ifndef COLAS_H
#define COLAS_H
#include <iomanip>
#include <stdio.h>
#include <iostream>
#include "Listas.h"
using namespace std;

template <class T>
class Cola /*: public Lista<T>*/{
private:
    Lista<T>* c;
public:
    Cola();
    ~Cola();
    void encolar(T);
    void descolar();
    bool colaEmpty();
    T    topeDeCola();
    T   ultimoDeCola();
    string imprimirCola(string);
    void printCola();
    int sizeCola();
    
};
#endif