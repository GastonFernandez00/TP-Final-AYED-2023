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
    int cantidadDePaginas = 2;//paginas(rd);
    int cantidadRouterTerminales = 2;//dist(rd);
    while(cantidadDePaginas%cantidadRouterTerminales != 0 || cantidadDePaginas == 0){cantidadDePaginas++;}
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

    for(int i = 0; i < cantidadRouterTerminales; i++)
        for(int j = i*(cantidadRouterTerminales/t.size()); j < (1+i)*(cantidadDePaginas/t.size());j++){
            t.at(i).empaquetado(p[j]);
    }
    
    for(int i = 0; i< r.size();i++) r.at(i).Recepcion(t.at(i).getPaquetes());

    
//     for(int i = 0; i< r.size();i++){
//         int sumar = 0;
//             for(int k = 0; k < r.at(i).getBufferRouter().size(); k++){
//                 queue<Paquete> c = r.at(i).getBufferRouter();
//                 if(r.at(i).getBufferRouter().front().getIdPertenencia()
//                 == c.front().getIdPertenencia()){sumar++;}
//                 c.pop();
//             }
//                 cout<<endl<<sumar<<" || "<<r.at(i).getBufferRouter().front().getDivisionesTotales()<<endl;
//     }
// }

//     int sumar = 0; queue<Paquete> c = t.at(0).getPaquetes();
//     cout<<c.size()<<"   "<<t.at(0).getPaquetes().size()<<endl;
//     while(c.size() > 0){
//     if(c.front().getIdPertenencia() == t.at(0).getPaquetes().front().getIdPertenencia()){ sumar++;}
//     c.pop();
//     }
//     cout<<endl<<sumar<<" || "<<t.at(0).getPaquetes().front().getDivisionesTotales();
// }
    

    Mapa m(sqrt(cantidadRouterTerminales)+1);
    for(int i = 0; i < r.size(); i++) m.incluirEnMapa(r.at(i));
    m.setCercanos();
    for(int i = 0; i < 100; i++) m.envioEntreRouters();
    m.imprimirMapa();
    // m.RearmadoDePaquetes();

    for(int i = 0; i < m.getMapa().size(); i++){
    for(int j = 0; j < m.getMapa().size(); j++){
        if(m.getMapa().at(i).at(j).getIDRouter() != -1 && m.getMapa().at(i).at(j).getBufferRouter().size() > 0){
            int sumar = 0;
            queue<Paquete> c = m.getMapa().at(i).at(j).getBufferRouter();
            for(int k = 0; k < m.getMapa().at(i).at(j).getBufferRouter().size(); k++){
                
                if(m.getMapa().at(i).at(j).getBufferRouter().front().getIdPertenencia()
                == c.front().getIdPertenencia()){
                    sumar++;
                    cout<<c.front().getDato()<<" ";
                    }
                // cout<<c.front().getIdPertenencia()<<" "<<c.front().getDato()
                // <<" "<<c.front().getPackNumero()<<endl;
                c.pop();
            }
                cout<<endl<<sumar<<" || "<<m.getMapa().at(i).at(j).getBufferRouter().front().getDivisionesTotales()<<endl;
        break;}

        cout<<"Redireccion------------------------"<<endl;
        if(m.getMapa().at(i).at(j).getIDRouter() != -1 && m.getMapa().at(i).at(j).getBufferRedireccionRouter().size() > 0){
            int sumar = 0;
            for(int k = 0; k < m.getMapa().at(i).at(j).getBufferRedireccionRouter().size(); k++){
                queue<Paquete> c = m.getMapa().at(i).at(j).getBufferRedireccionRouter();
                if(m.getMapa().at(i).at(j).getBufferRedireccionRouter().front().getIdPertenencia()
                == c.front().getIdPertenencia()){sumar++;}
                c.pop();
            }
                cout<<endl<<sumar<<" || "<<m.getMapa().at(i).at(j).getBufferRouter().front().getDivisionesTotales()<<endl;
        break;}


    break;}break;}
}
