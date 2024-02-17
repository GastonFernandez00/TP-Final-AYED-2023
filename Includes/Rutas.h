#include <list>
#include "Mapa.h"

class Rutas{
private:


public:

vector<pair<Router*,Router*>> ruta;
void calcularRuta(Mapa*);
void calcRuta(Router*,Router*,int,Mapa*);


};