#ifndef EXTRAS_H
#define EXTRAS_H
#include "Router.h"


int compare (const void * a, const void * b);

void cambio(Router *,Router *);
void cambio(Terminal *, Terminal *);

void burbuja_Router(Router *,Router *,int);
void burbuja_Terminal(Terminal *, Terminal *,int);



#endif 