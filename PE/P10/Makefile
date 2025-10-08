APP=app.exe

run: $(APP)
	./$(APP)


$(APP): inversa.c matrices.h matrices.o
	gcc inversa.c matrices.o -o $(APP)

matrices.o: matrices.c
	gcc -c matrices.c -o matrices.o