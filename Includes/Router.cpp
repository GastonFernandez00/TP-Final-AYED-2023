#include "Router.h"
using namespace std;

Router::Router(){ id_Router = rand()%256; posicion = rand()%1000; }
Router::Router(int i){ id_Router = i%256; posicion = rand()%1000;}
Router::Router(int i, int p){ id_Router = i%256; posicion = p%1000; }

Router::~Router(){ }

int Router::getIDRouter(){ return id_Router; }

int Router::getPosicionRouter(){ return posicion; }

void Router::Recepcion(Cola<int>* c){
    
    if(c->colaEmpty()){ return (void)0; }

    if(c->getIDDestino() == this->getIDRouter()){
        buffer->encolar(c);
        c->vaciaCola();
    }
    else{
        buffer_Redireccion->encolar(c);
        c->vaciaCola();
    }
}

bool Router::routerEmpty(){ return buffer->colaEmpty(); }

bool Router::routerRedireccionEmpty(){ return buffer_Redireccion->colaEmpty(); }



int main(int argc, char const *argv[])
{

    /*
    Ver:
        Como crear multiples objetos, que todos tengan los mismos parametros
        Como acceder a los objetos dentro de cada buffer
    
    
    
    */


    Cola<int> c[1000];
    Pagina p[100];
    Terminal emisores[100] = {Terminal(false)};
    Router r[256];

    

    // int control = 0;
    // while(control<100){
    //     cout<<endl<<emisores[control].getDeterminante()<<endl;
    //     control++;
    // }
    
    emisores->empaquetado(p,c);
    emisores->envio(c);
    
    //c->

    cout<<r[0].getPosicionRouter()<<endl;
    cout<<r[0].getIDRouter();
    cout<<"\n\n\n\n";
    c->printCola();
    cout<<endl<<c->getIDDestino()<<endl<<r->getIDRouter()<<endl;

    cout<<"\n\n\n\n";
    r[0].Recepcion(c);

    cout<<endl<<endl<<c->sizeCola()<<endl;

    if(!(r[0].routerEmpty())){
        cout<<"\nTiene algo\n";
    }
    else{
        cout<<"\nEsta Vacio\n";
    }

    cout<<"\n\n\n\n";
     if(!(r[0].routerRedireccionEmpty())){
        cout<<"\nTiene algo\n";
    }
    else{
        cout<<"\nEsta Vacio\n";
    }    

    system("pause");
    return 0;
}
