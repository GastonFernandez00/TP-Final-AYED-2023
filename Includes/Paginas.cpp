#include "Paginas.h"
#include "Extras.h"
#include <iostream>
#include <random>
using namespace std;

Pagina::Pagina(){ setTamanio(); setIDDestino(); setidDestinoTerminal();}
Pagina::Pagina(int n){ setTamanio(); setIDDestino(); setidDestinoTerminal();}

Pagina::~Pagina(){ }

void Pagina::setTamanio(){
    random_device rd;
    uniform_int_distribution<int> dist(1,500);
    tamanio = dist(rd); 
}
int& Pagina::getTamanio(){ return tamanio; }

void Pagina::setID(int n){ id_pagina = n; }
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
