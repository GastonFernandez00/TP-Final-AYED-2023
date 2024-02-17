/*
    Ver:
        >>>>>GRAFO PONDERADO Ó CON PESO

        >>>>>Calcula 1 vez los pesos

        >El mapa puede tener alguna funcion tipo rutas(id_inicio,id_final,Router *actual). Necesita 
        una funcion extra que indexe las rutas <---> Tal vez sea una funcion externa, a la que acceda el mapa
        
        >Ver que en el empaquetado, no se estén empaquetando siempre las mismas paginas

        >La Bandwidth debería ser la cantidad de paquetes que puede enviar un router

        >En la clase Terminal, probablemente haga falta un Cola<Pagina> ó mejor un vector<Pagina>, y una funcion
        que rearme las paginas a partir de los paquetes. Tal vez el rearmado se haga en el router

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

        >Posiblemente eliminar las funciones:
            -> Router: atributo y funciones de posicion
            -> Terminal: "Envio" 
            -> Cola: "cambiarEstado" y su atributo "estado"

        --->>> Al terminar, limpiar clases, y comentar funciones apropiadamente

*/

/*
    Known Problems: <>
        ::::IMPORTANTES::::
        >En el mapa, estoy creando copias de los routers existentes en vez de usar
        punteros a los mismos. Por lo que una vez creados y almacenados en el mapa,
        se deben alterar esos, y no los originales

        >Si intento aniadir nuevos routers, fuera del vector<Router> inicial, no puedo checkear los IDs. Habría
        que modificar la funcion checkIDRouter para que tome en cuenta vector<vector<Router>>
        
        ::::INSIGNIFICANTES::::
        >Si la cantidad de routers < 8, los routers en la lista de cercanos se repiten.

        >Cuando un router se intenta poner en la posicion de otro, los empieza a colocar desde (0,0), haciendo que
        que la parte superior izquierda normalmente esté más cargada
        
*/

/*  Notas:

        >Para simular la aleatoriedad puedo usar la libreria de time, en concreto la funcion 
        time(NULL), que devuelve los segundos desde EPOCH
    
*/