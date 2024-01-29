all1: compile link execute 
all2: compile_cola link_cola execute_cola clean_cola

compile: 
	g++ Terminal.cpp Router.cpp Extras.cpp -c

link:
	g++ Nodos.o Listas.o Colas.o Paginas.o Terminal.o Router.o Extras.o -o prog

execute:
	.\prog.exe

clean:
	rm -f prog *.o *.ghc

compile_cola:
	g++ Cola.cpp -c

link_cola:
	g++ Cola.o -o Cola.exe

execute_cola:
	.\Cola.exe

clean_cola:
	rm -f *.o *.ghc