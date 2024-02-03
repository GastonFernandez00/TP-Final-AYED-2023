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
    if(r.size() < 2){ return (void)0; }
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

        //cout<<"\nReingresa Check";
        return checkIDRouterPriv(r,control+1,cantdeRouters);
}

void Router::setReceptores(){
    for(int i = 0; i < cantidadDeReceptores; i++){
        receptores.push_back(crearNuevoReceptor()); 
    }

    for(int i = 0; i < cantidadDeReceptores; i++){ 
        receptores[i].setDeterminante(1); 
    }
    receptores.at(0).checkIDTerminal(receptores);
}

vector<Terminal> Router::getReceptor(){ return receptores; }

Router crearRouter(){ Router *r = new Router(); return *r;}

Cola<Paquete> Router::getBufferRouter(){ return buffer; }

Cola<Paquete> Router::getBufferRedireccionRouter(){ return buffer_Redireccion; }


//Prueba de Funciones
// int main(int argc, char const *argv[]){
//     int cantdePaginas = (time(nullptr)*rand())%1000;
//     Pagina p[cantdePaginas];
    
//     vector<Terminal> emisores; int cantdeEmisores = (time(nullptr)*rand())%256;
//     for(int i = 0; i < cantdeEmisores; i++) { Terminal terminal_aux; emisores.push_back(terminal_aux); }
//     emisores.at(0).checkIDTerminal(emisores);

//     vector<Router> routers; int cantdeRouters = (time(nullptr)*rand())%256;
//     for(int i = 0; i < cantdeRouters; i++) { Router router_aux; routers.push_back(router_aux); }
//     routers.at(0).checkIDRouter(routers);

//     cout<<"\nCantidad de Paginas: "<<cantdePaginas;
//     cout<<"\nCantidad de Emisores: "<<emisores.size();
//     cout<<"\nCantidad de Routers: "<<routers.size();
//     int cantdeReceptores = 0;
//     for(int i = 0; i < routers.size(); i++){
//         vector<Terminal> terminal_aux = routers.at(i).getReceptor();
//         cantdeReceptores += terminal_aux.size();
        
//     }
//     cout<<"\nCantidad de Receptores: "<<cantdeReceptores<<endl;

    // Router r;
    // vector<Terminal> aux = r.getReceptor();
    // for(int i = 0; i < aux.size(); i++){
    //     cout<<aux.at(i).getIDTerminal()<<" ";
    //     if((i+1)%10 == 0) cout<<endl;
    // }
    // aux.at(0).checkIDTerminal(aux);

    // int contador;
    // for(int i = 0; i < aux.size(); i++){
    //     for(int j = 0; j < aux.size(); j++){
    //         if(aux.at(i).getIDTerminal() == aux.at(j).getIDTerminal()){
    //             contador++;
    //         }
    //     }
    // }
    
    // cout<<"\nRepetidos: "<<contador<<endl;




    // int numeroDeRouter = (rand()*time(nullptr))%256, repetidos = 0;
    // // Cola<int> c[1000];

    // vector<Router> r;
    // r.reserve(numeroDeRouter);
    // for(int i = 0; i < numeroDeRouter; i++){ r.push_back(crearRouter()); }
    
    // cout<<"\nEntraCheck\n";
    // r.at(0).checkIDRouter(r);
    // cout<<"\nSaleCheck\n";

    // for(int i = 0; i < numeroDeRouter-1; i++){
    //     for(int j = 1+i; j < numeroDeRouter;j++){
    //         if(r.at(i).getIDRouter() == r.at(j).getIDRouter()){
    //             repetidos++; cout<<r.at(j).getIDRouter()<<" ";
    //         }
    //     }
    // }
    // cout<<"\nCant de Routers: "<<r.size()<<endl;
    // cout<<"\nRepetidos: "<<repetidos<<endl;

    // for(int i = 0; i < numeroDeRouter; i++){
    //     cout<<r.at(i).getIDRouter()<<" ";
    //     if((i+1)%10 == 0) cout<<endl;
    // }

    // return 0;
// }
