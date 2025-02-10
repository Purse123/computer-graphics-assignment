#include <stdio.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_video.h>
#include <SDL3/SDL_render.h>

#define WINDOW_HEIGHT 400
#define WINDOW_WIDTH 600

int main() {
/*
 * FLAGS
 * #define SDL_INIT_AUDIO      0x00000010u `SDL_INIT_AUDIO` implies `SDL_INIT_EVENTS`
 * #define SDL_INIT_VIDEO      0x00000020u `SDL_INIT_VIDEO` implies `SDL_INIT_EVENTS`, should be initialized on the main thread
 * #define SDL_INIT_JOYSTICK   0x00000200u `SDL_INIT_JOYSTICK` implies `SDL_INIT_EVENTS`, should be initialized on the same thread
 * as SDL_INIT_VIDEO on Windows if you don't set SDL_HINT_JOYSTICK_THREAD
 * #define SDL_INIT_HAPTIC     0x00001000u
 * #define SDL_INIT_GAMEPAD    0x00002000u `SDL_INIT_GAMEPAD` implies `SDL_INIT_JOYSTICK`
 * #define SDL_INIT_EVENTS     0x00004000u
 * #define SDL_INIT_SENSOR     0x00008000u `SDL_INIT_SENSOR` implies `SDL_INIT_EVENTS`
 * #define SDL_INIT_CAMERA     0x00010000u `SDL_INIT_CAMERA` implies `SDL_INIT_EVENTS`
*/
    SDL_Init(SDL_INIT_VIDEO);

    // SDL_Window * SDL_CreateWindow(const char *title, int w, int h, SDL_WindowFlags flags);
    SDL_Window *window = SDL_CreateWindow("--Dont look here you Nasty--", WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_OPENGL);
    if (window == NULL) {
        printf("Window unable to create\n");
    }

    // SDL_Renderer * SDL_CreateRenderer(SDL_Window *window, const char *name);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, NULL);

    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    SDL_Delay(3000);
}
