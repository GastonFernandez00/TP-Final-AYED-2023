#include <time.h>
#include "Terminal.h"
#include "Extras.h"
using namespace std;

Terminal::Terminal(){  this->setIDTerminal(); }
Terminal::Terminal(bool b){ determinante = b; if(determinante == 1) this->setIDTerminal();}
Terminal::~Terminal(){}

void Terminal::empaquetado(Pagina *p){
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

Cola<Paquete> Terminal::envio(){
    // pkg.cambiarEstado();
    // return this->getPaquetes();
    // //id_Router podria ser ingresado por usuario, mejor si no.
    // int id_Router = rand()%256;
    // int id_destino_terminal = rand()%256;
    // c->cambiarEstado();
    // c->setIDDestino(id_Router); 
    // c->setidDestinoTerminal(id_destino_terminal);   
}

void Terminal::setIDTerminal(){ id_TERMINAL = rand()%MaximaCantDeTerminales; }

void Terminal::setIDTerminal(int t){ id_TERMINAL = t%MaximaCantDeTerminales; }

int Terminal::getIDTerminal(){ return id_TERMINAL; }

void Terminal::setMaximaCantDeTerminales(int d){ MaximaCantDeTerminales = d; }

void Terminal::checkIDTerminal(int n){ checkIDTerminalPriv(this,this,0,n); }

void Terminal::checkIDTerminalPriv(Terminal *a, Terminal *b,int control,int cantTerminales){
    if(control == 10){ return (void)0; }

        burbuja_Terminal(a,b,cantTerminales);
        
        b++; int veces = 0,contador_a = 0,contador_b = 1;

        for(int i = 0; i < cantTerminales-1; i++){// 0 -> n-1
                       
            for(int j = 1; j < cantTerminales; j++){//    1 -> n

                if( contador_b < cantTerminales && b->getIDTerminal() >= 0){

                    if( a->getIDTerminal() == b->getIDTerminal()){ 
                        b->setMaximaCantDeTerminales(cantTerminales);
                        veces++;
                        b->setIDTerminal(b->getIDTerminal()+veces);
                    }
                    b++;contador_b++;
                }
            }

            a++; b = a; b++; veces = 0; contador_a++;contador_b = 1;
        }
        return checkIDTerminalPriv(this,this,control+1,cantTerminales);
        
}

Cola<Paquete> Terminal::getPaquetes(){ return pkg; }

Terminal crearTerminal(){ Terminal t; return t;}

int main(int argc, char const *argv[]){
    

    //PRUEBA CREACION DE PAGINA, TERMINAL, Y RECEPCION
    // int cantPaginas = (rand()*time(nullptr))%1024;
    // Pagina p[cantPaginas];
    // p->checkIDPaginas(cantPaginas);

    // int tamanioTerminal = (rand()*time(nullptr))%256;
    // vector<Terminal> t;
    // for(int i = 0; i < tamanioTerminal; i++) t.push_back(crearTerminal());
    // t.at(0).checkIDTerminal(t.size());

    // for(int i = 0; i < t.size(); i++){
    //     for(int j = 0; j < cantPaginas/256; j++){
    //         t.at(i).empaquetado(&p[j]);
    //     }
    // }

    // Cola<Paquete> Recibidos[tamanioTerminal];
    // for(int i = 0; i < tamanioTerminal; i++){
    //     Recibidos[i] = t.at(i).getPaquetes();
    // }
       
    //PRUEBA CHECK TERMINALES
    // int numero_de_terminales = (rand()*time(nullptr))%256;
    // vector<Terminal> t;
    // for(int i= 0; i < numero_de_terminales; i++){t.push_back(crearTerminal());}
    // t.at(0).checkIDTerminal(t.size());
    // for(int i = 0; i < t.size(); i++){
    //     cout<<t.at(i).getIDTerminal()<<" ";
    //     if((i+1)%10 == 0) cout<<endl;
    // }

    // cout<<endl<<endl;
    // int contadorter = 0;
    // for(int i = 0; i < numero_de_terminales-1; i++){
    //     for(int j = 1+i; j < numero_de_terminales; j++ ){
    //         if(t.at(i).getIDTerminal() == t.at(j).getIDTerminal()){ contadorter++;cout<<t.at(j).getIDTerminal()<<" ";}
    //     }
    // }
    // cout<<"\n\nRepetidos: "<<contadorter<<endl;
    

//     //PRUEBA PAGINAS / TERMINAL -> EMPAQUETADO
    // int tamanio = (time(NULL)*rand())%5000;
    // Pagina p[tamanio];
    
    // //vector<Paquete> pkg;
    // for(int i = 0; i < tamanio; i ++ ){ t.at(0).empaquetado(&p[i]); }
    // //t.empaquetado(p,&pkg);
    // Cola<Paquete> pkg = t.at(0).getPaquetes();

    // p->checkIDPaginas(tamanio);
    // for(int i= 0; i < tamanio; i++){
    //     cout<<p[i].getID()<<" ";
    //     if((i+1)%10 == 0) cout<<endl;
    // }
    // cout<<endl<<endl;
    // int contador = 0;
    // for(int i = 0; i < tamanio-1; i++){
    //     for(int j = 1+i; j < tamanio; j++ ){
    //         if(p[i].getID() == p[j].getID()){ contador++;cout<<p[j].getID()<<" ";}
    //     }
    // }
    // cout<<"\n\nRepetidos: "<<contador<<endl;

    
//     while(pkg.sizeCola() > 0 ){
//     cout<<"\n--------------------------------------------------\n";
//     cout<<"Tamanio: "<<pkg.sizeCola()<<endl;
//     cout<<"Dato: "<<pkg.getPrimero().getDato()<<endl;
//     //cout<<"Ultimo Dato: "<<pkg.getUltimo().getDato()<<endl;
//     //cout<<"ID destino: "<<pkg.getPrimero().getIDDestino()<<endl;
//     //cout<<"ID destino final: "<<pkg.getPrimero().getIDDestinoTerminal()<<endl;
//     cout<<"ID de pertenencia: "<<pkg.getPrimero().getIdPertenencia();
    
//     // cout<<"ID destino: "<<pkg.getUltimo().getIDDestino()<<endl;
//     // cout<<"ID destino final: "<<pkg.getUltimo().getIDDestinoTerminal()<<endl;
//     // cout<<"ID de pertenencia: "<<pkg.getUltimo().getIdPertenencia()<<endl;


//     pkg.desencolar();
//     // cout<<"--------------------------------------------------\n";
//     // if(pkg.getPrimero().getIdPertenencia() == pkg.getUltimo().getIdPertenencia()){
//     //     cout<<"\n--------------------------------------------------\nHUBO REPETIDO\n";
//     // }

//     // int Espera = 0;
//     // while(Espera == 0){
//     //     cout<<"Para continuar presione cualquier numero: ";cin>>Espera;
//     // }

// }
//     pkg.vaciarCola();
//     cout<<"Tamanio: "<<pkg.sizeCola()<<endl;

            
//     cout<<"\n--------------------------------------------------\n";

}

