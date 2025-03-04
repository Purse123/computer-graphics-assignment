CC=gcc
# LIBS= -lSDL_bgi -lSDL2 -lm
LIBS= -lSDL_bgi -lm
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

#sdl:
sdl-dda: dda-sdl3.c
	$(CC) -o dda-sdl dda-sdl3.c $(pkg-config --cflags --libs sdl3)

#raylib:
	cc main.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
clean:
	rm -f dda dda-sdl bla circle ellipse 2d-transform 6-bezier-curve
