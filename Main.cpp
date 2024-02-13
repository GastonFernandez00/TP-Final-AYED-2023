#include <iostream>
#include <time.h>
#include "./Includes/Mapa.h"
using namespace std;

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
//         <<"5) Salir\n";

//         cin>>opcion;
//         if( opcion == 1){ m.imprimirMapa();}
//         if( opcion == 2){
//             Router nuevo; m.incluirEnMapa(nuevo); m.setCercanos();
//             for(int i = 0; i < m.getMapa().size(); i++){
//                 m.getMapa().at(i).at(0).checkIDRouter(m.getMapa().at(i));
//             }
//         }
//         if( opcion == 3){
//             int cual = 0;
//             cout<<"\nIngresar ID de Router a ubicar: "; cin>>cual;
//             encontrarRouter(m,cual);
            
//         }
//         if( opcion == 4){
//             int cuenta = 0;
//             for(int i = 0; i < m.getMapa().size(); i++)
//                 for(int j = 0; j < m.getMapa().size(); j++)
//                     if(m.getMapa().at(i).at(j).getIDRouter() != -1){
//                         cuenta++;
//                         cout<<"Router Nº"<<cuenta<<" -> "<<m.getMapa().at(i).at(j).getIDRouter()<<endl;
//                     }
//         }       
//     } while (opcion != 5);
    




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
