#ifndef COLA_H
#define COLA_H
#include <iostream>
#include <queue>
#include <random>
#include "Paquete.h"
using namespace std;

/*  Clase Cola
    @param T*/
template <class T>
class Cola{
private:
    std::queue<T> c;
    int id_Cola = -1;
    bool estado = false;

public:

    //  Constructor de Clase: Genera una nueva cola tipo FIFO
    Cola();

    //  Destructor del Objeto    
    ~Cola();

    /*Establece el id de la cola
        @param int
    */
    void setIDCola();

    /*Establece el id de la cola
        @param int
    */
    void setIDCola(int);

    /*Cambia el estado de la cola, segun este lista para enviarse o no*/
    void cambiarEstado();
    
    //  Encolar: Introduce un nuevo dato a la cola
    //  @param   T
    void encolar(T);

    //  Elimina el dato mas antiguo de la cola
    void desencolar();

    /*  Vacia la cola  */
    void vaciarCola();

    //  Imprime la cola, no recibe parametros
    void imprimirCola();

    //  Devuelve la Cola
    queue<T> getCola();

    //  Devuelve el dato mas antiguo de la cola, pero no lo elimina.
    //  @returns T
    T& getPrimero();

    //  Devuelve el dato mas reciente de la cola, pero no lo elimina
    //  @returns T
    T getUltimo();

    /*  Devuelve el Id de la cola
        @returns int
    */
    int getIDCola();

    //  Pregunta si la Cola esta vacia
    //  @returns Boolean
    bool colaEmpty();

    //  Devuelve el tamaño de la Cola
    //  @returns int
    int sizeCola();

    /*  Devuelve el estado de la cola, si esta listo para enviarse o no*/
    bool getEstado();

};
#endif