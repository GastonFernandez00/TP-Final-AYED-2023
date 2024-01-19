#ifndef ROUTER_H
#define ROUTER_H
#include "Terminal.h"

class Router{
private:
    int id_Router = -1;
    int posicion = -1;

    Cola<Cola<int>*>* buffer = new Cola<Cola<int>*>();
    Cola<Cola<int>*>* buffer_Redireccion = new Cola<Cola<int>*>();
public:
    
    /*  Constructor de Clase, asocia una posicion e ID random*/
    Router();

    /*  Constructor de Clase, asocia una posicion random y un ID por parametro
        @param int
    */
    Router(int);

    /*  Constructor de Clase, asocia una posicion e ID por parametro
        @param int int
    */
    Router(int,int);

    /*Destructor de Clase*/
    ~Router();

    /*  Devuelve el ID del router actual 
        @returns int
    */
    int getIDRouter();

    /*  Devuelve la posicion pseudo-fisica del router actual
        @returns int
    */
    int getPosicionRouter();

    void Recepcion(Cola<int>*);







};
#endif