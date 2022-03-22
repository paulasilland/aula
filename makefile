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

VISORGUI: tigr.o VISORGUI.o GUIICONS.o GUIXML.o xml.o
	gcc -o VISORGUI VISORGUI.o tigr.o GUIICONS.o GUIXML.o xml.o $(CFLAGS) $(LDFLAGS)
tigr.o: tigr/tigr.c 
	gcc -c tigr/tigr.c 
VISORGUI.o: VISORGUI.c 
	gcc -c VISORGUI.c 
GUIICONS.o: GUIICONS.c 
	gcc -c GUIICONS.c 
GUIXML.o: GUIXML.c
	gcc -c GUIXML.c
xml.o: xml.c/src/xml.c
	gcc -c xml.c/src/xml.c

clean:
	del VISORGUI.exe VISORGUI.o tigr.o GUIICONS.o GUIXML.o xml.o