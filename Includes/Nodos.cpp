#include "Nodos.h"


template <class T>
Nodo<T>::Nodo(){ next = NULL; }

template <class T>
Nodo<T>::Nodo(T a){ dato = a; next = NULL;}

template <class T>
Nodo<T>::~Nodo(){}

template <class T>
void Nodo<T>::setNext(Nodo<T>* n){ next = n; }

template <class T>
void Nodo<T>::setDato(T a){ dato = a; }

template <class T>
T Nodo<T>::getDato(){ return dato; }

template <class T>
Nodo<T>* Nodo<T>::getNext(){ return next; }

template <class T>
bool    Nodo<T>::nodoIsEmpty(){ return next == NULL; }

template class Nodo<int>;
template class Nodo<float>;
template class Nodo<double>;
template class Nodo<char>;
template class Nodo<string>;