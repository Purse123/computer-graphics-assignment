CFLAGS= $(shell pkg-config --cflags glfw3) $(shell pkg-config --cflags glew)
LIBS= $(shell pkg-config --libs glfw3) $(shell pkg-config --libs glew) -lm -lGL

q1: basics.c
	gcc basics.c $(CFLAGS) $(LIBS) -o basics
q11: 11-opengl_line.c
	gcc 11-opengl_line.c $(CFLAGS) $(LIBS) -o line
q12: 12-traingle.c
	gcc 12-traingle.c $(CFLAGS) $(LIBS) -o triangle

clean:
	rm basics line triangle
