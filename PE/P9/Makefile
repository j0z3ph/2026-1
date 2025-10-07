run: programa.exe
	./programa.exe

programa.exe: funciones.c operaciones.h operaciones.o
	gcc funciones.c operaciones.o -o programa.exe

operaciones.o: operaciones.c
	gcc -c operaciones.c -o operaciones.o