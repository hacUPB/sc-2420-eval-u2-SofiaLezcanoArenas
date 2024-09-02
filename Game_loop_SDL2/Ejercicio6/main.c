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

int centerX, centerY, radius, x, y, cirV;

int rectX, rectY, rectW, rectH, rectV;

int lx1, ly1, lx2, ly2, lV;

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
    cirV = 60;

    rectX = 500;
    rectY = 200;
    rectW = 100;
    rectH = 60;
    rectV = 120;

    lx1 = 300;
    ly1 = 400;
    lx2 = 700;
    ly2 = 500;
    lV = 180;
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

    //Movimiento de figuras
    //rectángulo hacia la izquierda
    rectX -= (rectV * delta_time);
    //círculo hacia abajo
    centerY -= (cirV * delta_time);
    //línea hacia arriba
    ly1 -= (lV * delta_time);
    ly2 -= (lV * delta_time);

    //Colisiones con la ventana
    //Rectángulo
    if (rectX < 0)
    {
        rectX = 0; //para que no pase del borde izquierdo
        rectV = -rectV; // para que se mueva en la dirección opuesta
    }
    if (rectX + rectW > WINDOW_WIDTH)
    {
        rectX = WINDOW_WIDTH - rectW; //para que no pase del borde derecho
        rectV = -rectV;
    }
    if (rectY < 0)
    {
        rectY = 0; //para que no pase del borde superior
        rectV = -rectV; // para que se mueva en la dirección opuesta
    }
    if (rectY + rectH > WINDOW_HEIGHT)
    {
        rectY = WINDOW_HEIGHT - rectH;
        rectV = -rectV;
    }
    //Círculo
    if (centerX - radius < 0)
    {
        centerX = centerX + radius; //para que no pase del borde izquierdo
        cirV = -cirV; // para que se mueva en la dirección opuesta
    }
    if (centerX + radius > WINDOW_WIDTH)
    {
        centerX = WINDOW_WIDTH - radius;
        cirV = -cirV;
    }
    if (centerY - radius < 0)
    {
        centerY = centerY + radius; //para que no pase del borde superior
        cirV = -cirV; // para que se mueva en la dirección opuesta
    }
    if (centerY + radius > WINDOW_HEIGHT)
    {
        centerY = WINDOW_HEIGHT - radius; //para que no pase del borde inferior
        cirV = -cirV;
    }
    //linea
    if (lx1 < 0)
    {
        lx1 = 0;
        lx2 += 1;
        lV = -lV;
    }
    if (lx2 > WINDOW_WIDTH)
    {
        lx2 = WINDOW_WIDTH;
        lx1 -= 1;
        lV = -lV;
    }

    if (ly1 < ly2)
    {
        if (ly1 < 0)
        {
            ly1 = 0;
            ly2 += 1;
            lV = -lV;
        }
        if (ly2 > WINDOW_HEIGHT)
        {
            ly2 = WINDOW_HEIGHT;
            ly1 -= 1;
            lV = -lV;
        }
    }
    else
    {
        if (ly2 < 0)
        {
            ly2 = 0;
            ly1 += 1;
            lV = -lV;
        }
        if (ly1 > WINDOW_HEIGHT)
        {
            ly1 = WINDOW_HEIGHT;
            ly2 -= 1;
            lV = -lV;
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
        rectX, //posición en x
        rectY, //posición en y
        rectW, //ancho
        rectH //alto
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