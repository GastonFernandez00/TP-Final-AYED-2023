all: compile link execute clean
# all2: recompilarTodo linkTodo execute
# clean:
# 	rm -f *.o *.exe

compile:
	g++ Cola.cpp Paquete.cpp Paginas.cpp Terminal.cpp Extras.cpp -c

link: 
	g++ Cola.o Paquete.o Paginas.o Terminal.o Extras.o -o prog.exe

execute:
	.\prog.exe

clean:
	rm -f *.o

# recompilarTodo:
# 	g++ Cola.cpp Paquete.cpp Paginas.cpp Terminal.cpp Router.cpp Extras.cpp -c

# linkTodo:
# 	g++ Cola.o Paquete.o Extras.o Paginas.o Router.o Terminal.o -o prog

