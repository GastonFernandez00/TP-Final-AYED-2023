/*
    Ver:
      
        >En la clase Terminal, probablemente haga falta un Cola<Pagina> ó mejor un vector<Pagina>, y una funcion
        que rearme las paginas a partir de los paquetes. Tal vez el rearmado se haga en el router

        >Posiblemente eliminar funcion "Envio" de "Terminal", "cambiarEstado" y su atributo "estado" de "Cola", ya no tiene sentido. 

        >Se Tiene que enviar Paquete por paquete
                        
        >Cambiar la posicion por una forma matricial 100x100

        >Crear un mapa y asociar una posicion a un router ó su ID// Esto no tiene sentido, tiene que ser por ancho de banda
        ó sea, el "peso"  (tamanio de la cola buffer redestino) de cada router

        >La cola donde se acumulan los paquetes, deberian estar en el la terminal, no en el main

        >Para simular la aleatoriedad puedo usar la libreria de time, en concreto la funcion time(NULL), que devuelve los segundos desde EPOCH
   
*/

/*
    Known Problems:

        >>¡A veces! la creacion de routers ó de routers+terminales genera problemas, aparentemente de memoria. 
        Ver checkID clase terminal y tal vez la de pagina
        
        >La funcion checkID de "Terminal" ó "Pagina" crea algun problema con los punteros a veces. Si hay tiempo, checkear, 
        no es crucial



*/