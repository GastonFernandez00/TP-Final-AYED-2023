#include "Router.h"
using namespace std;

Router::Router(){ this->setIDRouter(); this->setRouterPosicion();  }
Router::Router(int i){ this->setIDRouter(i); this->setRouterPosicion();}
Router::Router(int i, int p){ this->setIDRouter(i); this->setRouterPosicion(p); }

Router::~Router(){ }

void Router::setIDRouter(){ id_Router = rand()%256; }

void Router::setRouterPosicion(){ posicion = rand()%1000; }

void Router::setIDRouter(int i){ id_Router = i%256; }

void Router::setRouterPosicion(int p){ posicion = p%1000; }

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
        inicial->setIDRouter(inicial->getIDRouter()+1);
    //}
}

void Router::checkIDRouter(){ checkIDRouterPriv(this, this);}
    /*
    Router *a = this, *b = this;
    b++;

    if(a->getIDRouter() != b->getIDRouter()){ b++; }








    /*
    for(int i = 1; i < 256; i++){
        for(int j = 0; j < 256-1; j++){
            if(b->getIDRouter() != NULL){
                if(a->getIDRouter() != b->getIDRouter()){
                    b++;
                }
                else{
                    b->setIDRouter(b->getIDRouter()+1);
                    b++;
                }
            }
        }
        a++;b = this; b+=i;
    }




    /*
    Router *prev = this;
    prev--;
    do{
        if(prev->getIDRouter() == this->getIDRouter() || prev->getPosicionRouter() == this->getPosicionRouter()){
            cambiarRouterID(prev,this);
            return this->checkIDRouter();
        }
        else prev--;

    }while(prev->getIDRouter() != NULL || prev->getPosicionRouter() != NULL);

    Router *post = this;
    post++;

    do{
        if(post->getIDRouter() == this->getIDRouter() || post->getPosicionRouter() == this->getPosicionRouter()){
            cambiarRouterID(post,this);
            return this->checkIDRouter();
        }
        else prev--;

    }while(prev->getIDRouter() != NULL || prev->getPosicionRouter() != NULL);
    /*
    if(post->getIDRouter() != NULL){

        
        return checkIDRouter(post);
    }
}*/

void Router::checkIDRouterPriv(Router *a, Router *b){
    b++;
    if(b == NULL){
        a++;b = a; b++;
        return checkIDRouterPriv(a,b);
    }
    else if(a->getIDRouter() != b->getIDRouter()){
        b++;
        return checkIDRouterPriv(a,b);
    }
    else{
        b->setIDRouter(b->getIDRouter()+1);
        b++;
        checkIDRouterPriv(a,b); 
    }
}


int main(int argc, char const *argv[])
{

    /*
    Ver:
        >Como crear multiples objetos, que todos tengan los mismos parametros
        
        >Como acceder a los objetos dentro de cada buffer
        
        >Ver que no haya 2 routers con la misma id ni posicion. Puede mandarse el arreglo a una funcion que checkee
        cada uno de los elementos, y revise si hay alguno igual

        >Ver que cada Termianl tenga un unico ID
    
    
    */


    Cola<int> c[1000];
    Pagina p[100];
    Terminal emisores[100];
    Router r[10],*pr; 


    
    pr = r;
    for(int rout = 0; rout < size(r); rout++){
        if(pr->getIDRouter() != NULL){
        cout<<rout<<" -> "<<pr->getIDRouter()<<endl;
        pr++;}
    }

    r[2].setIDRouter(64);

    cout<<"\n----------------------------------\n"
    <<"CHECKEANDO\n----------------------------------\n";
    
    r->checkIDRouter();cout<<endl;
    /*pr = r;
    for(int i = 0; i < 256; i++){
        pr->checkIDRouter(pr);
        pr++;
    }*/

    

    pr = r;
    for(int rout = 0; rout < size(r); rout++){
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

    //system("pause");
    return 0;
}
