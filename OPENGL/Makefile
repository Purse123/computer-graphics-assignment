CFLAGS= $(shell pkg-config --cflags glfw3)
LIBS= $(shell pkg-config --libs glfw3) -lm -lGL

q1: basics.c
	gcc basics.c $(CFLAGS) $(LIBS) -o basics

clean:
	rm basics
