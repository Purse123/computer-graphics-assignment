CC=gcc
LIBS= -lSDL_bgi -lSDL2
CFLAGS= -Wall

dda: 1-dda.c
	$(CC) -o dda 1-dda.c $(LIBS) $(CFLAGS)

sdl: dda-sdl3.c
	$(CC) -o dda-sdl dda-sdl3.c $(pkg-config --cflags --libs sdl3)

clean:
	rm -f dda dda-sdl
