#ifndef _MAPA_H
#define _MAPA_H
#include <iostream>
#include <vector>
#include "Router.h"
class Mapa{
private:
    int tamanioCuadradoMapa = 10;
    vector<vector<Router>> map;

    Router crearRouter();
    
public:
    Mapa();
    void incluirEnMapa(Router);
    //void imprimirMapa();
    vector<vector<Router>> getMapa();



};
#endif