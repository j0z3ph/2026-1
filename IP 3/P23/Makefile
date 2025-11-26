APP=agenda.exe
MAIN=agenda.c
TOOLS_OBJ=tools.o
TOOLS_H=tools.h
TOOLS=tools.c

AGENDALIB_OBJ=agendalib.o
AGENDALIB_SRC=agendalib.c
AGENDALIB_H=agendalib.h

run: $(APP)
	./$(APP)

$(APP): $(MAIN) $(TOOLS_H) $(TOOLS_OBJ) $(AGENDALIB_OBJ) $(AGENDALIB_H)
	gcc $(MAIN) $(TOOLS_OBJ) $(AGENDALIB_OBJ) -o $(APP)

$(TOOLS_OBJ): $(TOOLS)
	gcc -c $(TOOLS) -o $(TOOLS_OBJ)

$(AGENDALIB_OBJ): $(AGENDALIB_H) $(AGENDALIB_SRC)
	gcc -c $(AGENDALIB_SRC) -o $(AGENDALIB_OBJ)