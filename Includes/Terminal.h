#ifndef TERMINAL_H
#define TERMINAL_H
#include "Paginas.h"
#include "Colas.h"
class Terminal{
private:

public:

    Terminal();
    ~Terminal();

    void empaquetado(Pagina *,Cola<int>*);
    void envio(Cola<int>*);

};
#endif