#include "Mapa.h"
#include <thread>
#include <chrono>

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

    int x,y; this_thread::sleep_for(chrono::milliseconds(10));

    x = (time(nullptr)*rand())%tamanioCuadradoMapa;
    y = (time(nullptr)*rand())%tamanioCuadradoMapa;
    if(map.at(y).at(x).getIDRouter() == -1){  r.setRouterPosicion(x,y); map.at(y).at(x) = r;}
    else{
        x = y = 0;
        while( y < tamanioCuadradoMapa){
            if(map.at(y).at(x).getIDRouter() == -1){
                 r.setRouterPosicion(x,y);
                 map.at(y).at(x) = r;
                 return (void)0;
            }
            x++;
            if(x == tamanioCuadradoMapa){ x = 0; y++; }
        }
        cout<<"\nNo se pudo aniadir\n";
        return (void)0;
    } 
}

vector<vector<Router>> Mapa::getMapa(){ return map; }

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
                            if(dist < distCercanos[0]){ map.at(i).at(j).getCercanos().at(0) = &map.at(y).at(x); }
                            else if(dist < distCercanos[1]){ map.at(i).at(j).getCercanos().at(1) = &map.at(y).at(x); }
                            else if(dist < distCercanos[2]){ map.at(i).at(j).getCercanos().at(2) = &map.at(y).at(x); }
                            else if(dist < distCercanos[3]){ map.at(i).at(j).getCercanos().at(3) = &map.at(y).at(x); }
                            else if(dist < distCercanos[4]){ map.at(i).at(j).getCercanos().at(4) = &map.at(y).at(x); }
                            else if(dist < distCercanos[5]){ map.at(i).at(j).getCercanos().at(5) = &map.at(y).at(x); }
                            else if(dist < distCercanos[6]){ map.at(i).at(j).getCercanos().at(6) = &map.at(y).at(x); }
                            else if(dist < distCercanos[7]){ map.at(i).at(j).getCercanos().at(7) = &map.at(y).at(x); }
                                                   
                        }
                    }
     
                    x++;
                    if(x == tamanioCuadradoMapa){ x = 0; y++; }
                }
            }
        }
    }
}

int main(int argc, char const *argv[])
{

    int cantRouter = 1+(time(nullptr)*rand())%256;
    //cantRouter = 256;
    Mapa m(20);
    vector<Router> r;
    for(int i = 0; i < cantRouter; i++){ Router nuevo; r.push_back(nuevo); }
    r.at(0).checkIDRouter(r);
    cout<<"\nFinCheck\nCantidad de Routers: "<<r.size()<<endl;


    for(int i = 0; i < r.size(); i++) m.incluirEnMapa(r.at(i));
   
    
    //m.imprimirMapa();
    m.setCercanos();   
    m.imprimirMapa();
    cout<<"Router: "<<r.at(0).getIDRouter()<<endl;
    m.getMapa().at(r.at(0).getRouter_y()).at(r.at(0).getRouter_x()).printPosicionRouter();
    cout<<"Cercanos:\n";
    for(int i = 0; i < 8; i++)
    cout<<m.getMapa().at(r.at(0).getRouter_y()).at(r.at(0).getRouter_x()).getCercanos().at(i)->getIDRouter()
    <<endl;
    // cout<<r.at(0).getCercanos().at(i)->getIDRouter()<<endl;

    



    // int y,x; y = x = 0;
    // while( m.getMapa().at(y).at(x).getIDRouter() == -1){
    //     x++;
    //     if(x == m.getMapa().size()){ x = 0; y++;}
    // }
    
    // int a,b;
    // a = r.at(0).getIDRouter();
    // b = r.at(10).getIDRouter();
    // cout<<a<<endl;
    // cout<<b<<endl;


    // r.at(0).printPosicionRouter();
    // r.at(10).printPosicionRouter();

    // int distance = sqrt(pow(r.at(0).getRouter_x()-r.at(10).getRouter_x(),2)+pow(r.at(0).getRouter_y()-r.at(10).getRouter_y(),2));
    // printf("\nDistancia entre %d y %d: %d\n",a,b,distance);

    // for(int i = 0; i < r.at(0).getCercanos().size(); i++)
    // cout<<r.at(0).getCercanos().at(i)->getIDRouter()<<endl;




    cout<<endl;
    system("pause");
    return 0;
}
