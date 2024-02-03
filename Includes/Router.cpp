#include "Router.h"
#include "Extras.h"
#include <time.h>
using namespace std;

Router::Router(){ this->setIDRouter(); this->setRouterPosicion(); this->setReceptores(); }
Router::Router(int i){ this->setIDRouter(i); this->setRouterPosicion();this->setReceptores();}
Router::Router(int i, int x, int y){ this->setIDRouter(i); this->setRouterPosicion(x,y); this->setReceptores();}

Router::~Router(){ }

Terminal Router::crearNuevoReceptor(){ Terminal t; return t;}

void Router::setIDRouter(){ id_Router = rand()%MaximaCantDeRouters; }

void Router::setRouterPosicion(){ posicion[rand()%tamanio_Posicion][rand()%tamanio_Posicion] = 1; }

void Router::setIDRouter(int i){ id_Router = i%MaximaCantDeRouters; }

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

void Router::setMaximaCantDeRouters(int n){ MaximaCantDeRouters = n; }

void Router::checkIDRouter(vector<Router> &vr){ checkIDRouterPriv(vr, 0,vr.size());}

void Router::checkIDRouterPriv(vector<Router> &r,int control, int cantdeRouters){ 
    if(control == 10){ return (void)0; }
      
       
        // burbuja_Router(a,b,cantdeRouters);
        qsort(&r.at(0),cantdeRouters,sizeof(Router),compare);
        
        //for(;;);
        //cout<<"\nSale Sleep"<<endl;

        int veces = 0,contador_a = 0,contador_b = 1;

        for(int i = 0; i < r.size()-1; i++){
            for(int j = 1+i; j < r.size(); j++){
                // if(cantdeRouters != 0){b->getIDRouter();}
                if(r.at(i).getIDRouter() == r.at(j).getIDRouter()){
                    veces++;
                    r.at(j).setMaximaCantDeRouters(r.size());
                    r.at(j).setIDRouter(r.at(j).getIDRouter()+veces);
                    }
                }
            
            veces =0;
        }

        // cout<<"\nID A: "<<a->getIDRouter()<<"\nID B: "<<b->getIDRouter();
        // b->setIDRouter(b->getIDRouter()+1);
        // b++;b++;b++;
        // cout<<"\nNuevo ID B: "<<b->getIDRouter();

        cout<<"\nReingresa Check";
        return checkIDRouterPriv(r,control+1,cantdeRouters);
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

Router crearRouter(){ Router *r = new Router(); return *r;}

int main(int argc, char const *argv[])
{
    int numeroDeRouter = 135,repetidos = 0;
    // Cola<int> c[1000];

    vector<Router> r;
    r.reserve(numeroDeRouter);
    for(int i = 0; i < numeroDeRouter; i++){ r.push_back(crearRouter()); }
    
    cout<<"\nEntraCheck\n";
    r.at(0).checkIDRouter(r);
    cout<<"\nSaleCheck\n";

    for(int i = 0; i < numeroDeRouter-1; i++){
        for(int j = 1+i; j < numeroDeRouter;j++){
            if(r.at(i).getIDRouter() == r.at(j).getIDRouter()){
                repetidos++; cout<<r.at(j).getIDRouter()<<" ";
            }
        }
    }
  
    cout<<"\nRepetidos: "<<repetidos<<endl;

    for(int i = 0; i < numeroDeRouter; i++){
        cout<<r.at(i).getIDRouter()<<" ";
        if((i+1)%10 == 0) cout<<endl;
    }

    return 0;
}
