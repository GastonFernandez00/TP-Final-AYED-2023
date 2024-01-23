#include <iostream>
#include "./Includes/Router.h"
#include "./Includes/Extras.h"

#define MAXROUTER 5
using namespace std;



void printRouter(Router *r){


    for(int i = 0; i < MAXROUTER; i++){
        cout<<"\n---------------------\n"
        <<"Vector de Routers, posicion: "<<i+1<<endl
        <<"\nID: "<<r->getIDRouter()<<"\nEl buffer esta vacio? -> ";
        if(r->routerEmpty())cout<<"NO\n"; else cout<<"SI\n";
        cout<<"El buffer de redireccion esta vacio? -> ";
        if(r->routerRedireccionEmpty())cout<<"NO\n"; else cout<<"SI\n";
        r++;
    }

}


int main(int argc, char const *argv[])
{
    Router r[MAXROUTER];
    
    printRouter(r);

    r->checkIDRouter();

    printRouter(r);


    return 0;
}
