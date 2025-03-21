CC=gcc
# LIBS= -lSDL_bgi -lSDL2 -lm
LIBS= -lSDL_bgi -lm
OPENGL_LIBS=$(pkg-config --cflags --libs glfw3) $(pkg-config --cflags --libs gl) -lm
CFLAGS= -Wall

dda: 1-dda.c
	$(CC) -o dda 1-dda.c $(LIBS) $(CFLAGS)

bla: 2-bresenhams.c
	$(CC) -o bla 2-bresenhams.c $(LIBS) $(CFLAGS)

circle: 3-mid-point.c
	$(CC) -o circle 3-mid-point.c $(LIBS) $(CFLAGS)

ellipse: 4-midpoint-ellipse.c
	$(CC) -o ellipse 4-midpoint-ellipse.c $(LIBS) $(CFLAGS)

2d: 5-2d-trans.c
	$(CC) -o 2d-transform 5-2d-trans.c $(LIBS) $(CFLAGS)

bz: 6-bezier-curve.c
	$(CC) -o 6-bezier-curve 6-bezier-curve.c $(LIBS) $(CFLAGS)

3D: 7-3D-transformation.c
	$(CC) -o 3d-transformation 7-3D-transformation.c $(LIBS) $(CFLAGS)

sutherland: 8-sutherland.c
	$(CC) -o sutherland 8-sutherland.c $(LIBS) $(CFLAGS)

liang-barsky: 9-liang-barsky.c
	$(CC) -o liang-barsky 9-liang-barsky.c $(LIBS) $(CFLAGS)

gl_line: 
	$(CC) -o $(OPENGL_LIBS) $(CFLAGS)

#sdl:
sdl-dda: dda-sdl3.c
	$(CC) -o dda-sdl dda-sdl3.c $(pkg-config --cflags --libs sdl3)

#raylib:
	cc main.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
clean:
	rm -f dda dda-sdl bla circle ellipse 2d-transform 6-bezier-curve 3d-transformation sutherland liang-barsky
