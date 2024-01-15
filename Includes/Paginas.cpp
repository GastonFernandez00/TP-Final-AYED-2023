#include "Paginas.h"
#include <iostream>
//#include <stdio.h>
//using namespace std;

Pagina::Pagina(){ setTamanio(rand()); setID(rand()); }
Pagina::Pagina(int n){ setTamanio(n); setID(rand()); }

Pagina::~Pagina(){ }

void Pagina::setTamanio(int n){ tamanio = n%501; }
int Pagina::getTamanio(){ return tamanio; }

void Pagina::setID(int n){ id_pagina = n; }
int Pagina::getID(){ return id_pagina; }


/*  PRUEBA FUNCIONES
int main(int argc, char const *argv[])
{   int i = 0;
    while(i<1000){
    
    Pagina p;
    if(!(p.getTamanio() > 500)){
        cout<<"ERROR";
    }
    i++;    
    }
    return 0;
}
*/