run: programa.exe
	./programa.exe

programa.exe: inversa.c matrices.h matrices.o
	gcc inversa.c matrices.o -o programa.exe

matrices.o: matrices.c
	gcc -c matrices.c -o matrices.o