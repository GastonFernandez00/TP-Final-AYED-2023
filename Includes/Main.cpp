#include <iomanip>
#include <stdio.h>
#include <iostream>
//#include "Nodos.hpp"
#include "Listas.h"

using namespace std;

int main(int argc, char const *argv[])
{
    Lista<int> *p = new Lista<int>();
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

    p->tomar(0);

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