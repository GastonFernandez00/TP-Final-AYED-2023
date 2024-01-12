#include "Terminal.h"

using namespace std;

Terminal::Terminal(){}
Terminal::~Terminal(){}

void Terminal::empaquetado(Pagina *p,Cola<int>* c){
        while(p->getTamanio() >= 50){
            c->encolar(50);
            p->setTamanio(p->getTamanio()-50);
        }
        if(p->getTamanio() < 50 && p->getTamanio() > 0){
            c->encolar(p->getTamanio());
            p->setTamanio(0);
        }
}



int main(int argc, char const *argv[])
{
    Cola<int> c[256];
    Pagina p[100];
    Terminal t;

    for(int i = 0; i < size(p); i++){
        t.empaquetado(&p[i],&c[i]);
    }

    for(int i = 0; i < size(c); i++){
        if(!(c[i].colaEmpty())) 
        cout<<"Cola N"<<i+1<<" -> "<<c[i].sizeCola()<<endl; 
    }

    for(int i = 0; i < size(c); i++){
        if(!(c[i].colaEmpty())){
        cout<<"Cola N"<<i+1<<"\n";
        c[i].printCola();
        cout<<"\n----------\n";
        } 
    }

    //p->setTamanio(143);
    /*Terminal t;

    t.empaquetado(&p[0],&c[0]);

    c->printCola();

    cout<<endl<<endl<<c->sizeCola();
*/
    return 0;
}

