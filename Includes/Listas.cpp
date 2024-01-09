
//#include "Nodos.hpp"
#include "Listas.h"



template <class T>
Lista<T>::Lista(){ czo = new Nodo<T>();}

template <class T>
Lista<T>::~Lista(){}

template <class T>
void Lista<T>::add(T a){
    Nodo<T>* nuevo = new Nodo<T>(a);
    nuevo->setNext(czo);
    czo = nuevo;
}

template <class T>
int Lista<T>::size(){ return pSize(czo); }

template <class T>
int Lista<T>::pSize(Nodo<T>* inicio){
    if(inicio->getNext() != NULL){
        return 1+pSize(inicio->getNext());
    }
}

template class Lista<int>;
template class Lista<float>;