#include "Paquete.h"

Paquete::Paquete(){}

Paquete::~Paquete(){}

void Paquete::setIdPertenencia(int n){ idPertenencia = n; }

void Paquete::setPackNumero(int n){ packNumero = n; }

void Paquete::setDato(int d){ DATO = d; }

int Paquete::getIdPertenencia(){ return idPertenencia; }

int Paquete::getPackNumero(){ return packNumero; }

int Paquete::getDato(){ return (DATO > 0)? DATO:-1; }