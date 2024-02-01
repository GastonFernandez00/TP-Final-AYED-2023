all: compile link execute clean

compile:
	g++ ./Includes/Cola.cpp ./Includes/Paquete.cpp ./Includes/Paginas.cpp ./Includes/Terminal.cpp ./Includes/Extras.cpp -c

link: 
	g++ Cola.o Paquete.o Paginas.o Terminal.o Extras.o -o prog.exe

execute:
	.\prog.exe

clean:
	rm -f *.o *.exe