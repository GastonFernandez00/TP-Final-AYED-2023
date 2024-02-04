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

Router Mapa::crearRouter(){ Router r(0); return r;} // Router No inicializado, posicion vacia

void Mapa::incluirEnMapa(Router r){
    int x,y; this_thread::sleep_for(chrono::milliseconds(5));
    x = (time(nullptr)*rand())%tamanioCuadradoMapa;
    y = (time(nullptr)*rand())%tamanioCuadradoMapa;
    if(map.at(y).at(x).getIDRouter() == 0){ map.at(y).at(x) = r; }
    else{
        x = y = 0;
        while( y < tamanioCuadradoMapa){
            if(map.at(y).at(x).getIDRouter() == 0){
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

int main(int argc, char const *argv[])
{
    Mapa m;
    vector<Router> r;
    for(int i = 0; i < 100; i++){ Router nuevo; r.push_back(nuevo); }
    r.at(0).checkIDRouter(r);
    cout<<"\nFinCheck\n";


    for(int i = 0; i < 100; i++) m.incluirEnMapa(r.at(i));
   
    
    vector<vector<Router>> aux = m.getMapa();
    cout<<"\nCapacidad Cuadrada: "<<aux.capacity()<<endl;

    for(int i = 0; i < aux.capacity(); i++){
        for(int j = 0; j < aux.capacity(); j++){
            cout<<aux.at(i).at(j).getIDRouter()<<"   ";
            if((1+i)%(aux.capacity()+1) == 0) cout<<endl;
        }
    }
    cout<<endl;
    //system("pause");
    return 0;
}
