#ifndef ROUTER_H
#define ROUTER_H
#include "Terminal.h"

class Router{
private:
    int id_Router = -1;
    int posicion = -1;

    Cola<Cola<int>*> buffer;
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

    void Recepcion(Cola<int>*);







};
#endif