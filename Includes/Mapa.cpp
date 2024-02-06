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
    if(map.at(y).at(x).getIDRouter() == -1){ map.at(y).at(x) = r; r.setRouterPosicion(x,y);}
    else{
        x = y = 0;
        while( y < tamanioCuadradoMapa){
            if(map.at(y).at(x).getIDRouter() == -1){
                 map.at(y).at(x) = r;
                 r.setRouterPosicion(x,y);
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

int Mapa::calcularDistancia(Router *a,Router *b){
    int x_a = a->getRouter_x(), y_a = a->getRouter_y();
    int x_b = b->getRouter_x(), y_b = b->getRouter_y();
    int distancia = sqrt(pow((x_a-x_b),2)+pow((y_a-y_b),2));
    return distancia;
}

void Mapa::setCercanos(vector<Router> &r){// REVISAR, PROBLABEMENTE NO SIRVA.

    for(int i = 0; i < r.size(); i++){
        int x = 0,y = 0;
        for(int j = 0; j < 3; j++){
        while(y != tamanioCuadradoMapa){
            if(map.at(y).at(x).getIDRouter() != -1 && map.at(y).at(x).getIDRouter() != r.at(i).getIDRouter()){
                int dist = calcularDistancia(&r.at(i),&map.at(y).at(x));
                if(r.at(i).getCercanos().size() >= 4){
                    if(calcularDistancia(r.at(i).getCercanos().at(0),&map.at(y).at(x)) > dist){r.at(i).getCercanos().at(0) = &map.at(y).at(x);}
                    else if(calcularDistancia(r.at(i).getCercanos().at(1),&map.at(y).at(x)) > dist){r.at(i).getCercanos().at(1) = &map.at(y).at(x);}
                    else if(calcularDistancia(r.at(i).getCercanos().at(2),&map.at(y).at(x)) > dist){r.at(i).getCercanos().at(2) = &map.at(y).at(x);}
                    else if(calcularDistancia(r.at(i).getCercanos().at(3),&map.at(y).at(x)) > dist){r.at(i).getCercanos().at(3) = &map.at(y).at(x);}
                }
                else{
                    r.at(i).incluirCercanos(&map.at(y).at(x));
                }
            }
            
            x++;
            if(x == tamanioCuadradoMapa){ x = 0; y++;}
        }
    }}


}

int main(int argc, char const *argv[])
{

    int cantRouter = 1+(time(nullptr)*rand())%256;
    cantRouter = 256;
    Mapa m(20);
    vector<Router> r;
    for(int i = 0; i < cantRouter; i++){ Router nuevo; r.push_back(nuevo); }
    r.at(0).checkIDRouter(r);
    cout<<"\nFinCheck\nCantidad de Routers: "<<r.size()<<endl;


    for(int i = 0; i < r.size(); i++) m.incluirEnMapa(r.at(i));
   
    
    m.imprimirMapa();
    m.setCercanos(r);   


    // int y,x; y = x = 0;
    // while( m.getMapa().at(y).at(x).getIDRouter() == -1){
    //     x++;
    //     if(x == m.getMapa().size()){ x = 0; y++;}
    // }
    
    int a,b;
    a = r.at(0).getIDRouter();
    b = r.at(10).getIDRouter();
    cout<<a<<endl;
    cout<<b<<endl;


    r.at(0).printPosicionRouter();
    r.at(10).printPosicionRouter();

    int distance = sqrt(pow(r.at(0).getRouter_x()-r.at(10).getRouter_x(),2)+pow(r.at(0).getRouter_y()-r.at(10).getRouter_y(),2));
    printf("\nDistancia entre %d y %d: %d\n",a,b,distance);

    for(int i = 0; i < r.at(0).getCercanos().size(); i++)
    cout<<r.at(0).getCercanos().at(i)->getIDRouter()<<endl;




    cout<<endl;
    system("pause");
    return 0;
}
