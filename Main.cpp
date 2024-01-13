#include <iostream>
#include "Terminal.h"
using namespace std;

int crearPaginas();

int main(int argc, char const *argv[])
{
    int tamaniop = crearPaginas();
    Pagina p[tamaniop];

    for(int i = 0; i < tamaniop; i++){
        cout<<p[i].getTamanio()<<endl;
    }


    return 0;
}
int crearPaginas(){
    int i = 1;
    cout<<"Cuantas paginas se quieren enviar por PC?"
        <<"(El maximo es 256)\nIngresar cantidad: \n";
    cin>>i;
    return i;
}
