#include <time.h>
#include "Terminal.h"
#include "Extras.h"
#include <algorithm>
auto comparador_t = [](const auto& a, const auto& b) {
        return a.second < b.second;
};
using namespace std;

Terminal::Terminal(){  this->setIDTerminal(); }
Terminal::Terminal(bool b){ determinante = b; if(determinante == 1) this->setIDTerminal();}
Terminal::~Terminal(){}

void Terminal::empaquetado(Pagina &p){
        // cout<<"Entro\n";
        // int veces = 0;
        int numero_de_paquete = 0;

        if(this->getDeterminante() == 1){ 
            cout<<"[ERROR]: PC RECEPTOR, NO EMISOR";    
            return (void)0;
        }
        
        int pAux = p.getTamanio();
        int cantidadDeDivisiones = 0;
        while( pAux >= 50){
            cantidadDeDivisiones++;
            pAux -= 50;
        }
        if(pAux > 0){
            cantidadDeDivisiones++;
            pAux = 0;
        }

        for(int i = 0; i < cantidadDeDivisiones; i++){
            // veces++;
            numero_de_paquete++;
            Paquete aux;
            if(p.getTamanio() > 50){ aux.setDato(50);}
            else {aux.setDato(p.getTamanio());}
            aux.setIds(&p); aux.setPackNumero(i+1);aux.setCantidadTotal(cantidadDeDivisiones);
            if(p.getTamanio() > 50) p.getTamanio() -= 50;
            else{p.getTamanio() = 0;}
            pkg.push(aux);
        }
        // while(p.getTamanio() >= 50){
        //     veces++;
        //     numero_de_paquete++;
        //     Paquete aux;
        //     aux.setDato(50);aux.setIds(&p); aux.setPackNumero(numero_de_paquete);
        //     aux.setCantidadTotal(cantidadDeDivisiones);
        //     int nuevo_tamanio = p.getTamanio()-50;
        //     p.setTamanio(nuevo_tamanio);
        //     pkg.push(aux);
        // }
        // if(p.getTamanio() < 50 && p.getTamanio() > 0){
        //     veces++;
        //     numero_de_paquete++;
        //     Paquete aux;
        //     aux.setIds(&p); aux.setPackNumero(numero_de_paquete);
        //     aux.setDato(p.getTamanio()); aux.setCantidadTotal(cantidadDeDivisiones);
        //     p.setTamanio(0);
        //     pkg.push(aux);
        // }

        // cout<<"Veces que creo paquetes: "<<veces<<endl;
}

void Terminal::setDeterminante(bool D){ determinante = D; }

bool Terminal::getDeterminante(){ return determinante; }

queue<Paquete> Terminal::envio(){
    cout<<"No implementado, funcion vieja";
    queue<Paquete> p;
    return p;
    // pkg.cambiarEstado();
    // return this->getPaquetes();
    // //id_Router podria ser ingresado por usuario, mejor si no.
    // int id_Router = rand()%256;
    // int id_destino_terminal = rand()%256;
    // c->cambiarEstado();
    // c->setIDDestino(id_Router); 
    // c->setidDestinoTerminal(id_destino_terminal);   
}

void Terminal::setIDTerminal(){
    random_device rd;
    uniform_int_distribution<int> dist(0,MaximaCantDeTerminales-1);
    id_TERMINAL = dist(rd); 
    }

void Terminal::setIDTerminal(int t){ id_TERMINAL = t%MaximaCantDeTerminales; }

int Terminal::getIDTerminal(){ return id_TERMINAL; }

void Terminal::setMaximaCantDeTerminales(int d){ MaximaCantDeTerminales = d; }

void Terminal::checkIDTerminal(vector<Terminal> &t){ checkIDTerminalPriv( t,0,t.size()); }

void Terminal::checkIDTerminalPriv(vector<Terminal> &t,int control,int cantTerminales){
    if(t.size() < 2){ return (void)0; }
    if(control == 10){ return (void)0; }

        burbuja_Terminal(&t.at(0),&t.at(0),cantTerminales);
        // qsort(&t.at(0),t.size(),sizeof(Terminal),compare);
        
        int veces = 0,contador_a = 0,contador_b = 1;

        for(int i = 0; i < t.size()-1; i++){
            for(int j = 1+i; j < t.size(); j++){
                // if(cantdeRouters != 0){b->getIDRouter();}
                if(t.at(i).getIDTerminal() == t.at(j).getIDTerminal()){
                    veces++;
                    t.at(j).setMaximaCantDeTerminales(t.size());
                    t.at(j).setIDTerminal(t.at(j).getIDTerminal()+veces);
                    }
                }
            
            veces =0;
        }
        //cout<<"\nReingresa Check";
        return checkIDTerminalPriv(t,control+1,cantTerminales);
        
}

queue<Paquete>& Terminal::getPaquetes(){ return pkg; }

void Terminal::recibePaquetes(queue<Paquete> c){ recibidos.push_back(c); }

vector<queue<Paquete>>& Terminal::getPaquetesRecibidos(){ return recibidos; }

void Terminal::rearmarPaginas(queue<Paquete> &p){
    vector<pair<Paquete,int>> c;
    for(int i = 0; i < p.size(); i++)
    {c.push_back(pair<Paquete,int>(p.front(),p.front().getPackNumero()));}
    sort(c.begin(),c.end(),comparador_t);
    int tamanio = 0;
    for(int i = 0; i < c.size(); i++){
        tamanio += c.at(i).first.getDato();
    }
    Pagina nueva_p(tamanio);
    paginasDisponibles.push_back(nueva_p);
}

void Terminal::getPaginasDisponibles(){
    if(paginasDisponibles.size() <= 0){ cout<<"\nNo hay paginas para mostrar en este terminal"; return (void)0;}
    cout<<"\nLa/s Pagina/s Disponible/s en este Terminal es/son: "<<endl;
    for(int i = 0; i < paginasDisponibles.size();i++){
        cout<<"Paginas "<<i+1<<": "<<paginasDisponibles.at(i).getTamanio()<<endl;
    }

}

//Terminal crearTerminal(){ Terminal t; return t;} SOLO PARA TESTING

/*int main(int argc, char const *argv[]){
    

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

}*/

