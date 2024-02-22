#include <iostream>
#include ".\Includes\Mapa.h"
using namespace std;

random_device rd;
uniform_int_distribution<int> dist(0,256);
uniform_int_distribution<int> paginas(0,1000);

void printPaquetesListos(Mapa m){
    for(int i = 0; i < m.getMapa().size(); i ++){
        for(int j = 0 ; j < m.getMapa().size(); j++){
            if(m.getMapa().at(i).at(j).getIDRouter() == -1){
                cout<<-1<<" ";
            }
            else{
                cout<<m.getMapa().at(i).at(j).getPaquetesPreparados().size()<<" ";
            }
        }
        cout<<endl;
    }
}

int main(int argc, char const *argv[])
{
    int cantidadDePaginas = 1;// paginas(rd);
    int cantidadRouterTerminales = 1;//dist(rd);
    cout<<"Resultado: "<<cantidadDePaginas%cantidadRouterTerminales<<endl;
    while(cantidadDePaginas%cantidadRouterTerminales != 0){cantidadDePaginas++;}
    Pagina p[cantidadDePaginas];
    for(int i = 0; i < cantidadDePaginas; i++) p[i].setID(i);
    
    
    Pagina controlP[cantidadDePaginas];
    for(int i = 0; i < cantidadDePaginas; i++) controlP[i] = p[i];


    vector<Terminal> t;
    vector<Router> r;
    for(int i = 0; i < cantidadRouterTerminales; i++){
        Terminal nuevo_t; t.push_back(nuevo_t);
        Router nuevo_r; r.push_back(nuevo_r);
    }
    t.at(0).checkIDTerminal(t);
    r.at(0).checkIDRouter(r);

    for(int i = 0; i < cantidadDePaginas; i++) p[i].setIDDestino(r.at(dist(rd)%cantidadRouterTerminales).getIDRouter());

    t.at(0).empaquetado(p[0]);

    //     for(int i = 0; i < cantidadDePaginas; i++){
    //     cout<<p[i].getTamanio()<<" ";
    //     if((i+1)%10 == 0) cout<<endl;  
    // }

    // cout<<endl<<"-----------------------------------"<<endl;


//     for(int i = 0; i < t.size(); i++){
//         for(int j = 0; j < t.at(i).getPaquetes().size(); j++){
//             cout<<t.at(i).getPaquetes().front().getIdPertenencia()<<" ";
//             t.at(i).getPaquetes().pop();
//             if((j+1)%30 == 0) cout<<endl;
//         }
//         cout<<"\n";
//     }

//     cout<<"\nPaginas: "<<cantidadDePaginas;
// }


    
    
    // for(int i = 0; i< r.size();i++) r.at(i).Recepcion(t.at(i).getPaquetes());

    int sumar = 0; queue<Paquete> c = t.at(0).getPaquetes();
    cout<<c.size()<<"   "<<t.at(0).getPaquetes().size()<<endl;
    while(c.size() > 0){
    if(c.front().getIdPertenencia() == t.at(0).getPaquetes().front().getIdPertenencia()){ sumar++;}
    c.pop();
    }
    cout<<endl<<sumar<<" || "<<t.at(0).getPaquetes().front().getDivisionesTotales();
}
    

//     Mapa m(sqrt(cantidadRouterTerminales)+1);
//     for(int i = 0; i < r.size(); i++) m.incluirEnMapa(r.at(i));
//     m.setCercanos();
//     for(int i = 0; i < 300; i++) m.envioEntreRouters();

// //     m.RearmadoDePaquetes();

//     for(int i = 0; i < m.getMapa().size(); i++){
//     for(int j = 0; j < m.getMapa().size(); j++){
//         if(m.getMapa().at(i).at(j).getIDRouter() != -1){
//             for(int k = 0; k < m.getMapa().at(i).at(j).getBufferRouter().size(); k++){
//                 int suma = 0;
//                 queue<Paquete> c = m.getMapa().at(i).at(j).getBufferRouter();
//                 for(int k = 0; k < c.size(); k++){
//                 if(c.front().getIdPertenencia() ==  m.getMapa().at(i).at(j).getBufferRouter().front().getIdPertenencia()){
//                     cout<<c.front().getIdPertenencia()<<endl;
                   
//                 }
//                 c.pop();
//                 }
//                 cout<<endl<<m.getMapa().at(i).at(j).getBufferRouter().front().getIdPertenencia()
//                 <<" Paquetes: "<<m.getMapa().at(i).at(j).getBufferRouter().front().getDivisionesTotales();
//                 break;
//             }
//         }
//     break;}break;}

// }
        // for(int k = 0; k < m.getM
