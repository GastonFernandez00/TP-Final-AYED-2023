#ifndef _PAQUETE_H
#define _PAQUETE_H
#include <iostream>
#include "Paginas.h"
using namespace std;
class Paquete{
private:
    int TAMANIO_MAX = 50;

    int idPertenencia = -1;
    int id_Destino = -1;
    int id_Destino_Terminal = -1;
    
    int packNumero = -1;
    int DATO = 0;
public:

    //Constructor
    Paquete();

    //Destructor
    ~Paquete();

    /*  Establece el numero de paquete. Indica que posicion deberia tener al rearmar
        @param int    */
    void setPackNumero(int);

    /*  Establece a que pagina pertenece
        @param Pagina   */
    void setIds(Pagina *);

    /*  Establece que dato contiene
        @param int    */
    void setDato(int);

    /*  Devuelve a que pagina pertenece
        @returns int    */
    int getIdPertenencia();
    
    /*  Devuelve el Id de del router a donde debe ir la cola
            @returns int    */
    int getIDDestino();

    /*  Establece el Id de la computadora de destino.
        Si cada router tiene 256 (0 - 255) computadoras, cada una 
        esta numerada de esa forma, independiente de las otras que esten conectadas
        a otros routers. Pero sin parametros.*/
    int getIDDestinoTerminal();

    
    /*  Devuelve la posicion que deberia tener el paquete
        @returns int    */
    int getPackNumero();

    /*  Devuelde el dato que contiene el paquete
        @returns int    */
    int getDato();
};
#endif