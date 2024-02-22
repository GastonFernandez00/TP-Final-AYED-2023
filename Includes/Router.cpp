#include "Router.h"
#include "Extras.h"
#include <time.h>
using namespace std;

Router::Router(){ this->setIDRouter(); this->setReceptores(); this->setBandWidth(); }
Router::Router(int i){ this->setIDRouter(i); }

Router::~Router(){ }

Terminal Router::crearNuevoReceptor(){ Terminal t; return t;}

void Router::setIDRouter(){ id_Router = rand()%MaximaCantDeRouters; }

void Router::setRouterPosicion(){}

void Router::setIDRouter(int i){ id_Router = i%MaximaCantDeRouters; }

void Router::setRouterPosicion(int x, int y){ setRouter_x(x); setRouter_y(y); }

void Router::setRouter_x(int x){ posicion_x = x; }

void Router::setRouter_y(int y){ posicion_y = y; }

int Router::getRouter_x(){ return posicion_x;}

int Router::getRouter_y(){ return posicion_y;}

int Router::getIDRouter(){ return id_Router; }

void  Router::printPosicionRouter(){
    cout<<"\nPosicion X: "<<getRouter_x()<<endl<<"Posicion Y: "<<getRouter_y()<<endl;
}

void Router::Recepcion(queue<Paquete> &c){
    //Para cada paquete, decide si debe guardarse en este router, o enviarse a otro
    if(c.empty()){ return (void)0; }
    while(!(c.empty())){    
        if(c.front().getIDDestino() == this->getIDRouter()){
            buffer.push(c.front());
            c.pop();
        }
        else{
            buffer_Redireccion.push(c.front());
            c.pop();
        }
    }
}

//Recibe 1 paquete y decide si debe guardarse en este router, o enviarse a otro
void Router::Recepcion(Paquete &p){ 
    if(p.getDato() <= 0) return (void)0;
    else if(p.getIDDestino() == this->getIDRouter()){
        buffer.push(p);
    }
    else{
        buffer_Redireccion.push(p);
    }
}

bool Router::routerEmpty(){ return buffer.empty(); }

bool Router::routerRedireccionEmpty(){ return buffer_Redireccion.empty(); }

void Router::setMaximaCantDeRouters(int n){ MaximaCantDeRouters = n; }

//Llama a una funcion privada, que verifica que los ids no se repitan
void Router::checkIDRouter(vector<Router> &vr){ checkIDRouterPriv(vr, 0,vr.size());}

void Router::checkIDRouterPriv(vector<Router> &r,int control, int cantdeRouters){ 
    if(r.size() < 2){ return (void)0; }
    if(control == 10){ return (void)0; }
       
       //En base a sus IDs, reordena los routers, para luego poder ver cuales se repiten,
       //mas facilmente
        qsort(&r.at(0),cantdeRouters,sizeof(Router),compare);

        int veces = 0,contador_a = 0,contador_b = 1;

        for(int i = 0; i < r.size()-1; i++){ //Si los routers tiene el mismo ID, cambia el de uno de los 2
            for(int j = 1+i; j < r.size(); j++){
                if(r.at(i).getIDRouter() == r.at(j).getIDRouter()){
                    veces++;
                    r.at(j).setMaximaCantDeRouters(r.size());
                    r.at(j).setIDRouter(r.at(j).getIDRouter()+veces);
                    }
                }
            
            veces =0;
        }//Vuelve a llamar a la funcion, 10 veces, para asegurar que no se repitan
        return checkIDRouterPriv(r,control+1,cantdeRouters);
}

//Crea todos los terminales receptores para el router
void Router::setReceptores(){
    for(int i = 0; i < cantidadDeReceptores; i++){
        receptores.push_back(crearNuevoReceptor()); 
    }

    for(int i = 0; i < cantidadDeReceptores; i++){ //Establece cada terminal como receptor
        receptores[i].setDeterminante(1); 
    }
    receptores.at(0).checkIDTerminal(receptores);
}

vector<Terminal>& Router::getReceptor(){ return receptores; }

Router crearRouter(){ Router *r = new Router(); return *r;}

queue<Paquete>& Router::getBufferRouter(){ return buffer; }

int Router::getSizeBuffer(){ return buffer.size(); }

queue<Paquete>& Router::getBufferRedireccionRouter(){ return buffer_Redireccion; }

int Router::getSizeBufferRedireccionamiento(){ return buffer_Redireccion.size(); }

//Asocia los routers que se le pasen, como cercanos. Necesita usar
//la funcion del Mapa setCeranos()
void Router::incluirCercanos(Router *r){  
    if( cercanos.size() < 8) cercanos.push_back(r);
    else{ cout<<"\nCapacidad llena. Se necesita rearmar Ruta\n"; }
}

void Router::borrarCercanos(){ cercanos.clear(); }

vector<Router*>& Router::getCercanos(){ return cercanos; }

void Router::setBandWidth(){
    random_device rd;
    uniform_int_distribution<int> dist(1,50);
    bandWidth = dist(rd);
}

int Router::getBandWidth(){ return bandWidth; }

vector<queue<Paquete>>& Router::getPaquetesPreparados(){ return Preparado;}

Terminal& Router::getTerminalEspecifico(int n){
    for(int i = 0; i < this->getReceptor().size(); i++){
        if(this->getReceptor().at(i).getIDTerminal() == n)
            return this->getReceptor().at(i);
    }
    cout<<"\nEl terminal no se encuentra en el mapa."<<endl;
}
