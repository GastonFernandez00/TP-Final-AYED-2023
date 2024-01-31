all: compile link execute 
all2: recompilarTodo linkTodo executeTodo
cleanTodo:
	rm -f *.o *.exe

compile:
	g++ -c

link: 
	g++  -o prog.exe

execute:
	.\prog.exe

clean:
	rm -f *.o 

recompilarTodo:
	g++ Colas.cpp Nodos.cpp Listas.cpp Paquete.cpp Extras.cpp Paginas.cpp Router.cpp Terminal.cpp -c

linkTodo:
	g++ Colas.o Nodos.o Listas.o Paquete.o Extras.o Paginas.o Router.o Terminal.o -o prog

executeTodo:
	.\prog.exe