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

void Terminal::envio(Cola<int>* c/*, int id_Router*/){
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

        for(int i = 0; i < cantTerminales; i ++){
            cout<<a->getIDTerminal()<<" ";
            if((i+1)%10 == 0) cout<<endl;
            a++;
        }

        cout<<endl<<endl<<endl<<endl<<endl;
        // b++;int veces = 0;
        // for(int i = 0; i < cantTerminales; i++){
            
        //     if(a->getIDTerminal() > cantTerminales || a->getIDTerminal() < 0){ return checkIDTerminalPriv(this,this,control+1,cantTerminales); }

        //     for(int j = 1; j < cantTerminales-1; j++){
        //         if(b->getIDTerminal() < cantTerminales && b->getIDTerminal() >= 0){
        //             if(a->getIDTerminal() == b->getIDTerminal()){
        //                 b->setMaximaCantDeTerminales(cantTerminales);
        //                 veces+=1;
        //                 b->setIDTerminal(b->getIDTerminal()+veces);
        //             }    
        //             b++;
        //         }

        //     }

        //     a++;b = a; b++; veces = 0;
        // }
        // return checkIDTerminalPriv(this,this,control+1,cantTerminales);
        

}

Cola<Paquete> Terminal::getPaquetes(){ return pkg; }

Terminal crearTerminal(){ Terminal t; return t;}

int main(int argc, char const *argv[]){
    
    int numero_de_terminales = rand()%256;
    vector<Terminal> t;
    for(int i= 0; i < numero_de_terminales; i++){t.push_back(crearTerminal());}
    t.at(0).checkIDTerminal(t.size());
    for(int i = 0; i < t.size(); i++){
        cout<<t.at(i).getIDTerminal()<<" ";
        if((i+1)%10 == 0) cout<<endl;
    }

    cout<<endl<<endl;
    int contador = 0;
    for(int i = 0; i < numero_de_terminales-1; i++){
        for(int j = 1+i; j < numero_de_terminales; j++ ){
            if(t.at(i).getIDTerminal() == t.at(j).getIDTerminal()){ contador++;cout<<t.at(j).getIDTerminal()<<" ";}
        }
    }
    cout<<"\n\nRepetidos: "<<contador<<endl;
    

//     //PRUEBA PAGINAS / TERMINAL -> EMPAQUETADO
//     int tamanio = 4861;
//     Pagina p[tamanio];
//     Terminal t;
//     //vector<Paquete> pkg;
//     for(int i = 0; i < tamanio; i ++ ){ t.empaquetado(&p[i]);}
//     //t.empaquetado(p,&pkg);
//     Cola<Paquete> pkg = t.getPaquetes();

//     p->checkIDPaginas(tamanio);
//     for(int i= 0; i < tamanio; i++){
//         cout<<p[i].getID()<<" ";
//         if((i+1)%10 == 0) cout<<endl;
//     }
//     cout<<endl<<endl;
//     int contador = 0;
//     for(int i = 0; i < tamanio-1; i++){
//         for(int j = 1+i; j < tamanio; j++ ){
//             if(p[i].getID() == p[j].getID()){ contador++;cout<<p[j].getID()<<" ";}
//         }
//     }
//     cout<<"\n\nRepetidos: "<<contador<<endl;

    
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

