#ifndef PAGINAS_H
#define PAGINAS_H

class Pagina{
private:
    int id_pagina;
    int tamanio;//MAX = 500 //Tambien es la informacion en si misma
    int id_Destino = -1; //Router de Destino
    int id_Destino_Terminal = -1; //Terminal de Destino
    

    int  MaximaCantDePaginas = 256;
    void checkIDPaginasPriv(Pagina*, Pagina*,int,int);
    void setMaximaCantDePaginas(int);
public:

    /* Establece el id de la pagina
       @param int     */
    void setID(int);

    /*  Constructor de Clase
        Define ID Y  TAMANIO    */
    Pagina();

    /*  Constructor de Clase que recibe un tamanio especifico
        @param int    */
    Pagina(int);

    /*Destructor de Clase*/
    ~Pagina();

    /*  Devuelve del Tamanio de la Pagina
        @returns int    */
    int& getTamanio();

    /*  Establece el Tamanio de la Pagina <= 500
        @param int    */
    void setTamanio(int);  
    
    /*  Devuelve el ID de la pagina
        @returns int*/
    int getID();

    /*  Establece el ID de destino de la cola, pero sin parametros, aleatoriamente    */
    void setIDDestino();    
    
    /*  Establece el ID de destino de la cola
        @param int    */
   void setIDDestino(int);
    
    /*  Devuelve el ID del terminal a donde debe ir la cola
        @returns int    */
    void setidDestinoTerminal();

    /*  Establece el Id de la computadora de destino.
        Si cada router tiene 256 (0 - 255) computadoras, cada una 
        esta numerada de esa forma, independiente de las otras que esten conectadas
        a otros routers
        @param int    */
    void setidDestinoTerminal(int);

    /*  Devuelve el Id de del router a donde debe ir la cola
        @returns int    */
    int getIDDestino();

    /*  Establece el Id de la computadora de destino.
        Si cada router tiene 256 (0 - 255) computadoras, cada una 
        esta numerada de esa forma, independiente de las otras que esten conectadas
        a otros routers. Pero sin parametros.*/
    int getIDDestinoTerminal();

    void checkIDPaginas(int);

};
#endif