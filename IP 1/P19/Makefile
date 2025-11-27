APP=agenda.exe
MAIN=agenda.c
TOOLS_OBJ=tools.o
TOOLS_H=tools.h
TOOLS=tools.c

run: $(APP)
	./$(APP)

$(APP): $(MAIN) $(TOOLS_H) $(TOOLS_OBJ) agendalib.h agendalib.o
	gcc $(MAIN) $(TOOLS_OBJ) agendalib.o -o $(APP)

$(TOOLS_OBJ): $(TOOLS)
	gcc -c $(TOOLS) -o $(TOOLS_OBJ)

agendalib.o: agendalib.h agendalib.c
	gcc -c agendalib.c  -o agendalib.o