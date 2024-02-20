/*  Notas:
        >Las Paginas DEBEN saber qué Routers Existen (Los IDs)

        >Para aleatoriedad (Desde ahora) usar random_device y alguna distribucion probabilistica,
        como la uniforme    
*/

/*
    Ver:
        >Si los routers que se establecen como cercano, no pueden ir arriba ó abajo, para acercarse al router 
        de destino final, empiezan a pasarse el pkg entre ellos y se queda trabado

        >Controlar:
             Ahora mismo cada terminal envía la TOTALIDAD de los paquetes que tiene almacenado, al o mejor debería hacer
            sólo envía 1 (un) paquete por vez

        >En la clase Terminal, probablemente haga falta un Cola<Pagina> ó mejor un vector<Pagina>, y una funcion
        que rearme las paginas a partir de los paquetes. Tal vez el rearmado se haga en el mapa

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

