#ifndef EXTRAS_H
#define EXTRAS_H
//#include "Router.h"
#include "Router.h"


int compare (const void * a, const void * b);

void cambio(Router *,Router *);
void cambio(Terminal *, Terminal *);
void cambio(Pagina *, Pagina *);

void burbuja_Router(Router *,Router *,int);
void burbuja_Terminal(Terminal *, Terminal *,int);
void burbuja_Pagina(Pagina *, Pagina *,int);



#endif 