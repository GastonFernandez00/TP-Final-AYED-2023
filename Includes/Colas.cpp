#include "Colas.h"

template <class T>
Cola<T>::Cola(){ c = new Lista<T>(); }

template <class T>
Cola<T>::~Cola(){ }

template <class T>
void Cola<T>::encolar(T a){ c->add(a); }

template <class T>
void Cola<T>::descolar(){ c->borrarLast(); }

template <class T>
bool Cola<T>::colaEmpty(){ return c->isEmpty(); }

template <class T>
T Cola<T>::topeDeCola(){ return c->last(); }

template <class T>
T Cola<T>::ultimoDeCola(){ return c->cabeza(); }

template <class T>
string Cola<T>::imprimirCola(string p){ return c->toPrint(p);}

template <class T>
void Cola<T>::printCola(){ c->printLista(); }

template <class T>
int Cola<T>::sizeCola(){ return c->size(); }

template class Cola<int>;
template class Cola<float>;
template class Cola<double>;
template class Cola<char>;
template class Cola<string>;