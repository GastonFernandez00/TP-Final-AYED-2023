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
        buffer.encolar(c);
        delete c;
    }
    else{
        
    }
}