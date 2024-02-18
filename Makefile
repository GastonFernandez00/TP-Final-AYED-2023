all: compile link clean clear execute

compile: BORRAR
	g++ ./Includes/Mapa.cpp ./Includes/Cola.cpp ./Includes/Paquete.cpp ./Includes/Paginas.cpp ./Includes/Terminal.cpp ./Includes/Extras.cpp ./Includes/Router.cpp main.cpp -c

link: 
	g++ Prueba_Envio_De_Paquete.o Mapa.o Cola.o Paquete.o Paginas.o Terminal.o Extras.o Router.o main.o -o main.exe

execute:
	.\main.exe

clean:
	rm -f *.o 

clear:
	clear

BORRAR:
	c++ Prueba_Envio_De_Paquete.cpp -c