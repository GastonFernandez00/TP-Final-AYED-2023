#ifndef ROUTER_H
#define ROUTER_H
#include "Terminal.h"

class Router{
private:
    int id_Router = -1;
    int posicion = -1;

    Cola<Cola<int>*>* buffer = new Cola<Cola<int>*>();
    Cola<Cola<int>*>* buffer_Redireccion = new Cola<Cola<int>*>();
    void checkIDRouterPriv(Router *, Router *);
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

    /*  Establece el Valor de ID del router
        @param Router*
    */
   void setIDRouter();

    /*   Establece la Posicion del Router
        @param Router*
    */
   void setRouterPosicion();

   /*  Establece el Valor de ID del router con Parametros
        @param Router* , int
    */
   void setIDRouter(int);

    /*   Establece la Posicion del Router con Parametros
        @param Router* , int
    */
   void setRouterPosicion(int);

    /*  Devuelve el ID del router actual 
        @returns int
    */
    int getIDRouter();

    /*  Devuelve la posicion pseudo-fisica del router actual
        @returns int
    */
    int getPosicionRouter();

    /*  Prepara para recibir en el router el archivo que se esta enviando desde
        el terminal Emisor.
        Si el router es al que debe ir el archivo, se encola en un buffer, a espera
        para ser reenviado al terminal de destino
        Si NO es el router al que debe ir, se encola en otro buffer, a espera para reenviarse a otro
        router vecino.        
        @param Cola<int>*
    */
    void Recepcion(Cola<int>*);

    /*  Pregunta si la cola del router tiene algun elemento*/
    bool routerEmpty();

    /*  Pregunta si la cola de redireccion tiene algun elemento*/
    bool routerRedireccionEmpty();

    /*  Checkea que los routers sea unicos, y no haya repetidos
        @param Router*
    */
    void checkIDRouter();

    /*
    */
    void cambiarRouterID(Router*,Router*);





};
#endif