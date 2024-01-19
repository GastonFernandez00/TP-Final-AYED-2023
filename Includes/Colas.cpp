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

template <class T>
void Cola<T>::setIDCola(int i){ id_Cola = i; }

template <class T>
void Cola<T>::cambiarEstado(){ if(estado == false){ estado = true; } else{ estado = false; }}

template <class T>
void Cola<T>::setIDDestino(int destino){
    id_Destino = destino;
}

template <class T>
void Cola<T>::setIDDestino(){
    id_Destino = rand()%256;
}

template <class T>
int Cola<T>::getIDDestino(){ return id_Destino; }

template <class T>
int Cola<T>::getIDCola(){ return id_Cola; }

template <class T>
void Cola<T>::setidDestinoTerminal(int d){ id_Destino_Terminal = d; }

template <class T>
void Cola<T>::setidDestinoTerminal(){ id_Destino_Terminal = rand()%256; }

template <class T>
int Cola<T>::getIDDestinoTerminal(){ return id_Destino_Terminal; }


template class Cola<int>;
template class Cola<Cola<int>*>;
template class Cola<float>;
template class Cola<double>;
template class Cola<char>;
template class Cola<string>;

