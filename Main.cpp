#include <iostream>
#include <time.h>
#include "./Includes/Mapa.h"
using namespace std;

int getRandID(vector<Router> r){
    return r.at((int)(time(nullptr)*rand())%r.size()).getIDRouter();
}


void getCoords(int buscar,Mapa m){
    for(int i = 0; i < m.getMapa().size(); i++)
        for(int j = 0; j < m.getMapa().size(); j++)
            if(m.getMapa().at(i).at(j).getIDRouter() == buscar){
                m.getMapa().at(i).at(j).printPosicionRouter();
                return (void)0;
            }
            cout<<"\nEl Router "<<buscar<<" No existe."<<endl;
}

void getCercanoss(int buscar, Mapa m){
    for(int i = 0; i < m.getMapa().size(); i++)
        for(int j = 0; j < m.getMapa().size(); j++)
            if(m.getMapa().at(i).at(j).getIDRouter() == buscar){
                for(int k = 0; k < 8; k++)
                cout<<endl<<m.getMapa().at(i).at(j).getCercanos().at(k)->getIDRouter();
                cout<<endl;
                return (void)0;
            }
            cout<<"\nEl Router "<<buscar<<" No existe."<<endl;
}

void getPackRedir(int b, Mapa m){
     for(int i = 0; i < m.getMapa().size(); i++)
        for(int j = 0; j < m.getMapa().size(); j++)
            if(m.getMapa().at(i).at(j).getIDRouter() == b){
                cout<<"\nEl total de paquetes a redireccionar son: "<<m.getMapa().at(i).at(j).getSizeBufferRedireccionamiento();
                return (void)0;
            }
            cout<<"\nEl Router "<<b<<" No existe."<<endl;
}

void getPackNORedir(int b, Mapa m){
    for(int i = 0; i < m.getMapa().size(); i++)
        for(int j = 0; j < m.getMapa().size(); j++)
            if(m.getMapa().at(i).at(j).getIDRouter() == b){
                cout<<"\nEl total de paquetes a son: "<<m.getMapa().at(i).at(j).getSizeBuffer();
                return (void)0;
            }
            cout<<"\nEl Router "<<b<<" No existe."<<endl;
}

int main(int argc, char const *argv[])
{
NuevoMapa:
    Pagina p[1000];
    p->checkIDPaginas(size(p));
    int cantRouters, cantEmisores;
    cantRouters = cantEmisores = 1+(time(nullptr)*rand())%256;
    vector<Router> r; vector<Terminal> t;
    for(int i = 0; i < cantRouters; i++){ 
        Router nuevo_r; r.push_back(nuevo_r);
        Terminal nuevo_t; t.push_back(nuevo_t);
    }
    r.at(0).checkIDRouter(r);
    t.at(0).checkIDTerminal(t);

    for(int i = 0; i < size(p); i++){
        p[i].setIDDestino(getRandID(r));
    }

    //EMPAQUETA LAS PAGINAS
    for(int j = 0; j < t.size(); j++)
        for(int i = 0+(size(p)/t.size())*j; i < (1+j)*(size(p)/t.size()); i++){
            t.at(j).empaquetado(&p[i]);
        }

    //ENVIA LAS PAGINAS A ROUTERS
    for(int j = 0; j < t.size(); j++){
        r.at(j).Recepcion(t.at(j).getPaquetes());
    }


    Mapa m(20);
    for(int i = 0; i < cantRouters; i++) m.incluirEnMapa(r.at(i));
    m.setCercanos();

    int opcion = 0;
    do{
        cout<<"\nOpciones: "
        <<"\n1) Imprimir mapa"
        <<"\n2) Routers activos"
        <<"\n3) Routers cercanos a uno especifico"
        <<"\n4) Coordenadas de un Router especifico"
        <<"\n5) Paquetes a redireccionar de un Router especifico"
        <<"\n6) Paquetes que no deben ser redireccionados de un Router especifico"
        <<"\n7) Mapa Nuevo"
        <<"\n8) Salir"
        <<"\n\nIngresar Opcion: ";cin>>opcion;

        while(opcion > 8 || opcion < 1){
            cout<<"\nERROR: Reingresar Opcion: "; cin>>opcion;
        }
        switch(opcion){
            case 1:
                m.imprimirMapa(); break;
            case 2:
                cout<<"\nCantidad de Routers Activos: "<<m.cantidadDeRoutersEnMapa()<<endl; break;
            case 3:{
                int buscar = -1;
                cout<<"\nIngresar Router a buscar Cercanos: ";cin>>buscar;
                getCercanoss(buscar, m);                
                break;}
            case 4:{
                int buscar = -1;
                cout<<"\nIngresar Router a Buscar: ";cin>>buscar;
                getCoords(buscar,m);
                break;}
            case 5:{
                int buscar = -1;
                cout<<"\nIngresar Router a buscar Paquetes de Redireccion: ";cin>>buscar;
                getPackRedir(buscar,m);                
                break;}
            case 6:{
                int buscar = -1;
                cout<<"\nIngresar Router a buscar Paquetes :";cin>>buscar;
                getPackNORedir(buscar,m);    
                break;}
            
            case 7:
                goto NuevoMapa;
                break;
        }
        // <<"\n"
        // <<"\n"<<endl;
        
        
    }while(opcion != 8);
    return 0;
}


// void encontrarRouter(Mapa &m, int cual){
//     for(int i = 0; i < m.getMapa().size(); i++)
//                 for(int j = 0; j < m.getMapa().size(); j++)
//                     if(m.getMapa().at(i).at(j).getIDRouter() == cual){
//                         cout<<"\nEncontrado\n"; 
//                         m.getMapa().at(i).at(j).printPosicionRouter();
//                         return (void)0;
//                     }
//             cout<<"\nNo se encuentra ningun router con ese ID\n"; 
// }

// int main(int argc, char const *argv[])
// {   
// MapaNuevo:
//     int cantRouter = 1+time(nullptr)%256;
//     Mapa m(15);
//     vector<Router> r;
//     for(int i = 0; i < cantRouter; i++){ Router nuevo; r.push_back(nuevo);}
//     r.at(0).checkIDRouter(r);
//     for(int i = 0; i < r.size(); i++){m.incluirEnMapa(r.at(i));}
//     m.setCercanos();


//     int opcion = 0;
//     do{
//         cout<<" Opciones: \n"
//         <<"1) Imprimir mapa\n"
//         <<"2) Aniadir Router al Mapa\n"
//         <<"3) Ubicacion de un Router especifico\n"
//         <<"4) Mostrar Routers Existentes\n"
//         <<"5) Mostrar Routers Cercanos a uno dado\n"
//         <<"6) Mapa Nuevo\n"
//         <<"7) Salir\n";

//         cin>>opcion;
//         switch(opcion){
//         case 1:
//             m.imprimirMapa();
//             break;
//         case 2:{
//             Router nuevo; m.incluirEnMapa(nuevo); m.setCercanos();
//             }
//             break;        
//         case 3:{
//             int cual = 0;
//             cout<<"\nIngresar ID de Router a ubicar: "; cin>>cual;
//             encontrarRouter(m,cual);
//             }
//             break;        
//         case 4:{
//             int cuenta = 0;
//             for(int i = 0; i < m.getMapa().size(); i++)
//                 for(int j = 0; j < m.getMapa().size(); j++)
//                     if(m.getMapa().at(i).at(j).getIDRouter() != -1){
//                         cuenta++;
//                         cout<<"Router Nº"<<cuenta<<" -> "<<m.getMapa().at(i).at(j).getIDRouter()<<endl;
//                     }
//             }
//             break;        
//         case 5:{
//             int cual = 0;
//             cout<<"\nMostrar los 'Cercanos' del Router: ";cin>>cual;
//             for(int i = 0; i < m.getMapa().size(); i++)
//                 for(int j = 0; j < m.getMapa().size(); j++)
//                     if(m.getMapa().at(i).at(j).getIDRouter() == cual){
//                         cout<<"El router esta en: \n";m.getMapa().at(i).at(j).printPosicionRouter();
//                         for(int k = 0; k < 8; k++)
//                             cout<<"Cercano N"<<k+1<<" -> "<<m.getMapa().at(i).at(j).getCercanos().at(k)->getIDRouter()<<endl;
//                     }
//         }
//             break;        
//         case 6:{
//             cout<<"\nSeguro de crear un nuevo mapa?\nY|N\n";
//             char respuesta = 'N'; cin>>respuesta;
//             if( respuesta == 'Y' || respuesta == 'y'){
//                 int a,b,resultado;
//                 a = 1+rand()%100; b = 1+time(nullptr)%100;
//                 cout<<"\nPara Continuar responda, cuanto es "<<a<<"+"<<b<<endl;
//                 cin>>resultado;
//                 if(resultado == a+b || resultado == -1){
//                     cout<<"\nReiniciando\n";
//                     goto MapaNuevo;
//                 }
//                 else cout<<"\nError, no se reiniciara, intente nuevamente\n";
//             }
//         }

//             break;        
//         default:
//             break;
//         }
   
        
//     } while (opcion != 7);
    




//     return 0;
// }


// int main(int argc, char const *argv[]){
//     int cantdePaginas = (time(nullptr)*rand())%1000;
//     Pagina p[cantdePaginas];
    
//     vector<Terminal> emisores; int cantdeEmisores = (time(nullptr)*rand())%256;
//     for(int i = 0; i < cantdeEmisores; i++) { Terminal terminal_aux; emisores.push_back(terminal_aux); }
//     emisores.at(0).checkIDTerminal(emisores);

//     vector<Router> routers; int cantdeRouters = (time(nullptr)*rand())%256;
//     for(int i = 0; i < cantdeRouters; i++) { Router router_aux; routers.push_back(router_aux); }
//     routers.at(0).checkIDRouter(routers);

//     cout<<"\nCantidad de Paginas: "<<cantdePaginas;
//     cout<<"\nCantidad de Emisores: "<<emisores.size();
//     cout<<"\nCantidad de Routers: "<<routers.size();
//     int cantdeReceptores = 0;
//     for(int i = 0; i < routers.size(); i++){
//         vector<Terminal> terminal_aux = routers.at(i).getReceptor();
//         cantdeReceptores += terminal_aux.size();
        
//     }
//     cout<<"\nCantidad de Receptores: "<<cantdeReceptores<<endl;
//     system("pause");
    // Router r;
    // vector<Terminal> aux = r.getReceptor();
    // for(int i = 0; i < aux.size(); i++){
    //     cout<<aux.at(i).getIDTerminal()<<" ";
    //     if((i+1)%10 == 0) cout<<endl;
    // }
    // aux.at(0).checkIDTerminal(aux);

    // int contador;
    // for(int i = 0; i < aux.size(); i++){
    //     for(int j = 0; j < aux.size(); j++){
    //         if(aux.at(i).getIDTerminal() == aux.at(j).getIDTerminal()){
    //             contador++;
    //         }
    //     }
    // }
    
    // cout<<"\nRepetidos: "<<contador<<endl;




    // int numeroDeRouter = (rand()*time(nullptr))%256, repetidos = 0;
    // // Cola<int> c[1000];

    // vector<Router> r;
    // r.reserve(numeroDeRouter);
    // for(int i = 0; i < numeroDeRouter; i++){ r.push_back(crearRouter()); }
    
    // cout<<"\nEntraCheck\n";
    // r.at(0).checkIDRouter(r);
    // cout<<"\nSaleCheck\n";

    // for(int i = 0; i < numeroDeRouter-1; i++){
    //     for(int j = 1+i; j < numeroDeRouter;j++){
    //         if(r.at(i).getIDRouter() == r.at(j).getIDRouter()){
    //             repetidos++; cout<<r.at(j).getIDRouter()<<" ";
    //         }
    //     }
    // }
    // cout<<"\nCant de Routers: "<<r.size()<<endl;
    // cout<<"\nRepetidos: "<<repetidos<<endl;

    // for(int i = 0; i < numeroDeRouter; i++){
    //     cout<<r.at(i).getIDRouter()<<" ";
    //     if((i+1)%10 == 0) cout<<endl;
    // }

//     return 0;
// }



// int crearPaginas();

// int main(int argc, char const *argv[])
// {
//     int tamaniop = crearPaginas();
//     Pagina p[tamaniop];

//     for(int i = 0; i < tamaniop; i++){
//         cout<<"Lista N"<<i+1<<" -> "<<p[i].getTamanio()<<endl;
//     }
   
//     return 0;
// }
// int crearPaginas(){
//     int i=-1;
//     cout<<"Cuantas paginas se quieren enviar por PC?"
//         <<"(El maximo es 256)\nIngresar cantidad: \n";
//         cin>>i;
//     while( i<1 || i>256 ){
//         cout<<"\nERROR: valores entre 1 y 256\n";
//         cout<<"Reingresar: ";cin>>i;
//     }
//     return i;
// }
