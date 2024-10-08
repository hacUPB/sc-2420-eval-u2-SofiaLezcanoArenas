#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>
#include <math.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define FPS 30
#define FRAME_TIME (1000/FPS)

//punteros
SDL_Window* window = NULL; //se crea una ventana
SDL_Renderer* renderer = NULL; //se crea un renderer para poder renderizar cosas en la ventana

//variables
int game_is_running = false;
int last_frame_time = 0;

int centerX, centerY, radius, x, y;

int rectX, rectY, rectW, rectH;

int lx1, ly1, lx2, ly2;

int initialize_window(void) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        fprintf(stderr, "Error initializing SDL.\n");
        return false; //el condicional nos ayuda a verificar si hay errores en la inicializaci�n de SDL
    }
    window = SDL_CreateWindow(
        "A simple game loop using C & SDL",
        SDL_WINDOWPOS_CENTERED, //posici�n en x
        SDL_WINDOWPOS_CENTERED, //posici�n en y
        WINDOW_WIDTH, //ancho de la ventana
        WINDOW_HEIGHT, //alto de la ventana
        5
    );
    if (!window) {
        fprintf(stderr, "Error creating SDL Window.\n");
        return false; //el condicional nos ayuda a verificar si hay errores en la creaci�n de la ventana
    }
    renderer = SDL_CreateRenderer(window, -1, 0); //(ventana a donde estar� atado el rederer, -1 es para usar el display driver por defecto, banderas especiales para el render)
    if (!renderer) {
        fprintf(stderr, "Error creating SDL Renderer.\n");
        return false; //el condicional nos ayuda a verificar si hay errores en la creaci�n del renderer
    }
    return true;
}

void setup(void)
{
    centerX = 200;
    centerY = 100;
    radius = 40;

    rectX = 500;
    rectY = 200;
    rectW = 100;
    rectH = 60;

    lx1 = 300;
    ly1 = 400;
    lx2 = 700;
    ly2 = 500;
}

void update(void)
{
    int time_to_wait = FRAME_TIME - (SDL_GetTicks() - last_frame_time);

    if (time_to_wait > 0 && time_to_wait <= FRAME_TIME)
    {
        SDL_Delay(time_to_wait);
    }

    float delta_time = (SDL_GetTicks() - last_frame_time) / 1000.0f; // Get delta_time factor converted to seconds to be used to update objects

    last_frame_time = SDL_GetTicks(); // Store the milliseconds of the current frame to be used in the next one

    SDL_Event event; //se crea un evento SDL llamado evento
    while (SDL_PollEvent(&event)) //mientras que haya un evento
    {
        switch (event.type)
        {
        case SDL_QUIT: // si se hace clic en la x de la ventana o alt+4. Nota: aqu� no funciona autom�ticamente
            game_is_running = false; //el game loop se detendr�
            break;
        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_ESCAPE) //si se presiona Escape
            {
                game_is_running = false; //el game loop se detendr�
            }
            break;
        }
    }

    //Movimiento de figuras
    //rect�ngulo hacia la izquierda
    rectX -= (120 * delta_time);
    //c�rculo hacia abajo
    centerY -= (60 * delta_time);
    //l�nea hacia arriba
    ly1 -= (120 * delta_time);
    ly2 -= (120 * delta_time);
}

void render(void)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // (R, G, B, alpha) para definir el color a usar en lo pr�ximo a dibujar
    SDL_RenderClear(renderer);

    // Rect�ngulo
    SDL_SetRenderDrawColor(renderer, 200, 0, 100, 255);
    SDL_Rect rect =
    {
        rectX, //posici�n en x
        rectY, //posici�n en y
        rectW, //ancho
        rectH //alto
    };
    SDL_RenderDrawRect(renderer, &rect); // si se quiere relleno, puede usarse SDL_RenderFillRect(renderer, referencia)
    //C�rculo
    SDL_SetRenderDrawColor(renderer, 100, 0, 200, 255);
    for (x = -radius; x <= radius; x++)
    {
        y = (int)sqrt(radius * radius - x * x);
        SDL_RenderDrawPoint(renderer, centerX + x, centerY + y);
        SDL_RenderDrawPoint(renderer, centerX + x, centerY - y);
    }
    //L�nea
    SDL_SetRenderDrawColor(renderer, 0, 100, 200, 255);
    SDL_RenderDrawLine(renderer, lx1, ly1, lx2, ly2); //(renderer, x1, y1, x2, y2)

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