#include <iostream>
#include ".\Includes\Mapa.h"
using namespace std;

random_device rd;
uniform_int_distribution<int> dist(0,256);
uniform_int_distribution<int> paginas(0,1000);


void printBufferRedir(Mapa m){
    for(int i = 0; i < m.getMapa().size(); i ++){
        for(int j = 0 ; j < m.getMapa().size(); j++){
            if(m.getMapa().at(i).at(j).getIDRouter() == -1){
                cout<<-1<<" ";
            }
            else{
                cout<<m.getMapa().at(i).at(j).getSizeBufferRedireccionamiento()<<" ";
            }
        }
        cout<<endl;
    }
}

void printBuffer(Mapa m){
    for(int i = 0; i < m.getMapa().size(); i ++){
        for(int j = 0 ; j < m.getMapa().size(); j++){
            if(m.getMapa().at(i).at(j).getIDRouter() == -1){
                cout<<-1<<" ";
            }
            else{
                cout<<m.getMapa().at(i).at(j).getSizeBuffer()<<" ";
            }
        }
        cout<<endl;
    }
}

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

void redirvacio(Mapa m){
    bool vacio = true;
    for(int i = 0; i < m.getMapa().size(); i ++){
        for(int j = 0 ; j < m.getMapa().size(); j++){
            if(m.getMapa().at(i).at(j).getIDRouter() == -1 &&
            m.getMapa().at(i).at(j).getSizeBufferRedireccionamiento() > 0){
                vacio = false;
                m.getMapa().at(i).at(j).printPosicionRouter();
            }}}
           
}

int main(int argc, char const *argv[])
{

    //Le indico cuantas Paginas, y Routers/Terminales van a existir, de forma aleatoria
    int cantdePaginas = paginas(rd);
    int cantRouters = dist(rd); 
    while(cantdePaginas%cantRouters != 0){ cantdePaginas++; }

    //Establezco el ID de cada pagina luego de haberlas creado, para que no se repitan
    Pagina p[cantdePaginas];
    for(int i = 0; i < cantdePaginas; i++) p[i].setID(i);

    //Creo Los terminales y Routers
    //Cada Router crea automaticamente 256 terminales, que son los que van a recibir las paginas
    vector<Terminal> t;
    vector<Router> r;
    for(int i = 0; i < cantRouters; i++){
        Terminal Nuevo_t; t.push_back(Nuevo_t);
        Router Nuevo_r; r.push_back(Nuevo_r);
    }
    //Revisa que no los IDs de los terminales y routers no se repitan
    t.at(0).checkIDTerminal(t);
    r.at(0).checkIDRouter(r);
    //Establece de forma aleatoria a que router va a ir cada pagina, independientemente desde donde inicie
    for(int i = 0; i < cantdePaginas; i++) p[i].setIDDestino(r.at(dist(rd)%cantRouters).getIDRouter());

    //Vector auxiliar para poder acceder a cada pagina, ya que las originales pierden informacion
    Pagina aux[cantdePaginas];
    for(int i = 0; i < cantdePaginas; i++) aux[i] = p[i];

    //Empaqueta las paginas:
    //Esta hecho de forma que cada terminal empaquete la misma cantidad de paginas
    for(int i = 0; i < cantRouters; i++)
        for(int j = i*(cantdePaginas/t.size()); j < (1+i)*(cantdePaginas/t.size());j++){
            t.at(i).empaquetado(p[j]);
    }

    //Cada Router recibe los paquetes la terminal que tiene conectada
    for(int i = 0; i < cantRouters; i++){
        r.at(i).Recepcion(t.at(i).getPaquetes());
    }
    
    //Se crea el mapa de routers y se le asocian los routers
    Mapa m(sqrt(cantRouters)+1);
    for(int i = 0; i < cantRouters;i++) m.incluirEnMapa(r.at(i));
    //Se establecen para cada router qué otros routers tiene cerca
    //para poder enviar los paquetes
    m.setCercanos();


    int contador = 0;
    int opcion = 0;
    do{
        cout<<"\nOpciones: "
        <<"\n1) Imprimir IDs: "
        <<"\n2) Imprimir Buffer: "
        <<"\n3) Imprimir BufferRedireccion: "
        <<"\n4) Paquetes Preparados"
        <<"\n5) Envio"        
        <<"\n6) Envios Multiples"
        <<"\n7) Rearmado de Paquetes por Pagina"
        <<"\n8) Info de la Pagina"
        <<"\n9) Acceder a un Terminal de destino"
        <<"\n10) Envio a Terminales desde Router"
        <<"\n11) Envios Multiples a Termianes desde Router"
        <<"\n12) GetCercanos a un router especifico"
        <<"\n13) Imprimir Paginas de Una Terminal"
        <<"\n14) Imprimir las paginas de TODAS las terminales de un router"
        <<"\n20) Salir"
        <<"\nIngresar Opcion: ";cin>>opcion;

        switch(opcion){
            case 1:
                m.imprimirMapa(); break;
            case 2:
                printBuffer(m); break;
            case 3:
                printBufferRedir(m); break;
            case 4:
                printPaquetesListos(m); break;
            case 5:
                m.envioEntreRouters(); break;
            case 6:{
                int i = 0, valor = 1;
                cout<<"\nIngresar la cantidad de envios: ";cin>>valor;
                for(i = 0; i < valor; i++) m.envioEntreRouters();
                break;
                }
            case 7:
                m.RearmadoDePaquetes();
                break;
            case 9:{
                int rout,ter;
                cout<<"\nIngresar Router a acceder: ";cin>>rout;
                cout<<"\nIngresar Terminal a acceder dentro del router: ";cin>>ter;
                cout<<"\nCantidad de Paginas que se pueden armar en el terminal: "
                <<m.getRouterEspecifico(rout).getTerminalEspecifico(ter).getPaquetesRecibidos().size();

            break;}
            case 8:{
                int pag;
                cout<<"\nIngresar Pagina a obtener informacion (Existen 0 - "<<cantdePaginas-1<<" de paginas): ";cin>>pag;
                cout<<"\nId de Pagina: "<<aux[pag].getID()
                <<"\nId de destino de Router: "<<aux[pag].getIDDestino()
                <<"\nTemanio: "<<aux[pag].getTamanio()
                <<"\nId de destino de Terminal: "<<aux[pag].getIDDestinoTerminal()<<endl;
                break;}
            case 10:
                m.envioATerminales();
                break;
            case 11:{
                int i = 0, valor = 1;
                cout<<"\nIngresar la cantidad de envios a terminales: ";cin>>valor;
                for(i = 0; i < valor; i++) m.envioEntreRouters();
                break;
                }
            case 12:{
                int rout,ter;
                cout<<"\nIngresar Router a acceder: ";cin>>rout;
                for(int i = 0; i < 8; i++)cout
                <<m.getRouterEspecifico(rout).getCercanos().at(i)->getIDRouter()<<endl;
                break;
            }
            case 13:{
                m.printFinalDePaginas();
                break;}
            case 14:{
                int rout; cout<<"\nIngresar router a acceder: ";cin>>rout;
                for(int i = 0; i < 256; i++){
                    cout<<"\nTerminal: "<<i;
                    m.getRouterEspecifico(rout).getReceptor().at(i).getPaginasDisponibles();
                } 
                
            }
            }

        

    }while(opcion != 20);

    return 0;
}
