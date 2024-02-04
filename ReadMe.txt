/*
    Ver:
      
        >En la clase Terminal, probablemente haga falta un Cola<Pagina> ó mejor un vector<Pagina>, y una funcion
        que rearme las paginas a partir de los paquetes. Tal vez el rearmado se haga en el router

        >Posiblemente eliminar las funciones:
            -> Router: atributo y funciones de posicion
            -> Terminal: "Envio" 
            -> Cola: "cambiarEstado" y su atributo "estado"

        >Se Tiene que enviar Paquete por paquete
                        
        >La cola donde se acumulan los paquetes una vez enviados desde el router, deberian estar en cada terminal, no en el main

        >Ver de asociar una Bandwidth, que podría ser la cantidad de datos que puede descolarse a la vez. Tal vez funcion
        tipo Cola<Paquete> Reenviar(){
                Cola<Paquete> pkgReenviados;
                for(){
                    pkgReenviados.encolar(buffer.getPrimero());  
                    buffer.descolar();
                } 
                return pkgReenviados;
            }

        --->>> Al terminar, limpiar clases, y comentar funciones apropiadamente

*/

/*
    Known Problems: < Por ahora ninguno nuevo >

*/

/*  Notas:

        >Para simular la aleatoriedad puedo usar la libreria de time, en concreto la funcion 
        time(NULL), que devuelve los segundos desde EPOCH
    
*/