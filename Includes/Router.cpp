#include "Extras.h"
#include "Router.h"
using namespace std;

Router::Router(){ this->setIDRouter(); this->setRouterPosicion(); this->setReceptores(); }
Router::Router(int i){ this->setIDRouter(i); this->setRouterPosicion();this->setReceptores();}
Router::Router(int i, int x, int y){ this->setIDRouter(i); this->setRouterPosicion(x,y); this->setReceptores();}

Router::~Router(){ }

void Router::setIDRouter(){ id_Router = rand()%256; }

void Router::setRouterPosicion(){ posicion[rand()%tamanio_Posicion][rand()%tamanio_Posicion] = 1; }

void Router::setIDRouter(int i){ id_Router = i%256; }

void Router::setRouterPosicion(int x, int y){ posicion[y%tamanio_Posicion][x%tamanio_Posicion] = 1; }

int Router::getIDRouter(){ return id_Router; }

int Router::getPosicionRouter(){ return posicion[0][0]; } //CAMBIAR ESTO

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

void Router::checkIDRouter(){ checkIDRouterPriv(this, this, 0/*,0,1*/);}
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

void Router::checkIDRouterPriv(Router *a, Router *b, int control/*,int i,int j*/){ 
    if(control == 5){ return (void)0; }
    //for(int i = 0; i < 5; i++){
        burbuja_Router(a,b);
        //b++;
        //cambio_Prueba(a,b);
    //}

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
    //}
   
   /* b++;int veces = 0;
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
        
    /*b++;
    if(a->getIDRouter() > 265){ return (void)0; }
    else if(b->getIDRouter() > 256){ a++;b = a; return checkIDRouterPriv(a,b);   }
    else if(a->getIDRouter() != b->getIDRouter()){ return checkIDRouterPriv(a,b); }
    else{
        b->setIDRouter(b->getIDRouter()+1);
        return checkIDRouterPriv(this,this);
    }
    
    
    /*int i = 1;
    while(a->getIDRouter() < 256){
        cout<<i<<" -> "<<a->getIDRouter()<<endl;
        a++;i++;
    }

    /*
    bool flag = false;
    Router *aux_a = a, *aux_b = b;
    b++;
    while(b->getIDRouter() != NULL && flag == false){
        if(a->getIDRouter() != b->getIDRouter()){ b++; }
        else if(a->getIDRouter() == b->getIDRouter()){
            b->setIDRouter(b->getIDRouter()+1);
            flag = true;
        }
    }

    if(flag == true){ return checkIDRouterPriv(aux_a,aux_b); }
    else if(flag == false && a->getIDRouter() != NULL){ a++;b = a;return checkIDRouterPriv(a,b);}
    else{}
    /*
    b++;
    if( a->getIDRouter() == NULL) return (void)0;
    else if( b->getIDRouter() == NULL){
        a++;b = a;
        return checkIDRouterPriv(a,b);
    }
    else if(a->getIDRouter() != b->getIDRouter()){
        return checkIDRouterPriv(a,b);
    }
    else{
        b->setIDRouter(b->getIDRouter()+1);
        return checkIDRouterPriv(this,this);
        // return this->checkIDRouter();
        // return checkIDRouterPriv(a,b); 
    }*/
}

void Router::setReceptores(){
    for(int i = 0; i < size(receptores);i++){ 
        receptores[i].setDeterminante(1); 
    }
    receptores->checkIDTerminal();
}

Terminal* Router::getReceptor(){ return &receptores[0]; }



int main(int argc, char const *argv[])
{

    Cola<int> c[1000];
    Pagina p[100];
    //Terminal emisores[100],*pEmis = emisores,receptores[65536], *pRecep;
    Router r[169],*pr = r; 


    Terminal *t = pr->getReceptor();
    cout<<endl;
    for(int j = 0; j < size(r); j++){
        for(int i= 0; i < 256; i++){
            cout<<t->getIDTerminal()<<"  ";
            if((i+1)%10 == 0){ cout<<endl;}
            t++;
        }
    pr++;
    t = pr->getReceptor();
    }
    // for(int i = 0; i < 100; i++){pEmis->setDeterminante(0);pEmis++;}
    // for(int i = 0; i < 65536; i++){pRecep->setDeterminante(1);pRecep++;}

    // pEmis = emisores;
    // pRecep = receptores;
    
    // for(int i = 0; i < 100; i++){cout<<pEmis->getDeterminante();if((i+1)%10)cout<<endl;pEmis++;}
    cout<<endl<<"-----------------------------------------------"<<endl;
    // for(int i = 0; i < 100; i++){cout<<pRecep->getDeterminante();if((i+1)%10)cout<<endl;pRecep++;}
//     r->setRouterPosicion(0,0);
//     cout<<"POSICION R[0] "<<r->getPosicionRouter()<<endl;


//    /* pr = r;
//     for(int rout = 0; rout < size(r); rout++){
//         if(pr->getIDRouter() != NULL){
//         cout<<rout<<" -> "<<pr->getIDRouter()<<endl;
//         pr++;}
//     }
// */
//     pr = r;
//     for(int rout = 0; rout < size(r); rout++){
//         //if(pr->getIDRouter() != NULL){
//         cout<<pr->getIDRouter()<<"  ";
//         if((rout+1)%10 == 0){cout<<endl;}

//         pr++;//}
//     }


//     // r[2].setIDRouter(64);
//     // r[3].setIDRouter(64);
//     // r[0].setIDRouter(64);

    
//     cout<<"\n----------------------------------\n"
//     <<"CHECKEANDO\n----------------------------------\n";
//     r->checkIDRouter();cout<<endl;


//     cout<<"POSICION R[0] "<<r->getPosicionRouter()<<endl;
//     r->getPosicionRouter();
    
//     /*pr = r;
//     for(int i = 0; i < 256; i++){
//         pr->checkIDRouter(pr);
//         pr++;
//     }*/

    

//     // pr = r;
//     // for(int rout = 1; rout < size(r)+1; rout++){
//     //     if(pr->getIDRouter() != NULL){
//     //     cout<<rout<<" -> "<<pr->getIDRouter()<<" ";
//     //     if(rout%6 == 0) cout<<endl;
//     //     pr++;}
//     // }

//     pr = r;
//     for(int rout = 0; rout < size(r); rout++){
//         //if(pr->getIDRouter() != NULL){
//         cout<<pr->getIDRouter()<<"  ";
//         if((rout+1)%10 == 0){cout<<endl;}

//         pr++;//}
//     }

//     emisores->empaquetado(p,c);

//     if(r->routerEmpty()){
//         cout<<"\nVACIO\n";
//     }
//     else{
//         cout<<"\nCONTIENE\n";
//     }

//     // int control = 0;
//     // while(control<100){
//     //     cout<<endl<<emisores[control].getDeterminante()<<endl;
//     //     control++;
//     // }
    
//     /*emisores->empaquetado(p,c);
//     emisores->envio(c);
    
//     //c->

//     cout<<r[0].getPosicionRouter()<<endl;
//     cout<<r[0].getIDRouter();
//     cout<<"\n\n\n\n";
//     c->printCola();
//     cout<<endl<<c->getIDDestino()<<endl<<r->getIDRouter()<<endl;

//     cout<<"\n\n\n\n";
//     r[0].Recepcion(c);

//     cout<<endl<<endl<<c->sizeCola()<<endl;

//     if(!(r[0].routerEmpty())){
//         cout<<"\nTiene algo\n";
//     }
//     else{
//         cout<<"\nEsta Vacio\n";
//     }

//     cout<<"\n\n\n\n";
//      if(!(r[0].routerRedireccionEmpty())){
//         cout<<"\nTiene algo\n";
//     }
//     else{
//         cout<<"\nEsta Vacio\n";
//     }    */

//     // while(1);
//     system("pause");
    return 0;
}
