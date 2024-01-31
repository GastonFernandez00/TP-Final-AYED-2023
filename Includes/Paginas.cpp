#include "Paginas.h"
#include <iostream>
//#include <stdio.h>
using namespace std;

Pagina::Pagina(){ setTamanio(rand()); setID(rand()); setIDDestino(); setidDestinoTerminal();}
Pagina::Pagina(int n){ setTamanio(n); setID(rand()); setIDDestino(); setidDestinoTerminal();}

Pagina::~Pagina(){ }

void Pagina::setTamanio(int n){ tamanio = n%501; }
int Pagina::getTamanio(){ return tamanio; }

void Pagina::setID(int n){ id_pagina = (rand()%31571)*(n%168); }
int Pagina::getID(){ return id_pagina; }

void Pagina::setIDDestino(int d){ id_Destino = d%256; }

void Pagina::setidDestinoTerminal(int d){ id_Destino_Terminal = d%256; }

void Pagina::setIDDestino(){ id_Destino = rand()%256; }

void Pagina::setidDestinoTerminal(){ id_Destino_Terminal = rand()%256; }

int Pagina::getIDDestino(){ return id_Destino; }

int Pagina::getIDDestinoTerminal(){ return id_Destino_Terminal;}

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
