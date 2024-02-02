/*
    Ver:
        
        >Posiblemente eliminar funcion "Envio" de "Terminal", "cambiarEstado" y su atributo "estado" de "Cola", ya no tiene sentido. 

        >Se Tiene que enviar Paquete por paquete
        
        >Como acceder a los objetos dentro de cada buffer
                
        >Cambiar la posicion por una forma matricial 100x100

        >Crear un mapa y asociar una posicion a un router ó su ID// Esto no tiene sentido, tiene que ser por ancho de banda
        ó sea, el "peso"  (tamanio de la cola buffer redestino) de cada router

        >La cola donde se acumulan los paquetes, deberian estar en el la terminal, no en el main

        >Para simular la aleatoriedad puedo usar la libreria de time, en concreto la funcion time(NULL), que devuelve los segundos desde EPOCH
   
*/

/*
    Known Problems:

        >La funcion checkID de "Terminal", "Pagina" ó "Router" crea algun problema con los punteros a veces. Si hay tiempo, checkear, 
        no es inminente



*/