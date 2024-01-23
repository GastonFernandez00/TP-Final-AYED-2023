#include "Extras.h"
using namespace std;

void cambio(Router *a, Router *b){
    Router *aux = new Router();
    *aux = *a; *a = *b; *b = *aux;
    delete aux;
}

void burbuja(Router *a, Router *b){
    int contador = 0;
    int fores = 200;
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
    cout<<"Contador: "<<contador;
}


