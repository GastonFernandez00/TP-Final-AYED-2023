#include "Router.h"
using namespace std;

Router::Router(){ id_Router = rand(); posicion = rand(); }
Router::Router(int i){ id_Router = i; posicion = rand();}
Router::Router(int i, int p){ id_Router = i; posicion = p; }

Router::~Router(){ }

void Router::Recepcion(Cola<int>* c){
    if(c->getIDDestino() == this->id_Router){
        buffer.encolar(c);
        delete c;
    }
    else{
        
    }
}