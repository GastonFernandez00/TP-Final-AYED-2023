#ifndef PAGINAS_H
#define PAGINAS_H

//Clase Tamanio:
//Es un tipo de Dato
class Pagina{
private:
    int id_pagina;
    int tamanio;//MAX = 500 //Tambien es la informacion en si misma

    /* Establece el id de la pagina
       @param int 
    */
    void setID(int);

public:

    /*  Constructor de Clase*/
    Pagina();

    /*  Constructor de Clase que recibe un tamanio especifico
        @param int
    */
    Pagina(int);

    /*Destructor de Clase*/
    ~Pagina();

    /*  Devuelve del Tamanio de la Pagina
        @returns int
    */
    int getTamanio();

    /*  Establece el Tamanio de la Pagina <= 500
        @param int
    */
    void setTamanio(int);  
    
    /*  Devuelve el ID de la pagina
        @returns int
    */
    int getID();
};
#endif