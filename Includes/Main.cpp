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
    for (int i = 0; i < 10; i++){ p->add(i); }

    cout<<"\n-------------\n";
    cout<<p->size();
    cout<<"\n-------------\n";
    return 0;
}