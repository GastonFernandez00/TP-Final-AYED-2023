#ifndef NODOS_HPP
#define NODOS_HPP

#include <iomanip>
#include <stdio.h>
#include <iostream>

using namespace std;

//  Clase Nodo
//  @param  T, int, float, double, string, char
template <class T>
class Nodo{
private:
    T dato; //Tipo de dato a almacenar
    Nodo<T>* next;  //Nodo siguiente
public:
    
    /*Constructor de la Clase. Establece el puntero 
    del siguiente nodo como NULL
    */
    Nodo();
    
    /*Constructor de la Clase. Establece el puntero 
    del siguiente nodo como NULL, Y ademas introduce un primer dato, tipo T
    @param T
    */
    Nodo(T);

    //Destructor de la Clase
    ~Nodo();

    //Establece el Dato del Nodo Actual
    //@param T
    void setDato(T);

    //Establece el siguiente Nodo
    //@param Nodo<T>*
    void setNext(Nodo<T>*);

    //Devuelve el Dato almacenado en el Nodo Actual
    //@returns T
    T        getDato();

    //Devuelve el siguiente Nodo
    //@returns Nodo<T>*
    Nodo<T>* getNext();

    //Pregunta si el nodo esta vacio
    //@returns Boolean
    bool    nodoIsEmpty();
}; 
#endif