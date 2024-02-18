#include "Paquete.h"
#include <vector>

Paquete::Paquete(){}

Paquete::~Paquete(){}

void Paquete::setIds(Pagina *p){ 
    idPertenencia = p->getID();
    id_Destino = p->getIDDestino();
    id_Destino_Terminal = p->getIDDestinoTerminal();    
}

void Paquete::setPackNumero(int n){ packNumero = n; }

void Paquete::setCantidadTotal(int n) { Divisiones_Totales = n; }

void Paquete::setDato(int d){ DATO = d; }

int Paquete::getIdPertenencia(){ return idPertenencia; }

int Paquete::getIDDestino(){ return id_Destino; }

int Paquete::getIDDestinoTerminal(){ return id_Destino_Terminal;}

int Paquete::getPackNumero(){ return packNumero; }

int Paquete::getDivisionesTotales(){ return Divisiones_Totales; }

int Paquete::getDato(){ return (DATO > 0)? DATO:-1; }

// int main(int argc, char const *argv[])
// {
//     Pagina p[10];
//     Paquete *P;
//     vector<Paquete*> v;
//     for(int i = 0; i < size(p); i++){ v.push_back(new Paquete);}
    
//     cout<<v.at(0)->getIdPertenencia();

//     return 0;
// }
