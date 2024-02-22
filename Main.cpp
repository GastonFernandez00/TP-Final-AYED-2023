// #include <iostream>
// #include ".\Includes\Mapa.h"
// using namespace std;

// random_device rd;
// uniform_int_distribution<int> dist(0,256);
// uniform_int_distribution<int> paginas(0,1000);


// void printBufferRedir(Mapa m){
//     for(int i = 0; i < m.getMapa().size(); i ++){
//         for(int j = 0 ; j < m.getMapa().size(); j++){
//             if(m.getMapa().at(i).at(j).getIDRouter() == -1){
//                 cout<<-1<<" ";
//             }
//             else{
//                 cout<<m.getMapa().at(i).at(j).getSizeBufferRedireccionamiento()<<" ";
//             }
//         }
//         cout<<endl;
//     }
// }

// void printBuffer(Mapa m){
//     for(int i = 0; i < m.getMapa().size(); i ++){
//         for(int j = 0 ; j < m.getMapa().size(); j++){
//             if(m.getMapa().at(i).at(j).getIDRouter() == -1){
//                 cout<<-1<<" ";
//             }
//             else{
//                 cout<<m.getMapa().at(i).at(j).getSizeBuffer()<<" ";
//             }
//         }
//         cout<<endl;
//     }
// }

// void printPaquetesListos(Mapa m){
//     for(int i = 0; i < m.getMapa().size(); i ++){
//         for(int j = 0 ; j < m.getMapa().size(); j++){
//             if(m.getMapa().at(i).at(j).getIDRouter() == -1){
//                 cout<<-1<<" ";
//             }
//             else{
//                 cout<<m.getMapa().at(i).at(j).getPaquetesPreparados().size()<<" ";
//             }
//         }
//         cout<<endl;
//     }
// }

// void redirvacio(Mapa m){
//     bool vacio = true;
//     for(int i = 0; i < m.getMapa().size(); i ++){
//         for(int j = 0 ; j < m.getMapa().size(); j++){
//             if(m.getMapa().at(i).at(j).getIDRouter() == -1 &&
//             m.getMapa().at(i).at(j).getSizeBufferRedireccionamiento() > 0){
//                 vacio = false;
//                 m.getMapa().at(i).at(j).printPosicionRouter();
//             }}}
           
// }

// int main(int argc, char const *argv[])
// {
//     int cantdePaginas = 1000;// paginas(rd);
//     int cantRouters = dist(rd); 
//     while(cantdePaginas%cantRouters != 0){ cantdePaginas++; }

    
//     Pagina p[cantdePaginas];
//     for(int i = 0; i < cantdePaginas; i++) p[i].setID(i);
//     vector<Terminal> t;
//     vector<Router> r;
//     for(int i = 0; i < cantRouters; i++){
//         Terminal Nuevo_t; t.push_back(Nuevo_t);
//         Router Nuevo_r; r.push_back(Nuevo_r);
//     }
//     t.at(0).checkIDTerminal(t);
//     r.at(0).checkIDRouter(r);
//     for(int i = 0; i < cantdePaginas; i++) p[i].setIDDestino(r.at(dist(rd)%cantRouters).getIDRouter());

//     for(int i = 0; i < cantRouters; i++)
//         for(int j = i*(cantdePaginas/t.size()); j < (1+i)*(cantdePaginas/t.size());j++){
//             t.at(i).empaquetado(&p[j]);
//     }

//     for(int i = 0; i < cantRouters; i++){
//         r.at(i).Recepcion(t.at(i).getPaquetes());
//     }
    
    
//     Mapa m(sqrt(cantRouters)+1);
//     for(int i = 0; i < cantRouters;i++) m.incluirEnMapa(r.at(i));
//     m.setCercanos();


//     int contador = 0;
//     int opcion = 0;
//     do{
//         cout<<"\nOpciones: "
//         <<"\n1) Imprimir IDs: "
//         <<"\n2) Imprimir Buffer: "
//         <<"\n3) Imprimir BufferRedireccion: "
//         <<"\n4) Paquetes Preparados"
//         <<"\n5) Envio"        
//         <<"\n6) Envios Multiples"
//         <<"\n7) Rearmado de Paquetes por Pagina"
//         <<"\n8) Info de la Pagina"
//         <<"\n9) Acceder a un Terminal de destino"
//         <<"\n10) Envio a Terminales desde Router"
//         <<"\n11) GetCercanos a un router especifico"
//         <<"\n12) Imprimir Paginas de Una Terminal"
//         <<"\n13) Imprimir las paginas de TODAS las terminales de un router"
//         <<"\n20) Salir"
//         <<"\nIngresar Opcion: ";cin>>opcion;

//         switch(opcion){
//             case 1:
//                 m.imprimirMapa(); break;
//             case 2:
//                 printBuffer(m); break;
//             case 3:
//                 printBufferRedir(m); break;
//             case 4:
//                 printPaquetesListos(m); break;
//             case 5:
//                 m.envioEntreRouters(); break;
//             case 6:{
//                 int i = 0, valor = 1;
//                 cout<<"\nIngresar la cantidad de envios: ";cin>>valor;
//                 for(i = 0; i < valor; i++) m.envioEntreRouters();
//                 break;
//                 }
//             case 7:
//                 m.RearmadoDePaquetes();
//                 break;
//             case 9:{
//                 int rout,ter;
//                 cout<<"\nIngresar Router a acceder: ";cin>>rout;
//                 cout<<"\nIngresar Terminal a acceder dentro del router: ";cin>>ter;
//                 cout<<"\nCantidad de Paginas que se pueden armar en el terminal: "
//                 <<m.getRouterEspecifico(rout).getTerminalEspecifico(ter).getPaquetesRecibidos().size();

//             break;}
//             case 8:
//                 cout<<"\nId de Pagina: "<<p->getID()
//                 <<"\nId de destino de Router: "<<p->getIDDestino()
//                 <<"\nId de destino de Terminal: "<<p->getIDDestinoTerminal()<<endl;
//                 break;
//             case 10:
//                 m.envioATerminales();
//                 break;
//             case 11:{
//                 int rout,ter;
//                 cout<<"\nIngresar Router a acceder: ";cin>>rout;
//                 for(int i = 0; i < 8; i++)cout
//                 <<m.getRouterEspecifico(rout).getCercanos().at(i)->getIDRouter()<<endl;
//                 break;
//             }
//             case 12:{
//                 m.printFinalDePaginas();
//                 break;}
//             case 13:{
//                 int rout; cout<<"\nIngresar router a acceder: ";cin>>rout;
//                 for(int i = 0; i < 256; i++){
//                     cout<<"\nTerminal: "<<i+1;
//                     m.getRouterEspecifico(rout).getReceptor().at(i).getPaginasDisponibles();
//                 } 
                
//             }
//             }

        
//         // m.envio();
//         // // int tempo = 12500;
//         // // for(int i = 0; i < tempo; i++)for(int j = 0; j < tempo; j++);
//         // contador++;
//         // if(contador == 1000){
//         //     printBuffer(m);cout<<endl;
//         // printBufferRedir(m);cout<<endl;
//         //     contador = 0;
//         //     cout<<"Presione 1 para continuar";
//         //     cin>>opcion;
//         // }

//     }while(opcion != 20);

//     return 0;
// }
