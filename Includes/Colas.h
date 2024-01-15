#ifndef COLAS_H
#define COLAS_H
#include <iomanip>
#include <stdio.h>
#include <iostream>
#include "Listas.h"
using namespace std;


/*  Clase Cola
*   @param T
*/
template <class T>
class Cola /*: public Lista<T> POSIBLE HERENCIA*/{
private:
    int id_Cola = -1;
    int id_Destino = -1;
    bool estado = false;
    Lista<T>* c;

public:
    //  Constructor de Clase: Genera una nueva cola tipo FIFO
    Cola();

    //  Destructor del Objeto
    ~Cola();

    //  Encolar: Introduce un nuevo dato a la cola
    //  @param   T
    void encolar(T);
    
    //  Elimina el dato mas antiguo de la cola
    void descolar();

    //  Pregunta si la Cola esta vacia
    //  @returns Boolean
    bool colaEmpty();

    //  Devuelve el dato mas antiguo de la cola, pero no lo elimina.
    //  @returns T
    T    topeDeCola();

    //  Devuelve el dato mas reciente de la cola, pero no lo elimina
    //  @returns T
    T   ultimoDeCola();

    //  Imprime la cola 
    //  @param  string
    //  @returns string
    string imprimirCola(string);

    //  Imprime la cola, no recibe parametros
    void printCola();

    //  Devuelve el tamaño de la Cola
    //  @returns int
    int sizeCola();

    /*Establece el id de la cola
        @param int
    */
    void setIDCola(int);

    /*  Establede el ID de destino de la cola
        @param int
    */
   void setIDDestino(int);

    /*Cambia el estado de la cola, segun este lista para enviarse o no*/
    void cambiarEstado();

    /*  Devuelve el Id de del router a donde debe ir la cola
        @returns int
    */
    int getIDDestino();

    /*  Devuelve el Id de la cola
        @returns int
    */
    int getIDCola();
    
};
#endif