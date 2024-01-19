#include "Router.h"
using namespace std;

Router::Router(){ id_Router = rand(); posicion = rand(); }
Router::Router(int i){ id_Router = i; posicion = rand();}
Router::Router(int i, int p){ id_Router = i; posicion = p; }

Router::~Router(){ }

int Router::getIDRouter(){ return id_Router; }

int Router::getPosicionRouter(){ return posicion; }

void Router::Recepcion(Cola<int>* c){
    if(c->getIDDestino() == this->getIDRouter()){
        buffer->encolar(c);
        delete c;
    }
    else{
        buffer_Redireccion->encolar(c);
        delete c;
    }
}



int main(int argc, char const *argv[])
{
    Pagina p[100];
    Terminal t[1000000];
    Router r[256];

    cout<<r[0].getPosicionRouter();
    
    
    return 0;
}
