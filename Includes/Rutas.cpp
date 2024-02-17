#include "Rutas.h" //PROBABLEMENTE INNECESARIO
void Rutas::calcularRuta(Mapa *m){
    for(int i = 0; i < m->getMapa().size(); i++)
        for(int j = 0; j < m->getMapa().size(); j++)
            if(m->getMapa().at(i).at(j).getIDRouter() != -1){
                bool encontrado = false;
                for(int k = 0; k < 8; k++){
                    if((encontrado == false) && (m->getMapa().at(i).at(j).getBufferRedireccionRouter().getPrimero().getIDDestino() 
                    == m->getMapa().at(i).at(j).getCercanos().at(k)->getIDRouter())){
                        m->getMapa().at(i).at(j).setSiguienteInmediato(m->getMapa().at(i).at(j).getCercanos().at(k));
                        encontrado = true;
                    }
                }
                if(encontrado == false){
                    Router *inicio = &m->getMapa().at(i).at(j);
                    int final = m->getMapa().at(i).at(j).getBufferRedireccionRouter().getPrimero().getIDDestino();
                    calcRuta(inicio,inicio,final,m);
                }
            }
}

void Rutas::calcRuta(Router* inicio, Router* actual, int IDfinal, Mapa *m){




    return calcRuta(inicio, actual, IDfinal, m);
}