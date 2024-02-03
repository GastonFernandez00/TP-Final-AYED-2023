#ifndef TERMINAL_H
#define TERMINAL_H
#include "Paginas.h"
#include "Cola.h"
#include "Paquete.h"
class Terminal{
private:

    Cola<Paquete> pkg;
    int id_TERMINAL = -1;

    /*  Si: Determinante == 0 -> Emisor
        Si: Determinante == 1 -> Receptor
    */
    bool determinante = 0;
    int MaximaCantDeTerminales = 256;
    void setMaximaCantDeTerminales(int);
    void checkIDTerminalPriv(vector<Terminal> &,int,int/*,int,int*/);
public:
    

    /*  Constructor de la clase terminal, define si una 
        pc es emisor o receptor de forma aleatoria
    */
    Terminal();

    /*  Constructor de la clase terminal, define si una 
        pc es emisor o receptor por parametro
        @param bool
    */
    Terminal(bool);
    
    /*Destructor de Clase*/
    ~Terminal();

    /*  Establece el Determinante
        Si: Determinante == 0 -> Emisor
        Si: Determinante == 1 -> Receptor
    */
    void setDeterminante(bool);

    /*  Devuelve del Determinante
        @returns bool
    */
    bool getDeterminante();

    /*  Devuelve el ID del Terminal 
        @returns int
    */
    int getIDTerminal();

    /*  Si la pc es un emisor, aniade un ID a la cola (que es el mismo id de la pagina) 
        y separa la pagina en nodos de tamanio 50
        @param Pagina *, Cola<int>*
    */
    void empaquetado(Pagina *);

    /*  Establece que X cola esta lista para ser enviada (levanta un flag) y 
        asocia un id de router y terminal a donde debe ser enviado
        @param Cola<int>*, int
    */
    Cola<Paquete> envio();

    /*  Establece el ID del Terminal */
    void setIDTerminal();

    /*  Establece el ID del Terminal con parametro */
    void setIDTerminal(int);

    /*  Checkea que los terminales sea unicos, y no haya repetidos
    */
    void checkIDTerminal(vector<Terminal> &);

    /*  Devuelve los paquetes almacenados en la terminal*/
    Cola<Paquete> getPaquetes();


};
#endif