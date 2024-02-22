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
    int cantidadDePaginas = paginas(rd);
    int cantidadRouterTerminales = dist(rd);
    while(cantidadDePaginas%cantidadRouterTerminales != 0){cantidadDePaginas++;}
    Pagina p[cantidadDePaginas];
    for(int i = 0; i < cantidadDePaginas; i++) p[i].setID(i);

    vector<Terminal> t;
    vector<Router> r;
    for(int i = 0; i < cantidadRouterTerminales; i++){
        Terminal nuevo_t; t.push_back(nuevo_t);
        Router nuevo_r; r.push_back(nuevo_r);
    }
    t.at(0).checkIDTerminal(t);
    r.at(0).checkIDRouter(r);

    for(int i = 0; i < cantidadDePaginas; i++) p[i].setIDDestino(r.at(dist(rd)%cantidadRouterTerminales).getIDRouter());

    for(int i = 0; i < t.size(); i++){
        for(int k = i*(cantidadDePaginas/cantidadRouterTerminales); k < (1+i)*(cantidadDePaginas/cantidadRouterTerminales); k++){
        t.at(i).empaquetado(&p[k]);
    }}

//         for(int i = 0; i < cantidadDePaginas; i++){
//         cout<<p[i].getTamanio()<<" ";
//         if((i+1)%10 == 0) cout<<endl;  
//     }

//     cout<<endl<<"-----------------------------------"<<endl;


//     for(int i = 0; i < t.size(); i++){
//         for(int j = 0; j < t.at(i).getPaquetes().size(); j++){
//             cout<<t.at(i).getPaquetes().front().getDivisionesTotales()<<" ";
//             t.at(i).getPaquetes().pop();
//             if((j+1)%10 == 0) cout<<endl;
//         }
//         cout<<"\n\n";
//     }
// }
    
    for(int i = 0; i< r.size();i++) r.at(i).Recepcion(t.at(i).getPaquetes());

    Mapa m(sqrt(cantidadRouterTerminales)+1);
    for(int i = 0; i < r.size(); i++) m.incluirEnMapa(r.at(i));
    m.setCercanos();
    for(int i = 0; i < 300; i++) m.envioEntreRouters();

    m.RearmadoDePaquetes();

    for(int i = 0; i < m.getMapa().size(); i++){
    for(int j = 0; j < m.getMapa().size(); j++){
        if(m.getMapa().at(i).at(j).getIDRouter() != -1){
    //         for(int k = 0; k < m.getMapa().at(i).at(j).getBufferRouter().size(); k++){
    //             cout<<m.getMapa().at(i).at(j).getBufferRouter().front().getDivisionesTotales()<<" ";
    //             if((k+1)%10 == 0)cout<<endl;
    //             m.getMapa().at(i).at(j).getBufferRouter().pop();
    //         }
            
    //     }
        for(int k = 0; k < m.getMapa().at(i).at(j).getPaquetesPreparados().size(); k++){
            cout<<m.getMapa().at(i).at(j).getPaquetesPreparados().at(k).size()<<" | "
            <<m.getMapa().at(i).at(j).getPaquetesPreparados().at(k).front().getDivisionesTotales()<<endl;
        }
        }
        }

    }
}
