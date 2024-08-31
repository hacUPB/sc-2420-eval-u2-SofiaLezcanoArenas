#include <stdio.h>
#include <SDL.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define FALSE 0;
#define TRUE 1;

int game_is_running = FALSE;

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

int initialize_window(void) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        fprintf(stderr, "Error initializing SDL.\n");
        return FALSE;
    }
    window = SDL_CreateWindow(
        "A simple game loop using C & SDL",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        0
    );
    if (!window) {
        fprintf(stderr, "Error creating SDL Window.\n");
        return FALSE;
    }
    renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer) {
        fprintf(stderr, "Error creating SDL Renderer.\n");
        return FALSE;
    }
    return TRUE;
}

void setup(void) 
{
	printf("Setup()\n");
}

void update(void) 
{
	printf("Update()\n");
}

void render(void) 
{
	printf("Render()\n");
}

int main(int argc, char* args[]) 
{
    game_is_running = initialize_window();
	setup();

    while (game_is_running)
    {
        update();
	    render();
    }
	
	return 0;
}