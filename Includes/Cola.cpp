#include "Cola.h"


Cola::Cola(){ setIDCola(); setIDDestino(); setidDestinoTerminal(); }

Cola::~Cola(){ }

void Cola::setIDCola(){ id_Cola = rand(); }

void Cola::setIDDestino(){ id_Destino = rand(); }

void Cola::setidDestinoTerminal(){ id_Destino_Terminal = rand(); }

void Cola::cambiarEstado(){ (estado == false)? (estado = true):(estado = false);}

void Cola::encolar(int e){ c.push(e); }

void Cola::desencolar(){ c.pop(); }

void Cola::vaciarCola(){
    if(c.size() > 0){
        c.pop();
        return vaciarCola();
    }
    else cout<<"\nCola Vaciada\n";
}

void Cola::imprimirCola(){
    if(c.empty()){ return (void)0; }
    queue<int> aux = c;
    while(aux.size() > 0){
    cout<<aux.front()<<endl;
    aux.pop();
    }
    cout<<endl;
}

queue<int> Cola::getCola(){ return c; }

int Cola::getPrimero(){ return c.front(); }

int Cola::getUltimo(){ return c.back(); }

int Cola::getIDCola(){ return id_Cola; }

int Cola::getIDDestino(){ return id_Destino; }

int Cola::getIDDestinoTerminal(){ return id_Destino_Terminal;}

bool Cola::colaEmpty(){ return c.empty(); }

int Cola::sizeCola(){ return c.size(); }

bool Cola::getEstado(){ return estado; }




/*int main(int argc, char const *argv[])
{
    Cola c;
    cout<<"Encolando:"<<endl;
    for (int i = 0; i < 50; i++){
        c.encolar(rand()%100);
    }
    
    cout<<"IDs:"<<endl;
    cout<<c.getIDCola()<<endl<<c.getIDDestino()<<endl
    <<c.getIDDestinoTerminal()<<endl;
    
    cout<<"Estado:"<<endl;
    cout<<c.getEstado()<<endl;c.cambiarEstado();
    cout<<c.getEstado()<<endl;

    cout<<"Tamanio: "<<c.sizeCola()<<endl<<"Cola: "<<endl;
    c.imprimirCola();

    cout<<"Desencolar 25 items "<<endl;
    for (int i = 0; i < 25; i++){ c.desencolar();}

    cout<<"Cola post desencolar: "<<endl;
    c.imprimirCola();

    cout<<"Valor mas viejo: "<<c.getPrimero()<<endl
    <<"Valor mas nuevo: "<<c.getUltimo()<<endl;

    if(!(c.colaEmpty())){
        c.vaciarCola();
    }
    else{
        cout<<"LA COLA ESTABA VACIA\n";
    }
    
    cout<<"Nuevo tamanio: "<<c.sizeCola()<<endl;

    if(!(c.colaEmpty())){
        c.vaciarCola();
    }
    else{
        cout<<"LA COLA ESTABA VACIA\n";
    }

    return 0;
}
*/