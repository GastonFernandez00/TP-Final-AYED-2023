#include "Terminal.h"

using namespace std;

Terminal::Terminal(){
    int x = rand()%2;
    determinante = x;
}
Terminal::Terminal(bool b){ determinante = b;}
Terminal::~Terminal(){}

void Terminal::empaquetado(Pagina *p,Cola<int>* c){
        if(this->getDeterminante()){ 
            cout<<"[ERROR]: PC RECEPTOR, NO EMISOR";    
            return (void)0;
        }
        c->setIDCola(p->getID());
        while(p->getTamanio() >= 50){
            c->encolar(50);
            p->setTamanio(p->getTamanio()-50);
        }
        if(p->getTamanio() < 50 && p->getTamanio() > 0){
            c->encolar(p->getTamanio());
            p->setTamanio(0);
        }
}

bool Terminal::getDeterminante(){ return determinante; }

void Terminal::envio(Cola<int>* c/*, int id_Router*/){
    //id_Router podria ser ingresado por usuario, mejor si no.
    int id_Router = rand()%256;
    int id_destino_terminal = rand()%256;
    c->cambiarEstado();
    c->setIDDestino(id_Router); 
    c->setidDestinoTerminal(id_destino_terminal);   
}

/*int main(int argc, char const *argv[])
{
    Cola<int> cEnvio[128],cRecibido[128];
    Pagina p[100];
    Terminal t[10];

    

   


    

    /*for(int i = 0; i < size(p); i++){
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

    return 0;
}*/

