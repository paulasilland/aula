CFLAGS = -I../..
ifeq ($(OS),Windows_NT)
	LDFLAGS = -s -lopengl32 -lgdi32
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Darwin)
		LDFLAGS = -framework OpenGL -framework Cocoa
	else ifeq ($(UNAME_S),Linux)
		LDFLAGS = -s -lGLU -lGL -lX11
	endif
endif

visor: tigr.o visor.o 
	gcc -o visor visor.o tigr.o $(CFLAGS) $(LDFLAGS)
tigr.o: tigr/tigr.c 
	gcc -c tigr/tigr.c 
visor.o: visor.c 
	gcc -c visor.c 