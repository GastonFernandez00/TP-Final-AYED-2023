#include <time.h>
#include "Terminal.h"
#include "Extras.h"
#include <algorithm>

//Compara si una valor es mayor que otro, para luego reordenar el vector de pair<>
auto comparador_t = [](const auto& a, const auto& b) {
        return a.second < b.second;
};
using namespace std;

Terminal::Terminal(){  this->setIDTerminal(); }
Terminal::Terminal(bool b){ determinante = b; if(determinante == 1) this->setIDTerminal();}
Terminal::~Terminal(){}

void Terminal::empaquetado(Pagina &p){
        int numero_de_paquete = 0;

        if(this->getDeterminante() == 1){ //Si el terminal es un receptor, no tiene sentido que pueda empaquetar paginas
            cout<<"[ERROR]: PC RECEPTOR, NO EMISOR";    
            return (void)0;
        }
        
        //Toma en cuenta en cuantos paquetes se va a terminar dividiendo la pagina, 
        //y le da esa informacion a cada paquete
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

        //Crea los paquetes, y va diviviendo la pagina, hasta que esta vacia.
        //Luego envia los paquetes a pkg, para su posterior envio
        for(int i = 0; i < cantidadDeDivisiones; i++){
            numero_de_paquete++;
            Paquete aux;
            if(p.getTamanio() > 50){ aux.setDato(50);}
            else {aux.setDato(p.getTamanio());}
            aux.setIds(&p); aux.setPackNumero(i+1);aux.setCantidadTotal(cantidadDeDivisiones);
            if(p.getTamanio() > 50) p.getTamanio() -= 50;
            else{p.getTamanio() = 0;}
            pkg.push(aux);
        }
}

void Terminal::setDeterminante(bool D){ determinante = D; }

bool Terminal::getDeterminante(){ return determinante; }

void Terminal::setIDTerminal(){// Realmente no importa,  ya que los terminales emisores no se vuelve a tocar
    random_device rd;
    uniform_int_distribution<int> dist(0,MaximaCantDeTerminales-1);
    id_TERMINAL = dist(rd); 
    }

void Terminal::setIDTerminal(int t){ id_TERMINAL = t%MaximaCantDeTerminales; }

// Se usa para comparar si luego en la recepcion es donde corresponden los paquetes
int Terminal::getIDTerminal(){ return id_TERMINAL; }

void Terminal::setMaximaCantDeTerminales(int d){ MaximaCantDeTerminales = d; }

//Llama a la funcion privada 
void Terminal::checkIDTerminal(vector<Terminal> &t){ checkIDTerminalPriv( t,0,t.size()); }

//Revisa que los terminales no repitan ID. Se podría haber hecho simplemente con un setID()
void Terminal::checkIDTerminalPriv(vector<Terminal> &t,int control,int cantTerminales){
    if(t.size() < 2){ return (void)0; }
    if(control == 10){ return (void)0; }
        //Reorganiza los terminales segun id, de nayor a menor
        burbuja_Terminal(&t.at(0),&t.at(0),cantTerminales);

        int veces = 0,contador_a = 0,contador_b = 1;
        //Si alguno de los ID se repite, lo cambia por uno superior
        for(int i = 0; i < t.size()-1; i++){
            for(int j = 1+i; j < t.size(); j++){
                if(t.at(i).getIDTerminal() == t.at(j).getIDTerminal()){
                    veces++;
                    t.at(j).setMaximaCantDeTerminales(t.size());
                    t.at(j).setIDTerminal(t.at(j).getIDTerminal()+veces);
                    }
                }
            veces =0;
        }//Esto se hace 10 veces, para asegurar que no hay repeticiones
        return checkIDTerminalPriv(t,control+1,cantTerminales);
}

queue<Paquete>& Terminal::getPaquetes(){ return pkg; }

void Terminal::recibePaquetes(queue<Paquete> c){ recibidos.push_back(c); }

vector<queue<Paquete>>& Terminal::getPaquetesRecibidos(){ return recibidos; }

void Terminal::rearmarPaginas(queue<Paquete> &p){
    Pagina nueva_p;
    nueva_p.setID(p.front().getIdPertenencia());
    nueva_p.setidDestinoTerminal(p.front().getIDDestinoTerminal());
    nueva_p.setIDDestino(p.front().getIDDestino());

    int tamanio = 0;
    //Mientras la cola tenga paquetes, toma su informacion y se la pasa a la pagina
    //y luego descarta el paquete, para continuar con el que sigue
    while(p.size() > 0){ 
        tamanio += p.front().getDato();
        p.pop();
    }
    nueva_p.getTamanio() = tamanio;
    paginasDisponibles.push_back(nueva_p);
}

void Terminal::getPaginasDisponibles(){
    if(paginasDisponibles.size() <= 0){ cout<<"\nNo hay paginas para mostrar en este terminal"; return (void)0;}
    cout<<"\nLa/s Pagina/s Disponible/s en este Terminal es/son: "<<endl;
    for(int i = 0; i < paginasDisponibles.size();i++){
        cout<<"Paginas "<<i+1<<": "<<paginasDisponibles.at(i).getTamanio()<<" ID-> "<<paginasDisponibles.at(i).getID()<<endl;
    }

}