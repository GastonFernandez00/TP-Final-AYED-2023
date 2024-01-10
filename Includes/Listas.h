#ifndef LISTAS_HPP
#define LISTAS_HPP

#include "Nodos.h"

#include <iomanip>
#include <stdio.h>
#include <iostream>
using namespace std;

template <class T>
class  Lista{
private:
    Nodo<T>* czo;
    int pSize(Nodo<T>*);
    void imprimirLista(Nodo<T>*);
    bool checkDato(T,Nodo<T>*);
    void borrarDatop(T, Nodo<T>*,Nodo<T>*);
public:
    Lista();
    Lista(Nodo<T>*);
    ~Lista();

    void add(T);
    int  size();
    T cabeza(); 
    bool isEmpty();
    Lista<T>* resto();
    void printLista();
    string toPrint(string);
    bool esta(T);
    void borrarDato(T);
    

};
#endif