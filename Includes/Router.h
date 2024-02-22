#ifndef ROUTER_H
#define ROUTER_H
#include "Terminal.h"
#define tamanio_Posicion 50

class Router{
private:
    int id_Router = -1;
    int posicion_x = -1 , posicion_y = -1;
    vector<Router*> cercanos;   //Routers cercanos a este mismo

    int MaximaCantDeRouters = 256;

    int cantidadDeReceptores = 256;
    vector<Terminal> receptores;    //Terminales asociados a este router

    vector<queue<Paquete>> Preparado; //Preparado de paquetes para enviar a los terminales

    int bandWidth = 1;


    queue<Paquete> buffer;      //Paquetes que corresponden a este router
    queue<Paquete> buffer_Redireccion; //Paquetes que no corresponden a este router
    
    /*  Establece las terminales receptoras asociadas a este router */
    void setReceptores();

    //Revisa que los IDs de los routers no se repitan
    void checkIDRouterPriv(vector<Router> &, int, int);
    
    Terminal crearNuevoReceptor();
public:
    
    /*  Constructor de Clase, asocia una posicion e ID random*/
    Router();

    /*  Constructor de Clase, asocia una posicion random y un ID por parametro
        @param int
    */
    Router(int);

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
    void printPosicionRouter();

    /*  Prepara para recibir en el router el archivo que se esta enviando desde
        el terminal Emisor.
        Si el router es al que debe ir el archivo, se encola en un buffer, a espera
        para ser reenviado al terminal de destino
        Si NO es el router al que debe ir, se encola en otro buffer, a espera para reenviarse a otro
        router vecino.        
        @param Cola<int>*
    */
    void Recepcion(queue<Paquete>&);

    /*  Recibe un único paquete que se le este enviando, esta pensado
        para la comunicacion entre routers 
        @param Paquete& */
    void Recepcion(Paquete&);

    /*  Pregunta si la cola del router tiene algun elemento
        @returns bool   */
    bool routerEmpty();

    /*  Pregunta si la cola de redireccion tiene algun elemento
        @returns bool   */
    bool routerRedireccionEmpty();

    /*  Checkea que los routers sea unicos, y no haya repetidos
        @param vector<Router>&  */
    void checkIDRouter(vector<Router> &);

    /*  Devuelve un vector de los receptores del Router asociado
        @returns vector<Terminal>&  */
    vector<Terminal>& getReceptor();

    /*  Establece la maxima cantidad de routers
        @param int  */
    void setMaximaCantDeRouters(int);

    /*  Devuelve la cola de paquetes que tiene este router, y que corresponden a si mismo
        @returns queue<Paquete>&    */
    queue<Paquete>& getBufferRouter();

    /*  Devuelve el tamanio del buffer
        @returns int    */
    int getSizeBuffer();

    /*  Devuelve la cola de paquetes que tiene este router, y que deben ser
        redireccionados
        @returns queue<Paquete>&    */
    queue<Paquete>& getBufferRedireccionRouter();   

    /*  Devuelve el tamanio del buffer de redireccionamiento
        @returns int    */
    int getSizeBufferRedireccionamiento();

    /*  Establece la posicion en X del Router en el mapa 
        @param int  */
    void setRouter_x(int);

    /*  Establece la posicion en Y del Router en el mapa 
        @param int  */    
    void setRouter_y(int);

    /*  Devuelve la posicion en X del Router en el mapa 
        @returns int  */ 
    int getRouter_x();

    /*  Devuelve la posicion en Y del Router en el mapa 
        @returns int  */
    int getRouter_y();

    /*  Incluye en el vector de 'Cercanos', los routers proximos a este
        @param Router*  	*/
    void incluirCercanos(Router*);

    /*  Elimina la lista de Routers Cercanos (Esta implementada en el codigo, pero no se usa)*/
    void borrarCercanos();

    /*  Devuelve el vector de 'Cercanos', con punteros a los routers que esten cerca
        @returns vector<Router*>&   */
    vector<Router*>& getCercanos();

    /*  Establece la BandWidth, de forma aleatoria, que se usa para el envio de paquetes entre routers*/
    void setBandWidth();

    /*  Devuelve cual es la BandWidth de este Router
        @returns int    */
    int getBandWidth();

    /*  Devuelve los Paquetes que estan preparados para ser enviados a los terminales
        @returns vector<queue<Paquete>>&    */
    vector<queue<Paquete>>& getPaquetesPreparados();

    /*  Devuelve un terminal en concreto, que este asociado a este router. En base al ID del terminal
        @param int
        @returns Terminal&  */
    Terminal& getTerminalEspecifico(int);
};
#endif