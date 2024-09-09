#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>
#include <math.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

//punteros
SDL_Window* window = NULL; //se crea una ventana
SDL_Renderer* renderer = NULL; //se crea un renderer para poder renderizar cosas en la ventana

//variables
int game_is_running = false;
int last_frame_time = 0;

int centerX, centerY, radius, x, y;

int initialize_window(void) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        fprintf(stderr, "Error initializing SDL.\n");
        return false; //el condicional nos ayuda a verificar si hay errores en la inicialización de SDL
    }
    window = SDL_CreateWindow(
        "A simple game loop using C & SDL",
        SDL_WINDOWPOS_CENTERED, //posición en x
        SDL_WINDOWPOS_CENTERED, //posición en y
        WINDOW_WIDTH, //ancho de la ventana
        WINDOW_HEIGHT, //alto de la ventana
        5
    );
    if (!window) {
        fprintf(stderr, "Error creating SDL Window.\n");
        return false; //el condicional nos ayuda a verificar si hay errores en la creación de la ventana
    }
    renderer = SDL_CreateRenderer(window, -1, 0); //(ventana a donde estará atado el rederer, -1 es para usar el display driver por defecto, banderas especiales para el render)
    if (!renderer) {
        fprintf(stderr, "Error creating SDL Renderer.\n");
        return false; //el condicional nos ayuda a verificar si hay errores en la creación del renderer
    }
    return true;
}

void setup(void) 
{
    centerX = 200;
    centerY = 100;
    radius = 40;
}

void update(void)
{
    SDL_Event event; //se crea un evento SDL llamado evento
    while (SDL_PollEvent(&event)) //mientras que haya un evento
    {
        switch (event.type)
        {
        case SDL_QUIT: // si se hace clic en la x de la ventana o alt+4. Nota: aquí no funciona automáticamente
            game_is_running = false; //el game loop se detendrá
            break;
        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_ESCAPE) //si se presiona Escape
            {
                game_is_running = false; //el game loop se detendrá
            }
            break;
        }
    }

}

void render(void) 
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // (R, G, B, alpha) para definir el color a usar en lo próximo a dibujar
    SDL_RenderClear(renderer);

    // Rectángulo
    SDL_SetRenderDrawColor(renderer, 200, 0, 100, 255);
    SDL_Rect rect = 
    {
        0, //posición en x
        0, //posición en y
        100, //ancho
        60 //alto
    };
    SDL_RenderDrawRect(renderer, &rect); // si se quiere relleno, puede usarse SDL_RenderFillRect(renderer, referencia)

    //Círculo
    SDL_SetRenderDrawColor(renderer, 100, 0, 200, 255);
    for (x = -radius; x <= radius; x++) 
    {
        y = (int)sqrt(radius * radius - x * x);
        SDL_RenderDrawPoint(renderer, centerX + x, centerY + y);
        SDL_RenderDrawPoint(renderer, centerX + x, centerY - y);

    }

    //Línea
    SDL_SetRenderDrawColor(renderer, 0, 100, 200, 255);
    SDL_RenderDrawLine(renderer, 300, 400, 700, 500); //(renderer, x1, y1, x2, y2)

    SDL_RenderPresent(renderer); //cambio de buffer para evitar efecto glitch
}

void destroy_window(void) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int main(int argc, char* args[]) {
    game_is_running = initialize_window();

    setup();

    while (game_is_running) {
        update();
        render();
    }

    destroy_window();

    return 0;
}
