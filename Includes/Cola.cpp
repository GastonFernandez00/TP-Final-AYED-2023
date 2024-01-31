#include "Cola.h"

template <class T>
Cola<T>::Cola(){ setIDCola(); }

template <class T>
Cola<T>::~Cola(){ }

template <class T>
void Cola<T>::setIDCola(){ id_Cola = rand(); }

template <class T>
void Cola<T>::setIDCola(int d){ id_Cola = d; }

template <class T>
void Cola<T>::cambiarEstado(){ (estado == false)? (estado = true):(estado = false);}

template <class T>
void Cola<T>::encolar(T e){ c.push(e); }

template <class T>
void Cola<T>::desencolar(){ c.pop(); }

template <class T>
void Cola<T>::vaciarCola(){
    if(c.size() > 0){
        c.pop();
        return vaciarCola();
    }
    else cout<<"\nCola Vaciada\n";
}

template <class T>
void Cola<T>::imprimirCola(){
    cout<<-1;
    // if(c.empty()){ return (void)0; }
    // queue<T> aux = c;
    // while(aux.size() > 0){
    // cout<<aux.front()<<endl;
    // aux.pop();
    // }
    // cout<<endl;
}

template <class T>
queue<T> Cola<T>::getCola(){ return c; }

template <class T>
T Cola<T>::getPrimero(){ return c.front(); }

template <class T>
T Cola<T>::getUltimo(){ return c.back(); }

template <class T>
int Cola<T>::getIDCola(){ return id_Cola; }

template <class T>
bool Cola<T>::colaEmpty(){ return c.empty(); }

template <class T>
int Cola<T>::sizeCola(){ return c.size(); }

template <class T>
bool Cola<T>::getEstado(){ return estado; }

template class Cola<int>;
template class Cola<Cola<int>*>;
template class Cola<float>;
template class Cola<double>;
template class Cola<char>;
template class Cola<string>;
template class Cola<Paquete>;


///////////////////PRUEBA DE FUNCIONES
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