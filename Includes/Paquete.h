#ifndef _PAQUETE_H
#define _PAQUETE_H
#include <iostream>
using namespace std;
class Paquete{
private:
    int TAMANIO_MAX = 50;
    int packNumero = -1;
    int idPertenencia = -1;
    int DATO = 0;
public:

    //Constructor
    Paquete();

    //Destructor
    ~Paquete();

    /*  Establece el numero de paquete. Indica que posicion deberia tener al rearmar
        @param int
    */
    void setPackNumero(int);

    /*  Establece a que pagina pertenece
        @param int
    */
    void setIdPertenencia(int);

    /*  Establece que dato contiene
        @param int
    */
    void setDato(int);

    /*  Devuelve a que pagina pertenece
        @returns int
    */
    int getIdPertenencia();
    
    /*  Devuelve la posicion que deberia tener el paquete
        @returns int
    */
    int getPackNumero();

    /*  Devuelde el dato que contiene el paquete
        @returns int
    */
    int getDato();
};
#endif