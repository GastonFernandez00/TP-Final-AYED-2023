#ifndef TERMINAL_H
#define TERMINAL_H
#include "Paginas.h"
#include "Colas.h"
class Terminal{
private:
    /*  Si: Determinante == 0 -> Emisor
        Si: Determinante == 1 -> Receptor
    */
    bool determinante;
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

    /*  Establece el Determinante */
    void setDeterminante(bool);

    /*  Devuelve del Determinante
        @returns bool
    */
    bool getDeterminante();

    /*  Si la pc es un emisor, aniade un ID a la cola (que es el mismo id de la pagina) 
        y separa la pagina en nodos de tamanio 50
        @param Pagina *, Cola<int>*
    */
    void empaquetado(Pagina *,Cola<int>*);

    /*  Establece que X cola esta lista para ser enviada (levanta un flag) y 
        asocia un id de router y terminal a donde debe ser enviado
        @param Cola<int>*, int
    */
    void envio(Cola<int>* /*,int*/);


};
#endif