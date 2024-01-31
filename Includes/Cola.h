#ifndef COLA_H
#define COLA_H
#include <iostream>
#include <queue>
#include <random>
using namespace std;

/*  Clase Cola
*   @param T
*/
class Cola{
private:
    std::queue<int> c;
    int id_Cola = -1;
    int id_Destino = -1;
    int id_Destino_Terminal = -1;
    bool estado = false;

public:

    //  Constructor de Clase: Genera una nueva cola tipo FIFO
    Cola();

    //  Destructor del Objeto    
    ~Cola();

    /*Establece el id de la cola
        @param int
    */
    void setIDCola();

    /*Establece el id de la cola
        @param int
    */
    void setIDCola(int);

    /*  Establece el ID de destino de la cola, pero sin parametros, aleatoriamente
    */
    void setIDDestino();    
    
    /*  Establece el ID de destino de la cola
        @param int
    */
   void setIDDestino(int);
    
    /*  Devuelve el ID del terminal a donde debe ir la cola
        @returns int
    */
    void setidDestinoTerminal();

    /*  Establece el Id de la computadora de destino.
        Si cada router tiene 256 (0 - 255) computadoras, cada una 
        esta numerada de esa forma, independiente de las otras que esten conectadas
        a otros routers
        @param int
    */
    void setidDestinoTerminal(int);

    /*Cambia el estado de la cola, segun este lista para enviarse o no*/
    void cambiarEstado();
    
    //  Encolar: Introduce un nuevo dato a la cola
    //  @param   T
    void encolar(int);

    //  Elimina el dato mas antiguo de la cola
    void desencolar();

    /*  Vacia la cola  */
    void vaciarCola();

    //  Imprime la cola, no recibe parametros
    void imprimirCola();

    //  Devuelve la Cola
    queue<int> getCola();

    //  Devuelve el dato mas antiguo de la cola, pero no lo elimina.
    //  @returns T
    int getPrimero();

    //  Devuelve el dato mas reciente de la cola, pero no lo elimina
    //  @returns T
    int getUltimo();

    /*  Devuelve el Id de la cola
        @returns int
    */
    int getIDCola();

     /*  Devuelve el Id de del router a donde debe ir la cola
        @returns int
    */
    int getIDDestino();

    /*  Establece el Id de la computadora de destino.
        Si cada router tiene 256 (0 - 255) computadoras, cada una 
        esta numerada de esa forma, independiente de las otras que esten conectadas
        a otros routers. Pero sin parametros.
    */
    int getIDDestinoTerminal();

    //  Pregunta si la Cola esta vacia
    //  @returns Boolean
    bool colaEmpty();

    //  Devuelve el tamaño de la Cola
    //  @returns int
    int sizeCola();

    /*  Devuelve el estado de la cola, si esta listo para enviarse o no*/
    bool getEstado();
    


};
#endif