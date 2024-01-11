#ifndef LISTAS_HPP
#define LISTAS_HPP

#include "Nodos.h"

#include <iomanip>
#include <stdio.h>
#include <iostream>
using namespace std;

//  Clase Lista
//  @param  T
template <class T>
class  Lista{
private:
    Nodo<T>* czo;           //Puntero a un primer Nodo
    
    /*  Funcion auxiliar que calcula el tamanio de la lista
        @param Nodo<T>*
        @returns int
    */
    int pSize(Nodo<T>*);    

    /*  Funcion auxiliar que imprime la Lista
        @param Nodo<T>*
    */
    void imprimirLista(Nodo<T>*);

    /*  Funcion auxiliar que pregunta si un Dato dado se encuentra en la lista
        @param T, Nodo<T>*
        @returns Boolean
    */
    bool checkDato(T,Nodo<T>*);

    /*  Funcion auxiliar que borra el nodo que contiene un dato especifico
        @param T, Nodo<T>*, Nodo<T>* 
    */
    void borrarDatop(T, Nodo<T>*,Nodo<T>*);
    
    /*  Funcion auxiliar que borra el nodo mas antiguo de la lista
        @param Nodo<T>*, Nodo<T>* 
    */
    void borrarLastp(Nodo<T>*,Nodo<T>*);

    /*  Funcion auxiliar que devuelve el Dato del nodo mas antiguo
        @param Nodo<T>*, Nodo<T>* 
        @returns T
    */
    T lastp(Nodo<T>*, Nodo<T>*);

public:
    //Constructor de la Clase
    Lista();

    //Constructor de la Clase con un nodo predefinido
    Lista(Nodo<T>*);

    //Destructor de la Clase
    ~Lista();

    /*  Aniade un nuevo dato a la lista
        @param T
    */
    void add(T);
    
    /*  Devuelve el tamanio de la Lista
        @returns int
    */
    int  size();

    /*  Devuelve el Dato del Nodo mas reciente
        @returns T
    */
    T cabeza(); 
    
    /*  Pregunta si la Lista esta vacia
        @returns Boolean
    */
    bool isEmpty();

    Lista<T>* resto();

    /*  Imprime la Lista Completa*/
    void printLista();

    /*  Imprime la Lista Completa
        @param string
        @returns string
    */
    string toPrint(string);

    /*  Pregunta si un Dato especifico se encuentra en la lista
        @param T
        @returns Boolean
    */
    bool esta(T);
    
    /*  Borra un Dato en especifico de la Lista
        @param T
    */
    void borrarDato(T);
    
    /*  Borra el Dato mas reciente de la Lista*/
    void borrarCabeza();

    //  Borra el dato mas antiguo de la Lista
    void borrarLast();

    void concat(Lista<T>*);
    
    /*  Copia la Lista
        @returns Lista<T>*
    */    
    Lista<T>* copy();
    
    /*  Permite sobrevivir los 'n' primeros Datos de la Lista
        @param int
    */
    void tomar(int);

    /*  Devuelve el ultimo Dato de la Lista, sin eliminarlo de ella
        @returns T
    */
    T last();
};
#endif