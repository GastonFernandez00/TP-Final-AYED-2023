#include "Terminal.h"
#include "Extras.h"
using namespace std;

Terminal::Terminal(){
    // int x = rand()%2;
    // determinante = x;
    this->setIDTerminal();
}
Terminal::Terminal(bool b){ determinante = b; if(determinante == 1) this->setIDTerminal();}
Terminal::~Terminal(){}

void Terminal::empaquetado(Pagina *p,Cola<Paquete> *pak){
        int numero_de_paquete = 0;

        if(this->getDeterminante() == 1){ 
            cout<<"[ERROR]: PC RECEPTOR, NO EMISOR";    
            return (void)0;
        }
        
        while(p->getTamanio() >= 50){
            numero_de_paquete++;
            Paquete aux;
            aux.setDato(50);aux.setIds(p); aux.setPackNumero(numero_de_paquete);
            p->setTamanio(p->getTamanio()-50);
            pkg.encolar(aux);
        }
        if(p->getTamanio() < 50 && p->getTamanio() > 0){
            numero_de_paquete++;
            Paquete aux;
            aux.setIds(p); aux.setPackNumero(numero_de_paquete);
            aux.setDato(p->getTamanio());
            p->setTamanio(0);
            pkg.encolar(aux);
        }
}

void Terminal::setDeterminante(bool D){ determinante = D; }

bool Terminal::getDeterminante(){ return determinante; }

void Terminal::envio(Cola<int>* c/*, int id_Router*/){
    // //id_Router podria ser ingresado por usuario, mejor si no.
    // int id_Router = rand()%256;
    // int id_destino_terminal = rand()%256;
    // c->cambiarEstado();
    // c->setIDDestino(id_Router); 
    // c->setidDestinoTerminal(id_destino_terminal);   
}

void Terminal::setIDTerminal(){ id_TERMINAL = rand()%256; }

void Terminal::setIDTerminal(int t){ id_TERMINAL = t%256; }

int Terminal::getIDTerminal(){ return id_TERMINAL; }

void Terminal::checkIDTerminal(){ checkIDTerminalPriv(this,this,0); }

void Terminal::checkIDTerminalPriv(Terminal *a, Terminal *b,int control){
    if(control == 5){ return (void)0; }

    //for(int i = 0; i < 10; i++){
        burbuja_Terminal(a,b);
        //b++;
        //cambio_Prueba(a,b);
    //}

        b++;int veces = 0;
        for(int i = 0; i < 256; i++){
            
            if(a->getIDTerminal() > 256 || a->getIDTerminal() < 0){ return (void)0; }

            for(int j = 1; j < 256-1; j++){
                if(b->getIDTerminal() < 256 && b->getIDTerminal() >= 0){
                    if(a->getIDTerminal() == b->getIDTerminal()){
                        veces+=1;
                        b->setIDTerminal(b->getIDTerminal()+veces);
                    }    
                    b++;
                }

            }

            a++;b = a; b++; veces = 0;
        }

        checkIDTerminalPriv(this,this,control+1);
//    }
}

Cola<Paquete> Terminal::getPaquetes(){ return pkg; }

int main(int argc, char const *argv[])
{
    Pagina p[100];
    Cola<Paquete> pak;
    Terminal t;
    //vector<Paquete> pkg;
    for(int i = 0; i < size(p); i ++ ){ t.empaquetado(&p[i],&pak);}
    //t.empaquetado(p,&pkg);
    Cola<Paquete> pkg = t.getPaquetes();
    
    while(pkg.sizeCola() > 0 && pkg.getPrimero().getIdPertenencia() != pkg.getUltimo().getIdPertenencia()){
    cout<<"Tamanio: "<<pkg.sizeCola()<<endl;
    cout<<"Dato: "<<pkg.getPrimero().getDato()<<endl;
    cout<<"Ultimo Dato: "<<pkg.getUltimo().getDato()<<endl;
    cout<<"ID destino: "<<pkg.getPrimero().getIDDestino()<<endl;
    cout<<"ID destino final: "<<pkg.getPrimero().getIDDestinoTerminal()<<endl;
    cout<<"ID de pertenencia: "<<pkg.getPrimero().getIdPertenencia()<<endl;
    
    cout<<"ID destino: "<<pkg.getUltimo().getIDDestino()<<endl;
    cout<<"ID destino final: "<<pkg.getUltimo().getIDDestinoTerminal()<<endl;
    cout<<"ID de pertenencia: "<<pkg.getUltimo().getIdPertenencia()<<endl;


    cout<<"Descolando: "<<endl;pkg.desencolar();
    cout<<"--------------------------------------------------\n";
    if(pkg.getPrimero().getIdPertenencia() == pkg.getUltimo().getIdPertenencia()){
        cout<<"\n--------------------------------------------------\nHUBO MATCH\n";
    }

    // int Espera = 0;
    // while(Espera == 0){
    //     cout<<"Para continuar presione cualquier numero: ";cin>>Espera;
    // }

}
    pkg.vaciarCola();
    cout<<"Tamanio: "<<pkg.sizeCola()<<endl;

            
    cout<<"--------------------------------------------------\n";

}

