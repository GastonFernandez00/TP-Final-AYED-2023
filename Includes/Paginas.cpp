#include "Paginas.h"
#include "Extras.h"
#include <iostream>
//#include <stdio.h>
using namespace std;

Pagina::Pagina(){ setTamanio(rand()); setID(rand()); setIDDestino(); setidDestinoTerminal();}
Pagina::Pagina(int n){ setTamanio(n); setID(rand()); setIDDestino(); setidDestinoTerminal();}

Pagina::~Pagina(){ }

void Pagina::setTamanio(int n){ tamanio = n%501; }
int Pagina::getTamanio(){ return tamanio; }

void Pagina::setID(int n){ id_pagina = n%MaximaCantDePaginas; }
int Pagina::getID(){ return id_pagina; }

void Pagina::setIDDestino(int d){ id_Destino = d%256; }

void Pagina::setidDestinoTerminal(int d){ id_Destino_Terminal = d%256; }

void Pagina::setIDDestino(){ id_Destino = rand()%256; }

void Pagina::setidDestinoTerminal(){ id_Destino_Terminal = rand()%256; }

int Pagina::getIDDestino(){ return id_Destino; }

int Pagina::getIDDestinoTerminal(){ return id_Destino_Terminal;}

void Pagina::setMaximaCantDePaginas(int d){ MaximaCantDePaginas = d; }

void Pagina::checkIDPaginas(int cantpaginas){ checkIDPaginasPriv(this, this, 0,cantpaginas);}

void Pagina::checkIDPaginasPriv(Pagina *a, Pagina *b, int control,int cantpaginas){
        if(control == 10){ return (void)0; }

    //for(int i = 0; i < 10; i++){
        burbuja_Pagina(a,b,cantpaginas);
        
        //b++;
        //cambio_Prueba(a,b);
    //}

        b++;int veces = 0;
        for(int i = 0; i < 1000; i++){
            
            if(a->getID() > 1000 || a->getID() < 0){ return checkIDPaginasPriv(this,this,control+1,cantpaginas); }

            for(int j = 1; j < 1000-1; j++){
                if(b->getID() < 1000 && b->getID() >= 0){
                    if(a->getID() == b->getID()){
                        b->setMaximaCantDePaginas(cantpaginas);
                        veces+=1;
                        b->setID(b->getID()+veces);
                    }    
                    b++;
                }

            }

            a++;b = a; b++; veces = 0;
        }

        
//    }
}

//  PRUEBA DE FUNCIONES
// int main(int argc, char const *argv[]){   
//     Pagina p;

//     cout<<"TAMANIO: "<<p.getTamanio()<<endl
//     <<"ID: "<<p.getID()<<endl<<"Iddestino: "<<p.getIDDestino()<<endl
//     <<"IdDestinoTerminal: "<<p.getIDDestinoTerminal()<<endl;

//     cout<<"\n-------------\n";
//     cout<<"Restableciendo tamanio";p.setTamanio(350);
//     cout<<"\nRestableciendo IDdestino";p.setIDDestino(350);
//     cout<<"\nRestableciendo Iddestinoterminal";p.setidDestinoTerminal(350);

//     cout<<"\n-------------\nNuevos Valores"<<endl;
//     cout<<"TAMANIO: "<<p.getTamanio()<<endl
//     <<"ID: "<<p.getID()<<endl<<"Iddestino: "<<p.getIDDestino()<<endl
//     <<"IdDestinoTerminal: "<<p.getIDDestinoTerminal()<<endl;

// }
