#include "Paginas.h"
#include <iostream>
//#include <stdio.h>
//using namespace std;

Pagina::Pagina(){ setTamanio(rand()); }
Pagina::Pagina(int n){ setTamanio(n); }

Pagina::~Pagina(){ }

void Pagina::setTamanio(int n){ tamanio = n%501; }
int Pagina::getTamanio(){ return tamanio; }

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