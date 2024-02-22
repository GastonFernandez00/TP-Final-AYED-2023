#include "Extras.h"
using namespace std;

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

void cambio(Router *a, Router *b){
    Router *aux = new Router();
    *aux = *a; *a = *b; *b = *aux;
    delete aux;
}

void cambio(Terminal *a, Terminal *b){
    Terminal *aux = new Terminal();
    *aux = *a; *a = *b; *b = *aux;
    delete aux;
}

void burbuja_Router(Router *a, Router *b,int cantdeRouters){
    int contador = 0;
    int fores = cantdeRouters;
    Router *aux_a = a, *aux_b = b;
    b++;
    for(int i = 1; i < fores; i++){
        for(int j = 0; j < fores-1;j++){
            if( (a->getIDRouter()) > (b->getIDRouter()) ){
                contador++;
                cambio(a,b);
            }
            a++;b++;
        }
        a = aux_a; b = aux_b; b++;
    }
    //cout<<"Contador: "<<contador;
}

void burbuja_Terminal(Terminal* a,Terminal* b,int cantTerminales){
    int contador = 0;
    int fores = cantTerminales;
    Terminal *aux_a = a, *aux_b = b;
    b++;
    for(int i = 1; i < fores; i++){
        for(int j = 0; j < fores-1;j++){
            if( (a->getIDTerminal()) > (b->getIDTerminal()) ){
                contador++;
                cambio(a,b);
            }
            a++;b++;
        }
        a = aux_a; b = aux_b; b++;
    }
    //cout<<"Contador: "<<contador;   
}