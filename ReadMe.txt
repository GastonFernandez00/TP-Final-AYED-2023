/*     
        Final Regular Algoritmos y Estructuras de Datos (AYED)

        >Alumno: Fernández, Gastón Emanuel.
        >Matrícula: 42.386.463.
        >Carrera: Ingeniería en Computación.
*/

/*  Notas:
        >Las Paginas DEBEN saber qué Routers Existen (Los IDs)

        >Para aleatoriedad (Desde ahora) usar random_device y alguna distribucion probabilistica,
        como la uniforme    
*/

/*  Ver:
        >Controlar:
             Ahora mismo cada terminal envía la TOTALIDAD de los paquetes que tiene almacenado, al o mejor debería hacer
            sólo envía 1 (un) paquete por vez

        --->>> Al terminar, limpiar clases, y comentar funciones apropiadamente
*/

/*  Known Problems: <>
        ::::IMPORTANTES::::
        >En el mapa, estoy creando copias de los routers existentes en vez de usar
        punteros a los mismos. Por lo que una vez creados y almacenados en el mapa,
        se deben alterar esos, y no los originales

        >Si intento aniadir nuevos routers, fuera del vector<Router> inicial, no puedo checkear los IDs. Habría
        que modificar la funcion checkIDRouter para que tome en cuenta vector<vector<Router>>
        
        >Si los routers que se establecen como cercano, no pueden ir arriba ó abajo, para acercarse al router 
        de destino final, empiezan a pasarse el pkg entre ellos y se queda trabado
        
        ::::INSIGNIFICANTES::::
*/

