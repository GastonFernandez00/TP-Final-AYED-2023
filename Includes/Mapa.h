#ifndef _MAPA_H
#define _MAPA_H
#include <iostream>
#include <vector>
#include "Router.h"
class Mapa{
private:
    int tamanioCuadradoMapa = 50;
    vector<vector<Router>> map;

    Router crearRouter();
    void setTamanioCuadradoMapa(int);
    float calcularDistancia(Router *,Router *);
    void armadoDePaginas();
    
    
public:
    Mapa();
    Mapa(int);
    void incluirEnMapa(Router&);
    void imprimirMapa();
    vector<vector<Router>>& getMapa();
    void setCercanos();
    int cantidadDeRoutersEnMapa();
    void RearmadoDePaquetes();

    Router& getRouterEspecifico(int);

    void envioEntreRouters();

    void envioATerminales();
    


};
#endif