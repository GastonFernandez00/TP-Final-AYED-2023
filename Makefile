all: compile link execute clean

compile:
	g++ ./Includes/Cola.cpp ./Includes/Paquete.cpp ./Includes/Paginas.cpp ./Includes/Terminal.cpp ./Includes/Extras.cpp ./Includes/Router.cpp -c

link: 
	g++ Cola.o Paquete.o Paginas.o Terminal.o Extras.o Router.o -o prog.exe

execute:
	.\prog.exe

clean:
	rm -f *.o *.exe