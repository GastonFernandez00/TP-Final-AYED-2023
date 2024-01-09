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
public:
    Lista();
    ~Lista();

    void add(T);
    int  size(); 
};
#endif