#ifndef _MAPA_H
#define _MAPA_H
#include <iostream>
#include <vector>
#include "Router.h"
class Mapa{
private:
    int tamanioCuadradoMapa = 50; //Tamanio estandar del mapa
    vector<vector<Router>> map; //El mapa en si mismo

    /*  Genera un Router vacio, solo para que el mapa tenga una organizacion coherente
        @returns Router */
    Router crearRouter();   

    /*  Establece las filas y columnas del mapa segun el valor que se le pase
        @param int  */
    void setTamanioCuadradoMapa(int);

    /*  Devuelve la distancia entre 2 Routers
        @param Router*, Router* 
        @returns float  */
    float calcularDistancia(Router *,Router *);

    /*  Arma las paginas, en base a las colas de paquetes que tengan los Terminales */
    void armadoDePaginas();
    
    
public:

    /*  Genera el mapa, todas las posiciones son, en primer lugar, Routers vacios */
    Mapa();

    /*  Genera el mapa con un tamanio especifico, todas las posiciones son, en primer lugar, Routers vacios
        @param int  */
    Mapa(int);

    /*  Almacena en el Mapa, el Router que se le pase 
        @param Router&  */
    void incluirEnMapa(Router&);

    /*  'Imprime' el mapa. Imprime los IDs, de forma ordenada  */
    void imprimirMapa();

    /*  Devuelve el mapa, para que se pueda recorrer y/o modificar
        @returns vector<vector<Router>>&    */
    vector<vector<Router>>& getMapa();

    /*  Establece los Routers cercanos a cada uno   */
    void setCercanos();

    /*  Devuelve cuantos routers no vacios existen en el mapa
        @returns int    */
    int cantidadDeRoutersEnMapa();

    /*  Crea y organiza colas de paquetes, teniendo en cuenta a que pagina
        pertenecian originalmente los paquetes  */
    void RearmadoDePaquetes();

    /*  Devuelve un Router especifico
        @param int
        @returns Router&    */
    Router& getRouterEspecifico(int);


    /*  Provoca un envio entre routers  */
    void envioEntreRouters();

    /*  Provoca un Envio a terminales   */
    void envioATerminales();

    /*  Imprime las paginas ya armadas de un terminal*/
    void printFinalDePaginas();
};
#endif