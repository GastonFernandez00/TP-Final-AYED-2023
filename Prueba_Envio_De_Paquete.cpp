#include <iostream>
#include ".\Includes\Mapa.h"
using namespace std;

random_device rd;
uniform_int_distribution<int> dist(0,1);

int main(int argc, char const *argv[])
{
    Pagina p[1];
    vector<Terminal> t;  
    vector<Router> r;
    for(int i = 0; i < 2; i ++){
        Terminal Nuevo_t; t.push_back(Nuevo_t);
        Router Nuevo_r; r.push_back(Nuevo_r);
    }
    t.at(0).checkIDTerminal(t);
    r.at(0).checkIDRouter(r);
    p->setIDDestino(r.at(dist(rd)).getIDRouter());
    
    cout<<"Informacion de la Pagina\n"
    <<"\nID Destino: "<<p->getIDDestino()
    <<"\nID Destino Terminal: "<<p->getIDDestinoTerminal()
    <<"\nID de la Pagina: "<<p->getID()
    <<"\nTamanio de la Pagina: "<<p->getTamanio()<<endl;
    
    cout<<"\nRouters Existentes: ";for(int i = 0; i < 2; i++) cout<<r.at(i).getIDRouter()<<" ";
      
    t.at(0).empaquetado(p);
    
    cout<<"\n\nPaquetes dentro de la Terminal: \n";
    Cola<Paquete> aux = t.at(0).getPaquetes();
    while(aux.sizeCola() > 0){
        cout<<aux.getPrimero().getDato()<<endl;
        aux.desencolar();
    }

    Mapa m(5);

    for(int i = 0; i < r.size();i++) m.incluirEnMapa(r.at(i));

    m.imprimirMapa();

    for(int i = 0; i < m.getMapa().size(); i ++)
        for(int j = 0; j < m.getMapa().size(); j ++)
            if(m.getMapa().at(i).at(j).getIDRouter() == r.at(0).getIDRouter()){
                cout<<"Router donde se esta haciendo la recepcion: "<<m.getMapa().at(i).at(j).getIDRouter()
                <<endl;
                m.getMapa().at(i).at(j).Recepcion(t.at(0).getPaquetes());
            }

    cout<<"\n\nPaquetes dentro de la Terminal TRAS recepcion: \n";
   aux = t.at(0).getPaquetes();
    while(aux.sizeCola() > 0){
        cout<<aux.getPrimero().getDato()<<endl;
        aux.desencolar();
    }
    
    for(int k = 0; k < 2; k ++){
    cout<<"\n\n\nPaquetes en el Router: "<<r.at(k).getIDRouter()<<endl;
     for(int i = 0; i < m.getMapa().size(); i ++)
        for(int j = 0; j < m.getMapa().size(); j ++)
            if(m.getMapa().at(i).at(j).getIDRouter() == r.at(k).getIDRouter()){
                cout<<"ENCONTRE EL ROUTER";
                cout<<"\nCant de Paquetes almacenados: ";
                cout<<m.getMapa().at(i).at(j).getBufferRouter().sizeCola();
                cout<<"\nCant de Paquetes almacenados a REDIRECCIONAR: ";
                cout<<m.getMapa().at(i).at(j).getBufferRedireccionRouter().sizeCola();

            }}
            //     if(m.getMapa().at(i).at(j).getSizeBuffer() > 0 ){
            //         aux = m.getMapa().at(i).at(j).getBufferRouter();
            //         while(aux.sizeCola() > 0){
            //             cout<<aux.getPrimero().getDato()<<endl;
            //             aux.desencolar();
            //         }
            //     }
            //     else{
            //         aux = m.getMapa().at(i).at(j).getBufferRedireccionRouter();
            //         while(aux.sizeCola() > 0){
            //             cout<<aux.getPrimero().getDato()<<endl;
            //             aux.desencolar();
            //         }
            //     }
            // }




    return 0;
}
