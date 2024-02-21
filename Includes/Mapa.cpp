#include "Mapa.h"
#include <algorithm>
//#include <thread>
//#include <chrono>

auto comparador = [](const auto& a, const auto& b) {
        return a.second < b.second;
};

Mapa::Mapa(){
    for(int i = 0; i < tamanioCuadradoMapa; i++){
        vector<Router> aux;
        map.push_back(aux);
        for(int j = 0; j < tamanioCuadradoMapa; j++){
            map.at(i).push_back(crearRouter());
        }
    }

}

Mapa::Mapa(int n){
    setTamanioCuadradoMapa(n);
    for(int i = 0; i < tamanioCuadradoMapa; i++){
        vector<Router> aux;
        map.push_back(aux);
        for(int j = 0; j < tamanioCuadradoMapa; j++){
            map.at(i).push_back(crearRouter());
        }
    }
}

void Mapa::setTamanioCuadradoMapa(int n){ tamanioCuadradoMapa = n; }

Router Mapa::crearRouter(){ Router r(-1); return r;} // Router No inicializado, posicion vacia y sin receptores

void Mapa::incluirEnMapa(Router &r){

    random_device rd;
    uniform_int_distribution<int> dist(0,tamanioCuadradoMapa-1);
    int x,y;

    x = dist(rd);
    y = dist(rd);
    if(map.at(y).at(x).getIDRouter() == -1){  r.setRouterPosicion(x,y); map.at(y).at(x) = r;}
    else{
        vector<pair<int,int>> cuenta; 
        for(int i = 0; i < tamanioCuadradoMapa; i++){
            int contador = 0;
                for(int j = 0; j < tamanioCuadradoMapa; j++){
                    if(map.at(i).at(j).getIDRouter() != -1){
                        contador++;
                    }
                }
            cuenta.push_back(pair<int,int>(i,contador));
        }
        sort(cuenta.begin(),cuenta.end(),comparador);

        if(cuenta.at(0).second < tamanioCuadradoMapa){
            y = cuenta.at(0).first;
            bool seleccionado = false;
            while(seleccionado == false){
                x = dist(rd);
                if(map.at(y).at(x).getIDRouter() == -1){
                    r.setRouterPosicion(x,y); map.at(y).at(x) = r;
                    return (void)0;
                }
            }
        }
        
        cout<<"\nNo se pudo aniadir\n";
        return (void)0;
    } 
}

vector<vector<Router>>& Mapa::getMapa(){ return map; }

int Mapa::cantidadDeRoutersEnMapa(){
    int suma = 0;
    for(int i = 0; i < map.at(0).size(); i++)
        for(int j = 0; j < map.at(0).size(); j++)
            if(map.at(i).at(j).getIDRouter() != -1){
                suma += 1;
            }
    return suma;
}

void Mapa::imprimirMapa(){
    if(map.size() <= 0) return (void)0;
    cout<<endl;
    for(int i = 0; i < tamanioCuadradoMapa; i++){
        for(int j = 0; j < tamanioCuadradoMapa; j++){
        cout<<map.at(i).at(j).getIDRouter()<<" ";
        //if((1+j)%(tamanioCuadradoMapa+1) == 0) cout<<endl;
        }
        cout<<endl;
    }
    cout<<endl;
}

float Mapa::calcularDistancia(Router *a,Router *b){
    int x_a = a->getRouter_x(), y_a = a->getRouter_y();
    int x_b = b->getRouter_x(), y_b = b->getRouter_y();
    float distancia = sqrt(pow((x_a-x_b),2)+pow((y_a-y_b),2));
    return distancia;
}

void Mapa::setCercanos(){    

    for(int i = 0; i < tamanioCuadradoMapa; i++){
        for(int j = 0; j < tamanioCuadradoMapa; j++){
            if(map.at(i).at(j).getIDRouter() != -1){
                for(int repe = 0; repe < 8; repe++){
                    int x = 0, y = 0;

                    while(y != tamanioCuadradoMapa){
                        if(map.at(y).at(x).getIDRouter() != -1 && map.at(y).at(x).getIDRouter() != map.at(i).at(j).getIDRouter()){
                            if(map.at(i).at(j).getCercanos().size() < 8) map.at(i).at(j).incluirCercanos(&map.at(y).at(x));
                            else{
                                float dist = calcularDistancia(&map.at(i).at(j),&map.at(y).at(x));
                                float distCercanos[8];
                                for(int calc = 0; calc < 8; calc++){
                                    distCercanos[calc] = calcularDistancia(map.at(i).at(j).getCercanos().at(calc),&map.at(i).at(j));
                                }
                                
                                for(int calc = 0; calc < 8; calc++){
                                    bool yaEsta = false;
                                    if((dist < distCercanos[calc]) && (yaEsta == false)){
                                        for(int rep = 0; rep < 8; rep++){
                                            if(map.at(i).at(j).getCercanos().at(rep)->getIDRouter() == map.at(y).at(x).getIDRouter()){
                                                yaEsta = true;
                                            }
                                        }    
                                        if( yaEsta == false){
                                            map.at(i).at(j).getCercanos().at(calc) = &map.at(y).at(x);
                                        }
                                    }
                                }
                                                    
                            }
                        }
        
                        x++;
                        if(x == tamanioCuadradoMapa){ x = 0; y++; }
                    }
                }
            }
        }
    }
}

Router& Mapa::getRouterEspecifico(int R){
    for(int i = 0; i < tamanioCuadradoMapa; i ++)
        for(int j = 0; j < tamanioCuadradoMapa; j ++)
            if(map.at(i).at(j).getIDRouter() == R) return map.at(i).at(j);

    cout<<"\nEl router no se encuentra en el mapa."<<endl;
}

void Mapa::envioEntreRouters(){
    for(int i = 0; i < tamanioCuadradoMapa; i++)
        for(int j = 0; j < tamanioCuadradoMapa; j++)
            if(map.at(i).at(j).getIDRouter() != -1 && map.at(i).at(j).getSizeBufferRedireccionamiento() > 0){
                for(int bw = 0; bw < map.at(i).at(j).getBandWidth(); bw++)
                if(map.at(i).at(j).getSizeBufferRedireccionamiento() > 0){
                bool enviado = false;
                for(int k = 0; k < 8; k++){
                    if(map.at(i).at(j).getBufferRedireccionRouter().front().getIDDestino()
                    == map.at(i).at(j).getCercanos().at(k)->getIDRouter() && enviado == false){
                    //END IF
                        map.at(i).at(j).getCercanos().at(k)->Recepcion(map.at(i).at(j).getBufferRedireccionRouter().front());
                        map.at(i).at(j).getBufferRedireccionRouter().pop();
                        enviado = true;
                    }
                }
                if(enviado == false){
                    vector<pair<Router*,int>> aux;
                    for (int n = 0; n < 8; n++) aux.push_back(pair<Router*,float>(
                        map.at(i).at(j).getCercanos().at(n),calcularDistancia(map.at(i).at(j).getCercanos().at(n),
                        &getRouterEspecifico(map.at(i).at(j).getBufferRedireccionRouter().front().getIDDestino()))));
                        sort(aux.begin(), aux.end(), comparador);

                        Router* conveniente = aux.at(0).first;
                        for(int n = 1; n < 3; n++){
                            if((conveniente->getSizeBufferRedireccionamiento()/conveniente->getBandWidth()) > (aux.at(n).first->getSizeBufferRedireccionamiento()/aux.at(n).first->getBandWidth()))
                            conveniente = aux.at(n).first;
                        }
                        conveniente->Recepcion(map.at(i).at(j).getBufferRedireccionRouter().front());
                        map.at(i).at(j).getBufferRedireccionRouter().pop();
                        enviado = true;
                }

            }}
    
}

void Mapa::RearmadoDePaquetes(){
    for(int i = 0; i < tamanioCuadradoMapa; i++)
        for(int j = 0; j < tamanioCuadradoMapa; j++)
            if(map.at(i).at(j).getIDRouter() != -1 && map.at(i).at(j).getSizeBuffer() > 0){
                while(map.at(i).at(j).getSizeBuffer() > 0){
                    //if(map.at(i).at(j).getSizeBuffer() > 0){
                        bool encontrado = false, index; 
                        for(int iter = 0; iter < map.at(i).at(j).getPaquetesPreparados().size(); iter++){
                            if(map.at(i).at(j).getPaquetesPreparados().at(iter).front().getIdPertenencia()
                            == map.at(i).at(j).getBufferRouter().front().getIdPertenencia()
                            && encontrado == false){encontrado = true;index = iter;}
                        }
                            if(encontrado == false){
                                queue<Paquete> aux; 
                                aux.push( map.at(i).at(j).getBufferRouter().front());
                                map.at(i).at(j).getPaquetesPreparados().push_back(aux);
                                map.at(i).at(j).getBufferRouter().pop();
                            }
                            else{
                                map.at(i).at(j).getPaquetesPreparados().at(index).push(map.at(i).at(j).getBufferRouter().front());
                                map.at(i).at(j).getBufferRouter().pop();
                            }
                        }
                }
 //           }
}

void Mapa::envioATerminales(){
    
    for(int i = 0; i < tamanioCuadradoMapa; i ++){
        for(int j = 0; j < tamanioCuadradoMapa; j++){
            Router *r = &map.at(i).at(j);
            vector<queue<Paquete>*> aEnviar;
            if(r->getIDRouter() != -1 && r->getPaquetesPreparados().size() > 0){
                for(int k = 0; k < r->getPaquetesPreparados().size();k++){
                    if(r->getPaquetesPreparados().at(k).front().getDivisionesTotales()==
                    r->getPaquetesPreparados().at(k).size()){
                        //END IF 
                        aEnviar.push_back(&r->getPaquetesPreparados().at(k));
                    }
                }
            }
            for(int k = 0; k < aEnviar.size(); k++){
                if(r->getReceptor().at(k).getIDTerminal() == aEnviar.back()->front().getIDDestinoTerminal()){
                    r->getReceptor().at(k).recibePaquetes(*aEnviar.back());

                    while(aEnviar.back()->size() > 0){
                    aEnviar.back()->pop();
                    }
                    
                    aEnviar.pop_back();
                }
            }
            for(int k = 0 ; k < r->getPaquetesPreparados().size(); k++){
                if(r->getPaquetesPreparados().at(k).empty()){
                    r->getPaquetesPreparados().erase(r->getPaquetesPreparados().begin()+1);
                }
            }

        }
    }    
    this->armadoDePaginas();
}

void Mapa::armadoDePaginas(){
    for(int i = 0; i < tamanioCuadradoMapa; i++){
        for(int j = 0; j < tamanioCuadradoMapa; j++){
            Router *r = &map.at(i).at(j);
            if(r->getIDRouter() != -1){
                for(int ter = 0; ter < 256; ter++){
                    while(r->getReceptor().at(ter).getPaquetesRecibidos().size() > 0){
                        r->getReceptor().at(ter).rearmarPaginas(r->getReceptor().at(ter).getPaquetesRecibidos().back());
                        r->getReceptor().at(ter).getPaquetesRecibidos().pop_back();
                    }                    
                }
            }
        }
    }

}

void Mapa::printFinalDePaginas(){
    int x,y;
    cout<<"\nIngresar Router a ver: ";cin>>y;
    cout<<"\nIngresar Terminal a ver: ";cin>>x;
    getRouterEspecifico(y).getTerminalEspecifico(x).getPaginasDisponibles();
}

// int main(int argc, char const *argv[])
// {

//     // int cantRouter = 1+(time(nullptr)*rand())%256;
//     int cantRouter = 25;
//     Mapa m(20);
//     vector<Router> r;
//     for(int i = 0; i < cantRouter; i++){ Router nuevo; r.push_back(nuevo); }
//     r.at(0).checkIDRouter(r);
//     cout<<"\nFinCheck\nCantidad de Routers: "<<r.size()<<endl;


//     for(int i = 0; i < r.size(); i++) m.incluirEnMapa(r.at(i));
   
    
//     //m.imprimirMapa();
//     m.setCercanos();   
//     m.imprimirMapa();
//     cout<<"Router: "<<r.at(0).getIDRouter()<<endl;
//     m.getMapa().at(r.at(0).getRouter_y()).at(r.at(0).getRouter_x()).printPosicionRouter();
//     cout<<"Cercanos:\n";
//     for(int i = 0; i < m.getMapa().at(r.at(0).getRouter_y()).at(r.at(0).getRouter_x()).getCercanos().size(); i++)
//     cout<<m.getMapa().at(r.at(0).getRouter_y()).at(r.at(0).getRouter_x()).getCercanos().at(i)->getIDRouter()
//     <<endl;
//     // cout<<r.at(0).getCercanos().at(i)->getIDRouter()<<endl;

//     cout<<"\n\nCantidad de Routers Activos: "<<m.cantidadDeRoutersEnMapa()<<endl;



//     // int y,x; y = x = 0;
//     // while( m.getMapa().at(y).at(x).getIDRouter() == -1){
//     //     x++;
//     //     if(x == m.getMapa().size()){ x = 0; y++;}
//     // }
    
//     // int a,b;
//     // a = r.at(0).getIDRouter();
//     // b = r.at(10).getIDRouter();
//     // cout<<a<<endl;
//     // cout<<b<<endl;


//     // r.at(0).printPosicionRouter();
//     // r.at(10).printPosicionRouter();

//     // int distance = sqrt(pow(r.at(0).getRouter_x()-r.at(10).getRouter_x(),2)+pow(r.at(0).getRouter_y()-r.at(10).getRouter_y(),2));
//     // printf("\nDistancia entre %d y %d: %d\n",a,b,distance);

//     // for(int i = 0; i < r.at(0).getCercanos().size(); i++)
//     // cout<<r.at(0).getCercanos().at(i)->getIDRouter()<<endl;




//     cout<<endl;
//     system("pause");
//     return 0;
// }
