CC=gcc
LIBS= -lSDL_bgi -lSDL2 -lm
CFLAGS= -Wall

dda: 1-dda.c
	$(CC) -o dda 1-dda.c $(LIBS) $(CFLAGS)

bla: 2-bresenhams.c
	$(CC) -o bla 2-bresenhams.c $(LIBS) $(CFLAGS)

sdl: dda-sdl3.c
	$(CC) -o dda-sdl dda-sdl3.c $(pkg-config --cflags --libs sdl3)

#raylib:
# cc main.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
clean:
	rm -f dda dda-sdl bla
