#ifndef NODOS_HPP
#define NODOS_HPP

#include <iomanip>
#include <stdio.h>
#include <iostream>

using namespace std;
template <class T>
class Nodo{
private:
    T dato;
    Nodo<T>* next;
public:
    Nodo();
    Nodo(T);
    ~Nodo();

    void setDato(T);
    void setNext(Nodo<T>*);

    T        getDato();
    Nodo<T>* getNext();
}; 
#endif