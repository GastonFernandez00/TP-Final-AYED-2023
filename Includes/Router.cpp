#include "Router.h"
using namespace std;

Router::Router(){ setIDRouter(this); setRouterPosicion(this);  }
Router::Router(int i){ setIDRouter(this,i); setRouterPosicion(this);}
Router::Router(int i, int p){ setIDRouter(this,i); setRouterPosicion(this,p); }

Router::~Router(){ }

void Router::setIDRouter(Router *r){ r->id_Router = rand()%256; }

void Router::setRouterPosicion(Router *r){ r->posicion = rand()%1000; }

void Router::setIDRouter(Router *r,int i){ r->id_Router = i%256; }

void Router::setRouterPosicion(Router *r,int p){ r->posicion = p%1000; }

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

void Router::cambiarRouterID(Router* ref, Router* inicial){
    //if(ref->getIDRouter() > inicial->getIDRouter()){
        setIDRouter(inicial,inicial->getIDRouter()+1);
    //}
}

void Router::checkIDRouter(Router *r){
    Router *prev = r;
    prev--;
    do{
        if(prev->getIDRouter() == r->getIDRouter() || prev->getPosicionRouter() == r->getPosicionRouter()){
            cambiarRouterID(prev,r);
            return checkIDRouter(r);
        }
        else prev--;

    }while(prev->getIDRouter() != NULL || prev->getPosicionRouter() != NULL);

    Router *post = r;
    post++;

    do{
        if(post->getIDRouter() == r->getIDRouter() || post->getPosicionRouter() == r->getPosicionRouter()){
            cambiarRouterID(post,r);
            return checkIDRouter(r);
        }
        else prev--;

    }while(prev->getIDRouter() != NULL || prev->getPosicionRouter() != NULL);
    /*
    if(post->getIDRouter() != NULL){

        
        return checkIDRouter(post);
    }*/
}


int main(int argc, char const *argv[])
{

    /*
    Ver:
        >Como crear multiples objetos, que todos tengan los mismos parametros
        
        >Como acceder a los objetos dentro de cada buffer
        
        >Ver que no haya 2 routers con la misma id ni posicion. Puede mandarse el arreglo a una funcion que checkee
        cada uno de los elementos, y revise si hay alguno igual

        >Modificar las funciones set posicion, ID y checkIDRouter para que no reciban un 
        parametro Router
    
    
    */


    Cola<int> c[1000];
    Pagina p[100];
    Terminal emisores[100];
    Router r[100],*pr; 

    pr = r;
    for(int rout = 0; rout < 256; rout++){
        if(pr->getIDRouter() != NULL){
        cout<<rout<<" -> "<<pr->getIDRouter()<<endl;
        pr++;}
    }

    r[2].setIDRouter(&r[2],64);

    cout<<"\n----------------------------------\n"
    <<"CHECKEANDO\n----------------------------------\n";
    
    pr = r;
    for(int i = 0; i < 256; i++){
        pr->checkIDRouter(pr);
        pr++;
    }

    

    pr = r;
    for(int rout = 0; rout < 256; rout++){
        if(pr->getIDRouter() != NULL){
        cout<<rout<<" -> "<<pr->getIDRouter()<<endl;
        pr++;}
    }

    // int control = 0;
    // while(control<100){
    //     cout<<endl<<emisores[control].getDeterminante()<<endl;
    //     control++;
    // }
    
    /*emisores->empaquetado(p,c);
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
    }    */

    system("pause");
    return 0;
}
