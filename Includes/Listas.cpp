
//#include "Nodos.hpp"
#include "Listas.h"



template <class T>
Lista<T>::Lista(){ czo = new Nodo<T>();}

template <class T>
Lista<T>::Lista(Nodo<T>* n){ czo = n; }

template <class T>
Lista<T>::~Lista(){}

template <class T>
void Lista<T>::add(T a){
    Nodo<T>* nuevo = new Nodo<T>(a);
    nuevo->setNext(czo);
    czo = nuevo;
}

template <class T>
int Lista<T>::size(){ return pSize(czo); }

template <class T>
int Lista<T>::pSize(Nodo<T>* inicio){
    if(inicio->getNext() != NULL){
        return 1+pSize(inicio->getNext());
    }
}

template <class T>
T Lista<T>::cabeza(){ return czo->getDato(); }

template <class T>
bool Lista<T>::isEmpty(){ return czo->nodoIsEmpty(); }

template <class T>
Lista<T>* Lista<T>::resto(){ Lista<T> *l = new Lista<T>(czo->getNext()); return l; }

template <class T>
void Lista<T>::printLista(){ imprimirLista(czo); }

template <class T>
void Lista<T>::imprimirLista(Nodo<T>* inicio){
    if(!this->isEmpty()){
        if(inicio->getNext() != NULL){
        cout<<inicio->getDato()<<endl;
        imprimirLista(inicio->getNext());
        }
    }
    else{
        cout<<"\n[ERROR]: LISTA VACIA\n";
    }
}

template <class T>
string Lista<T>::toPrint(string p){
    if (this->isEmpty()) {
        return p;
    }
    else {
        //std::ostringstream stm;
        ostringstream stm;
        stm << this->cabeza() << "-" << this->resto()->toPrint(p) << endl;
        //cout<<endl<<" stm.str()= "<<stm.str()<<endl;
        return stm.str();
    }
}

template <class T>
bool Lista<T>::esta(T a){ checkDato(a,czo); }

template <class T>
bool Lista<T>::checkDato(T a,Nodo<T>* inicio){
    
    if(inicio->getDato() != a && inicio->getNext() == NULL){
        return false;
    }

    else if(inicio->getDato() != a && inicio->getNext() != NULL){
         return checkDato(a,inicio->getNext());
    }
    
    else{ return true;}
}

template <class T>
void Lista<T>::borrarDato(T a){ borrarDatop(a,czo,NULL); }/*{
    Nodo<T>* actual = czo, anterior = NULL;
    while(actual->getNext() != NULL){
        if(actual->getDato() == dato){
            
        }
        else{
            anterior = actual; actual = actual->getNext();
        }
    }

}*/

template <class T>
void Lista<T>::borrarDatop(T dato,Nodo<T>* inicio,Nodo<T>* anterior){
    
    if(inicio->getDato() != dato && inicio->getNext() == NULL){
        cout<<"\nNo se puede encontrar el dato '"<<dato<<"' en la lista\n";
    }

    else if(inicio->getDato() != dato && inicio->getNext() != NULL){
        borrarDatop(dato,inicio->getNext(),inicio);
    }

    else{
        if(anterior == NULL){ czo = czo->getNext(); }
        else { anterior->setNext(inicio->getNext()); }
    }
}

template <class T>
void Lista<T>::borrarCabeza(){ if(!this->isEmpty()) czo = czo->getNext(); }

template <class T>
void Lista<T>::borrarLast(){ borrarLastp(czo,NULL); }

template <class T>
void Lista<T>::borrarLastp(Nodo<T>* inicio,Nodo<T>* anterior){
    if(inicio->getNext() != NULL){ return borrarLastp(inicio->getNext(),inicio); }
    else{
        if(anterior != NULL){ anterior->setNext(NULL); }
        else{ delete czo; }
    }
}

template <class T> 
void Lista<T>::concat(Lista<T>* l1){
    // le transfiere los datos de l1 a this
    if (!(l1->isEmpty())) {
        this->concat(l1->resto());
        this->add(l1->cabeza());
    }
}

template <class T>
Lista<T>* Lista<T>::copy(void){
    Lista<T>* aux = new Lista();
    aux->concat(this);
    return aux;
}

template <class T>
void Lista<T>::tomar(int n){
    if(this->size()>n){
        this->borrarLast();
        return tomar(n);
    }
}

template <class T>
T Lista<T>::last(){ return lastp(czo,NULL); }

template <class T>
T Lista<T>::lastp(Nodo<T>* inicio,Nodo<T>* anterior){
    if(!this->isEmpty()){
        if(inicio->getNext() != NULL){ lastp(inicio->getNext(),inicio); }
        else{
            if(anterior == NULL){ return czo->getDato(); }
            else{ return anterior->getDato();}
        }
    }
}

/*template <class T>
Lista<T>::*/


template class Lista<int>;
template class Lista<float>;
template class Nodo<double>;
template class Nodo<char>;
template class Nodo<string>;