#ifndef TERMINAL_H
#define TERMINAL_H
#include <queue>
#include <random>
#include "Paginas.h"
#include "Paquete.h"
class Terminal{
private:

    queue<Paquete> pkg;     //Paquetes que se van a reenviar
    vector<queue<Paquete>> recibidos; //Paquetes recibidos desde el router
    vector<Pagina> paginasDisponibles; //Paginas ya rearmadas
    int id_TERMINAL = -1;



    /*  Si: Determinante == 0 -> Emisor
        Si: Determinante == 1 -> Receptor
    */
    bool determinante = 0;
    int MaximaCantDeTerminales = 256;
    void setMaximaCantDeTerminales(int);

    //Revisa que los IDs de los terminales no se repitan
    void checkIDTerminalPriv(vector<Terminal> &,int,int/*,int,int*/);
public:
    

    /*  Constructor de la clase terminal, define el
        ID del terminal */
    Terminal();

    /*  Constructor de la clase terminal, define si una 
        pc es emisor o receptor por parametro
        @param bool */
    Terminal(bool);
    
    /*Destructor de Clase*/
    ~Terminal();

    /*  Establece el Determinante
        Si: Determinante == 0 -> Emisor
        Si: Determinante == 1 -> Receptor   */
    void setDeterminante(bool);

    /*  Devuelve del Determinante
        @returns bool    */
    bool getDeterminante();

    /*  Devuelve el ID del Terminal 
        @returns int    */
    int getIDTerminal();

    /*  Si la pc es un emisor, aniade un ID a la cola (que es el mismo id de la pagina) 
        y separa la pagina en nodos de tamanio 50
        @param Pagina *, Cola<int>*    */
    void empaquetado(Pagina &);

    /*  Establece el ID del Terminal */
    void setIDTerminal();

    /*  Establece el ID del Terminal con parametro */
    void setIDTerminal(int);

    /*  Checkea que los terminales sea unicos, y no haya repetidos    */
    void checkIDTerminal(vector<Terminal> &);

    /*  Devuelve los paquetes almacenados en la terminal*/
    queue<Paquete>& getPaquetes();

    /*  Recibe desde el router todos los paquetes que formen un pagina completa
        y los almacena dentro del terminal
        @param queue<Paquete>   */
    void recibePaquetes(queue<Paquete>);

    /*  Devuelve un vector que contiene listas de paquetes. Estas colas de paquetes
        ya estan organizadas segun a que pagina pertenecia cada paquete
        @returns vector<queue<Paquete>>&    */
    vector<queue<Paquete>>& getPaquetesRecibidos();

    /*  Toma la cola de paquetes que se le pase y la convierte en una pagina, 
        pasandoles toda la informacion que contengan los paquetes y almacenandola
        dentro del terminal
        @param queue<Paquete>&  */
    void rearmarPaginas(queue<Paquete>&);

    /*  Imprime todas las paginas que contega un terminal (Su tamanio e ID)  */
    void getPaginasDisponibles();

};
#endif