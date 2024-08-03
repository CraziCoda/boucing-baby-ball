# compile cpp with glut and opengl 

CC = g++
LFLAGS = -lglut -lGLU -lGL
SOURCES = main.cpp

all: $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) $(LFLAGS) -o main

clean:
	rm -f main