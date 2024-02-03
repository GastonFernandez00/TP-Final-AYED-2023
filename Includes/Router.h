#ifndef ROUTER_H
#define ROUTER_H
#include "Terminal.h"
#define tamanio_Posicion 50

class Router{
private:
    int id_Router = -1;
    int posicion[tamanio_Posicion][tamanio_Posicion];

    int MaximaCantDeRouters = 256;
    //Terminal receptores[256];
    int cantidadDeReceptores = 256;
    vector<Terminal> receptores;


    Cola<Paquete> buffer;
    Cola<Paquete> buffer_Redireccion;
    void checkIDRouterPriv(vector<Router> &, int, int);
    Terminal crearNuevoReceptor();
public:
    
    /*  Constructor de Clase, asocia una posicion e ID random*/
    Router();

    /*  Constructor de Clase, asocia una posicion random y un ID por parametro
        @param int
    */
    Router(int);

    /*  Constructor de Clase, asocia una posicion e ID por parametro
        @param int, int, int
    */
    Router(int,int,int);

    /*Destructor de Clase*/
    ~Router();

    /*  Establece el Valor de ID del router
        @param
    */
   void setIDRouter();

    /*   Establece la Posicion del Router
        @param
    */
   void setRouterPosicion();

   /*  Establece el Valor de ID del router con Parametros
        @param int
    */
   void setIDRouter(int);

    /*   Establece la Posicion del Router con Parametros
        @param int, int
    */
   void setRouterPosicion(int,int);

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
    void Recepcion(Cola<Paquete> );

    /*  Pregunta si la cola del router tiene algun elemento*/
    bool routerEmpty();

    /*  Pregunta si la cola de redireccion tiene algun elemento*/
    bool routerRedireccionEmpty();

    /*  Checkea que los routers sea unicos, y no haya repetidos
    */
    void checkIDRouter(vector<Router> &);

    /*  Establece las terminales receptoras asociadas a este router */
    void setReceptores();

    /*  Devuelve un vector de los receptores del Router asociado*/
    vector<Terminal> getReceptor();

    void setMaximaCantDeRouters(int);

    Cola<Paquete> getBufferRouter();

    Cola<Paquete> getBufferRedireccionRouter();   

};
#endif