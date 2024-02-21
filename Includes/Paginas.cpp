#include "Paginas.h"
#include "Extras.h"
#include <iostream>
#include <random>
//#include <stdio.h>
using namespace std;

Pagina::Pagina(){ srand(time(nullptr)); setTamanio(rand()); setID(rand()); setIDDestino(); setidDestinoTerminal();}
Pagina::Pagina(int n){ srand(time(nullptr)); setTamanio(n); setID(rand()); setIDDestino(); setidDestinoTerminal();}

Pagina::~Pagina(){ }

void Pagina::setTamanio(int n){ tamanio = n%501; }
int Pagina::getTamanio(){ return tamanio; }

void Pagina::setID(int n){ id_pagina = n%MaximaCantDePaginas; }
int Pagina::getID(){ return id_pagina; }

void Pagina::setIDDestino(int d){ id_Destino = d%256; }

void Pagina::setidDestinoTerminal(int d){ id_Destino_Terminal = d%256; }

void Pagina::setIDDestino(){ srand(time(nullptr)); id_Destino = rand()%256; }

void Pagina::setidDestinoTerminal(){
    random_device rd;
    uniform_int_distribution<int> dist(0,255);
    id_Destino_Terminal = dist(rd); 
}

int Pagina::getIDDestino(){ return id_Destino; }

int Pagina::getIDDestinoTerminal(){ return id_Destino_Terminal;}

void Pagina::setMaximaCantDePaginas(int d){ MaximaCantDePaginas = d; }

void Pagina::checkIDPaginas(int cantpaginas){ checkIDPaginasPriv(this, this, 0,cantpaginas);}

void Pagina::checkIDPaginasPriv(Pagina *a, Pagina *b, int control,int cantpaginas){
        if(control == 10){ return (void)0; }

    
        burbuja_Pagina(a,b,cantpaginas);
        
        b++;int veces = 0;
        for(int i = 0; i < cantpaginas; i++){
            
            if(a->getID() > cantpaginas || a->getID() < 0){ return checkIDPaginasPriv(this,this,control+1,cantpaginas); }

            for(int j = 1; j < cantpaginas-1; j++){
                if(b->getID() < cantpaginas && b->getID() >= 0){
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

        return checkIDPaginasPriv(this,this,control+1,cantpaginas);

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
