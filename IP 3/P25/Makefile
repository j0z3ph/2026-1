MAIN=main.c
COMPILER=gcc
APP=main.exe
GRAPHICS_H=graficos.h
GRAPHICS_LIB=graficos.o
GRAPHICS_SRC=graficos.c
WIN_FLAGS=-mwindows
run: $(APP)
	./$(APP)

$(APP): $(MAIN) $(GRAPHICS_H) $(GRAPHICS_LIB)
	$(COMPILER) -o $(APP) $(GRAPHICS_LIB) $(MAIN) $(WIN_FLAGS)

$(GRAPHICS_LIB): $(GRAPHICS_H) $(GRAPHICS_SRC)
	$(COMPILER) -c $(GRAPHICS_SRC) -o $(GRAPHICS_LIB)

clean: 
	del $(APP) $(GRAPHICS_LIB)