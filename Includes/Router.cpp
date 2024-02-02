#include "Router.h"
#include "Extras.h"
#include <time.h>
using namespace std;

Router::Router(){ this->setIDRouter(); this->setRouterPosicion(); this->setReceptores(); }
Router::Router(int i){ this->setIDRouter(i); this->setRouterPosicion();this->setReceptores();}
Router::Router(int i, int x, int y){ this->setIDRouter(i); this->setRouterPosicion(x,y); this->setReceptores();}

Router::~Router(){ }

Terminal Router::crearNuevoReceptor(){ Terminal t; return t;}

void Router::setIDRouter(){ id_Router = rand()%256; }

void Router::setRouterPosicion(){ posicion[rand()%tamanio_Posicion][rand()%tamanio_Posicion] = 1; }

void Router::setIDRouter(int i){ id_Router = i%256; }

void Router::setRouterPosicion(int x, int y){ posicion[y%tamanio_Posicion][x%tamanio_Posicion] = 1; }

int Router::getIDRouter(){ return id_Router; }

int Router::getPosicionRouter(){ return posicion[0][0]; } //CAMBIAR ESTO

void Router::Recepcion(Cola<Paquete> c){
    
    if(c.colaEmpty()){ return (void)0; }

    if(c.getPrimero().getIDDestino() == this->getIDRouter()){
        buffer.encolar(c.getPrimero());
        c.desencolar();
    }
    else{
        buffer_Redireccion.encolar(c.getPrimero());
        c.desencolar();
    }
}

bool Router::routerEmpty(){ return buffer.colaEmpty(); }

bool Router::routerRedireccionEmpty(){ return buffer_Redireccion.colaEmpty(); }

void Router::checkIDRouter(){ checkIDRouterPriv(this, this, 0);}

void Router::checkIDRouterPriv(Router *a, Router *b, int control/*,int i,int j*/){ 
    if(control == 5){ return (void)0; }
    
        burbuja_Router(a,b);
    
        b++;int veces = 0;
        for(int i = 0; i < 256; i++){
            
            if(a->getIDRouter() > 256 || a->getIDRouter() < 0){ return (void)0; }

            for(int j = 0; j < 256; j++){
                if(b->getIDRouter() < 256 && b->getIDRouter() >= 0){
                    if(a->getIDRouter() == b->getIDRouter()){
                        veces+=1;
                        b->setIDRouter(b->getIDRouter()+veces);
                    }    
                    b++;
                }

            }

            a++;b = a; b++; veces = 0;
        }

    checkIDRouterPriv(this,this,control+1);
}

void Router::setReceptores(){
    // for(int i = 0; i < size(receptores); i++){
    //     // receptores.push_back(crearNuevoReceptor()); 
    // }

    for(int i = 0; i < size(receptores); i++){ 
        receptores[i].setDeterminante(1); 
    }
    receptores[0].checkIDTerminal(size(receptores));
}

Terminal* Router::getReceptor(){ return &receptores[0]; }

Router crearRouter(){ Router r; return r;}

int main(int argc, char const *argv[])
{
    int numeroDeRouter = 256,repetidos = 0;
    // Cola<int> c[1000];
    Pagina p[1000];
    Terminal Emisores[256];

    for(int j = 0; j < size(p); j++){
        for(int i = 0; i < size(p)/size(Emisores); i++){
            Emisores[i].empaquetado(&p[j]);
        }
    }
    vector<Router> r;

    for(int i = 0; i < numeroDeRouter; i++){ r.push_back(crearRouter()); }

    for(int i = 0; i < numeroDeRouter; i++){
        r.at(i).Recepcion(Emisores[i].getPaquetes());
    }

      for(int i = 0; i < numeroDeRouter; i++){
        Terminal *det = r.at(i).getReceptor();
        for(int j = 0; j < 256; j++){
            if( det->getDeterminante() == 0){
                cout<<"\nHubo un error en la asignacion del determinante\n";
            }
        }
      }


    cout<<endl<<sizeof(r);
    cout<<"\nFin\n";
    return 0;
}
