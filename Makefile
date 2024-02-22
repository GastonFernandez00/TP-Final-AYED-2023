all: compile link clean clear execute

compile:
	g++ ./Includes/Mapa.cpp ./Includes/Paquete.cpp ./Includes/Paginas.cpp ./Includes/Terminal.cpp ./Includes/Extras.cpp ./Includes/Router.cpp main.cpp -c

link: 
	g++ Mapa.o Paquete.o Paginas.o Terminal.o Extras.o Router.o main.o -o main.exe

execute:
	.\main.exe

clean:
	rm -f *.o 

clear:
	clear
