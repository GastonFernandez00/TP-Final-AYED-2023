#include "Mapa.h"
#include <algorithm>


auto comparador = [](const auto& a, const auto& b) {
        return a.second < b.second;
};

Mapa::Mapa(){
    for(int i = 0; i < tamanioCuadradoMapa; i++){
        vector<Router> aux; //Genera una fila
        map.push_back(aux);
        for(int j = 0; j < tamanioCuadradoMapa; j++){
            map.at(i).push_back(crearRouter()); //Aumenta la columna con un Router vacio
        }
    }
}

Mapa::Mapa(int n){
    setTamanioCuadradoMapa(n); //Establece cual va a ser el tamanio del mapa
    for(int i = 0; i < tamanioCuadradoMapa; i++){
        vector<Router> aux; //Genera una fila
        map.push_back(aux);
        for(int j = 0; j < tamanioCuadradoMapa; j++){
            map.at(i).push_back(crearRouter()); //Aumenta la columna con un Router vacio
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
                for(int j = 0; j < tamanioCuadradoMapa; j++){ //Cuenta cuantos espacios ocupados hay en cada fila
                    if(map.at(i).at(j).getIDRouter() != -1){
                        contador++;
                    }
                }
            cuenta.push_back(pair<int,int>(i,contador)); 
        }
        sort(cuenta.begin(),cuenta.end(),comparador);//reordena de menor a mayor, en base a las filas mas ocupadas

        if(cuenta.at(0).second < tamanioCuadradoMapa){//Si hay espacios libres en la fila se
            y = cuenta.at(0).first;                    //define que fila es. Ya que se cambio en el sort
            bool seleccionado = false;
            while(seleccionado == false){               //Mientras no se haya incluido el router en alguna posicion, repite
                x = dist(rd);
                if(map.at(y).at(x).getIDRouter() == -1){//Tiene que ser una posicion vacia
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
            if(map.at(i).at(j).getIDRouter() != -1){ //Cuenta cuantos Routers No vacios hay
                suma += 1;
            }
    return suma;
}

void Mapa::imprimirMapa(){
    if(map.size() <= 0) return (void)0;
    cout<<endl;
    for(int i = 0; i < tamanioCuadradoMapa; i++){
        for(int j = 0; j < tamanioCuadradoMapa; j++){ //Tambien imprime los vacios, para mantener el formato del mapa
        cout<<map.at(i).at(j).getIDRouter()<<" ";     //tal que Mapa[tamanioCuadradoMapa][tamanioCuadradoMapa]
        }
        cout<<endl;
    }
    cout<<endl;
}

float Mapa::calcularDistancia(Router *a,Router *b){//Simplemente aplica pitagoras
    int x_a = a->getRouter_x(), y_a = a->getRouter_y();
    int x_b = b->getRouter_x(), y_b = b->getRouter_y();
    float distancia = sqrt(pow((x_a-x_b),2)+pow((y_a-y_b),2));
    return distancia;
}

void Mapa::setCercanos(){    

    for(int i = 0; i < tamanioCuadradoMapa; i++){ for(int j = 0; j < tamanioCuadradoMapa; j++){
        if(map.at(i).at(j).getIDRouter() != -1){ //Recorre Todos los  routers no vacios
            for(int repe = 0; repe < 8; repe++){ //Recorre los routers cercanos
                int x = 0, y = 0;

                while(y != tamanioCuadradoMapa){ //Vuelve a recorrer el mapa, pero con otros valores X,Y, par poder comparar
                    if(map.at(y).at(x).getIDRouter() != -1 && map.at(y).at(x).getIDRouter() != map.at(i).at(j).getIDRouter()){
                        //Si el router por el que pasa el segundo recorrido es el mismo que el primero, lo ignora
                        if(map.at(i).at(j).getCercanos().size() < 8) map.at(i).at(j).incluirCercanos(&map.at(y).at(x));
                        //Si no tiene Cercanos establecidos, le include los 8 primeros que encuentre
                        else{
                            //Calcula la distancia entre el router del primer recorrido y el segundo
                            float dist = calcularDistancia(&map.at(i).at(j),&map.at(y).at(x));
                            float distCercanos[8];
                            for(int calc = 0; calc < 8; calc++){//Calcula la distancia entre el router del primer recorrido y sus cercanos
                                distCercanos[calc] = calcularDistancia(map.at(i).at(j).getCercanos().at(calc),&map.at(i).at(j));
                            }
                            
                            for(int calc = 0; calc < 8; calc++){
                                bool yaEsta = false;
                                //Si alguna distancia nueva es menor a la que estaba original, va a intentar reemplazar a la original
                                //siempre y cuando no sea el mismo router intentando reemplazarse a si mismo
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
    }}
}

Router& Mapa::getRouterEspecifico(int R){
    for(int i = 0; i < tamanioCuadradoMapa; i ++)
        for(int j = 0; j < tamanioCuadradoMapa; j ++)
            if(map.at(i).at(j).getIDRouter() == R) return map.at(i).at(j);

    cout<<"\nEl router no se encuentra en el mapa."<<endl;
}

void Mapa::envioEntreRouters(){
    for(int i = 0; i < tamanioCuadradoMapa; i++) for(int j = 0; j < tamanioCuadradoMapa; j++)
        if(map.at(i).at(j).getIDRouter() != -1 && map.at(i).at(j).getBufferRedireccionRouter().size() > 0){
            for(int bw = 0; bw < map.at(i).at(j).getBandWidth(); bw++)//Repite el envio de un router en particular en base al BW
            if(map.at(i).at(j).getBufferRedireccionRouter().size() > 0){
            bool enviado = false;
            for(int k = 0; k < 8; k++){//Revisa si el router de destino del paquete es uno de los routers cercano
                if(map.at(i).at(j).getBufferRedireccionRouter().front().getIDDestino()
                == map.at(i).at(j).getCercanos().at(k)->getIDRouter() && enviado == false){
                //END IF
                //Si es uno de los cercanos, lo envia ahi
                    map.at(i).at(j).getCercanos().at(k)->Recepcion(map.at(i).at(j).getBufferRedireccionRouter().front());
                    map.at(i).at(j).getBufferRedireccionRouter().pop(); // Y lo quita del buffer
                    enviado = true;
                    break;
                }
            }
            if(enviado == false){
                //Si no es uno de los cercanos, almacena todos los cercanos en un vector<pair<Router*,int>>
                //en base a la distancia entre cada uno de los cercanos y el destino final del paquete
                vector<pair<Router*,int>> aux;
                for (int n = 0; n < 8; n++) aux.push_back(pair<Router*,float>(
                    map.at(i).at(j).getCercanos().at(n),calcularDistancia(map.at(i).at(j).getCercanos().at(n),
                    &getRouterEspecifico(map.at(i).at(j).getBufferRedireccionRouter().front().getIDDestino()))));
                    //Organiza el vector<pair<Router*,int>> de menor a mayor
                    sort(aux.begin(), aux.end(), comparador);

                    //Toma los primeros 3 routers mas cercanos al destino final, y elige le que este mas vacio
                    //teniendo en cuenta la relacion del tamanio del buffer de redireccionamiento
                    //y la BW del router cercano
                    Router* conveniente = aux.at(0).first;
                    for(int n = 1; n < 3; n++){
                        if((conveniente->getSizeBufferRedireccionamiento()/conveniente->getBandWidth()) > (aux.at(n).first->getSizeBufferRedireccionamiento()/aux.at(n).first->getBandWidth()))
                        conveniente = aux.at(n).first;
                    }
                    //Provoca el envio y lo quita del buffer de redireccionamiento
                    conveniente->Recepcion(map.at(i).at(j).getBufferRedireccionRouter().front());
                    map.at(i).at(j).getBufferRedireccionRouter().pop();
                    enviado = true;
            }

        }}
    
}

void Mapa::RearmadoDePaquetes(){
    for(int i = 0; i < tamanioCuadradoMapa; i++) for(int j = 0; j < tamanioCuadradoMapa; j++)
            
            if(map.at(i).at(j).getIDRouter() != -1 && map.at(i).at(j).getSizeBuffer() > 0){
                while(map.at(i).at(j).getSizeBuffer() > 0){//Mientras haya paquetes en el router que corresponde
                        //Si no existen colas de paquetes, crea una nueva, y manda ahi el primer paquete
                        if(map.at(i).at(j).getPaquetesPreparados().size() <= 0){
                            queue<Paquete> aux;//Luego se envia al vector de colas de paquetes y se borra del buffer
                            aux.push( map.at(i).at(j).getBufferRouter().front());
                            map.at(i).at(j).getPaquetesPreparados().push_back(aux);
                            map.at(i).at(j).getBufferRouter().pop();
                        }
                        else{
                            //Si ya existen colas de paquetes en el vector, recorre cada cola, preguntando si alguna tiene el 
                            //mismo id de pertenencia que el paquete que se le quiere mandar.
                            //Si se encuentra, se manda alli y se quita del buffer
                            bool encontrado = false;
                            for(int iter = 0; iter < map.at(i).at(j).getPaquetesPreparados().size();iter++){
                                if(map.at(i).at(j).getPaquetesPreparados().at(iter).front().getIdPertenencia()
                                == map.at(i).at(j).getBufferRouter().front().getIdPertenencia() && encontrado == false){
                                    map.at(i).at(j).getPaquetesPreparados().at(iter).push(map.at(i).at(j).getBufferRouter().front());
                                    map.at(i).at(j).getBufferRouter().pop();
                                    encontrado = true;
                                }
                            }
                            //Si no se encuentra, se crea una nueva cola de paquetes y se manda al vector
                            if(encontrado == false){
                                    queue<Paquete> aux;
                                    aux.push( map.at(i).at(j).getBufferRouter().front());
                                    map.at(i).at(j).getPaquetesPreparados().push_back(aux);
                                    map.at(i).at(j).getBufferRouter().pop();
                                }
                        }
                }
            }
}


void Mapa::envioATerminales(){
    for(int i = 0; i < tamanioCuadradoMapa; i++) for(int j = 0; j < tamanioCuadradoMapa; j++){
        Router *r = &map.at(i).at(j);
        if(r->getIDRouter() != -1){
            for(int p = 0; p < r->getPaquetesPreparados().size(); p++){
                if(!r->getPaquetesPreparados().at(p).empty())
                //Si existen colas de paquetes, se pregunta si ya estan completas (pueden no estarlo)
                if(r->getPaquetesPreparados().at(p).front().getDivisionesTotales() == r->getPaquetesPreparados().at(p).size()){
                    //Las que esten completas, se envian al terminal que les corresponda, teniendo en cuenta
                    //el id del terminal, y el id de terminal de destino de la cola
                    //Y luego se quita del vector
                    for(int ter = 0; ter < 256; ter++){
                        if(r->getPaquetesPreparados().at(p).front().getIDDestinoTerminal() == r->getReceptor().at(ter).getIDTerminal()){
                            r->getReceptor().at(ter).recibePaquetes(r->getPaquetesPreparados().at(p));
                            r->getPaquetesPreparados().erase(r->getPaquetesPreparados().begin()+p);
                            break;
                        }
                    }break;
                }

            }

        }
    }//Automaticamente se envia a que los terminales armen las paginas que se les enviaron
    this->armadoDePaginas();
}

void Mapa::armadoDePaginas(){
    for(int i = 0; i < tamanioCuadradoMapa; i++){ for(int j = 0; j < tamanioCuadradoMapa; j++){
            Router *r = &map.at(i).at(j);
            if(r->getIDRouter() != -1){
                for(int ter = 0; ter < 256; ter++){
                    //Si un terminal recibio una cola paquetes, se envia a arme la pagina
                    //y se elimina la cola del vector
                    while(r->getReceptor().at(ter).getPaquetesRecibidos().size() > 0){
                        r->getReceptor().at(ter).rearmarPaginas(r->getReceptor().at(ter).getPaquetesRecibidos().back());
                        r->getReceptor().at(ter).getPaquetesRecibidos().pop_back();
                    }                    
                }
            }
        }
    }

}

void Mapa::printFinalDePaginas(){//Toma un router y terminal especificos, e imprime las paginas que tenga (Si es que tiene)
    int x,y;
    cout<<"\nIngresar Router a ver: ";cin>>y;
    cout<<"\nIngresar Terminal a ver: ";cin>>x;
    getRouterEspecifico(y).getTerminalEspecifico(x).getPaginasDisponibles();
}