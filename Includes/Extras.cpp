#include "Extras.h"
using namespace std;

// void cambio(Router *a, Router *b){
//     Router *aux = new Router();
//     *aux = *a; *a = *b; *b = *aux;
//     delete aux;
// }

void cambio(Terminal *a, Terminal *b){
    Terminal *aux = new Terminal();
    *aux = *a; *a = *b; *b = *aux;
    delete aux;
}

void cambio(Pagina *a, Pagina *b){
    Pagina *aux = new Pagina();
    *aux = *a; *a = *b; *b = *aux;
    delete aux;
}

// void burbuja_Router(Router *a, Router *b){
//     int contador = 0;
//     int fores = 199;
//     Router *aux_a = a, *aux_b = b;
//     b++;
//     for(int i = 1; i < fores; i++){
//         for(int j = 0; j < fores-1;j++){
//             if( (a->getIDRouter()) > (b->getIDRouter()) ){
//                 contador++;
//                 cambio(a,b);
//             }
//             a++;b++;
//         }
//         a = aux_a; b = aux_b; b++;
//     }
//     //cout<<"Contador: "<<contador;
// }

void burbuja_Terminal(Terminal* a,Terminal* b){
    int contador = 0;
    int fores = 256;
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

void burbuja_Pagina(Pagina* a,Pagina* b,int cantpaginas){
    int contador = 0;
    int fores = cantpaginas;
    Pagina *aux_a = a, *aux_b = b;
    b++;
    for(int i = 1; i < fores; i++){
        for(int j = 0; j < fores-1;j++){
            if( (a->getID()) > (b->getID()) ){
                contador++;
                cambio(a,b);
            }
            a++;b++;
        }
        a = aux_a; b = aux_b; b++;
    }
    //cout<<"Contador: "<<contador;   
}


