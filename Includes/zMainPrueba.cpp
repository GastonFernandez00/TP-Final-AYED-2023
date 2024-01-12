#include <iomanip>
#include <stdio.h>
#include <iostream>
//#include "Nodos.hpp"
//#include "Listas.h"
#include    "Colas.h"

using namespace std;

int main(int argc, char const *argv[]){
    int count = 10;   
    
    
    Cola<int> c[10];
    
    for (int i = 0; i < count; i++){
        int x = rand()%10;
        for (int j = 0; j < x; j++){
            c[i].encolar(rand());
        }        
    }

    for (int i = 0; i < count; i++){
        cout<<"\n---------------------------\nCola N: "<<i+1<<endl;
        //cout<<c[i].sizeCola();
        c[i].printCola();
    }
    
    

    
    
    
    
    /*Cola<string> *c = new Cola<string>();
    for(int i = 0 ; i<10; i++) c->encolar("Gaston");
    c->printCola();

    cout<<"\n\n\n"<<c->sizeCola();
    



   /* Lista<int> *p = new Lista<int>();
    //Lista<int>* p = new Lista<int>();
    for (int i = 0; i < 10; i++){ p->add(rand()); }

    cout<<"\n-------------\n";
    cout<<p->size();
    cout<<"\n-------------\n";
    p->printLista();

    /*p->borrarDato(6334);
    p->borrarDato(19169);
    p->borrarDato(41);
    p->borrarDato(11478);
    p->borrarDato(29358);

    p->borrarDato(-5);

    p->borrarDato(26962);*/

    //for(int i = 0; i< 5; i++) p->borrarCabeza();

    //for(int i = 0; i< 8; i++) p->borrarLast();

    /*p->tomar(0);

    cout<<"\n----\n";

    cout<<p->last();

    cout<<"\n----\n";

    p->printLista();
    //cout<<p->cabeza();


    /*if(p->esta(63304)){
        cout<<"\n\n\nESTAAAAAAAAAAAAAAAAAAAAAAAAAAA\n\n\n";
    }
    else{
        cout<<"\n\n\nFuck Off\n\n\n";
    }*/
    return 0;
}