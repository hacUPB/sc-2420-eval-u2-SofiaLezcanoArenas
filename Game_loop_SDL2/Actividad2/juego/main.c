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
int empezar = 0;
int teclaEspacio = 0;

int rectX, rectY, rectW, rectH, rectV;

struct linea {
    int x1;
    int y1;
    int x2;
    int y2;
    int width;
    int height;
} lh1, lh2, lh3, lh4, lh5, lh6, lh7, lh8, lv1, lv2, lv3, lv4, lv5, lv6, lv7, lv8, meta;

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
    //Pista
    lh1.x1 = 0; lh1.y1 = 500; lh1.x2 = 150; lh1.y2 = 500; lh1.width = lh1.x2 - lh1.x1; lh1.height = lh1.y2 - lh1.y1;

    lh2.x1 = 150; lh2.y1 = 400; lh2.x2 = 250; lh2.y2 = 400; lh2.width = lh2.x2 - lh2.x1; lh2.height = lh2.y2 - lh2.y1;

    lh3.x1 = 250; lh3.y1 = 100; lh3.x2 = 500; lh3.y2 = 100; lh3.width = lh3.x2 - lh3.x1; lh3.height = lh3.y2 - lh3.y1;

    lh4.x1 = 500; lh4.y1 = 450; lh4.x2 = 550; lh4.y2 = 450; lh4.width = lh4.x2 - lh4.x1; lh4.height = lh4.y2 - lh4.y1;

    lh5.x1 = 650; lh5.y1 = 100; lh5.x2 = 800; lh5.y2 = 100; lh5.width = lh5.x2 - lh5.x1; lh5.height = lh5.y2 - lh5.y1;

    lh6.x1 = 400; lh6.y1 = 550; lh6.x2 = 650; lh6.y2 = 550; lh6.width = lh6.x2 - lh6.x1; lh6.height = lh6.y2 - lh6.y1;

    lh7.x1 = 350; lh7.y1 = 200; lh7.x2 = 400; lh7.y2 = 200; lh7.width = lh7.x2 - lh7.x1; lh7.height = lh7.y2 - lh7.y1;

    lh8.x1 = 250; lh8.y1 = 500; lh8.x2 = 350; lh8.y2 = 500; lh8.width = lh8.x2 - lh8.x1; lh8.height = lh8.y2 - lh8.y1;

    lv1.x1 = 150; lv1.y1 = 500; lv1.x2 = 150; lv1.y2 = 400; lv1.width = lv1.x2 - lv1.x1; lv1.height = lv1.y2 - lv1.y1;

    lv2.x1 = 250; lv2.y1 = 400; lv2.x2 = 250; lv2.y2 = 100; lv2.width = lv2.x2 - lv2.x1; lv2.height = lv2.y2 - lv2.y1;

    lv3.x1 = 500; lv3.y1 = 100; lv3.x2 = 500; lv3.y2 = 450; lv3.width = lv3.x2 - lv3.x1; lv3.height = lv3.y2 - lv3.y1;

    lv4.x1 = 550; lv4.y1 = 450; lv4.x2 = 550; lv4.y2 = 0; lv4.width = lv4.x2 - lv4.x1; lv4.height = lv4.y2 - lv4.y1;

    lv5.x1 = 650; lv5.y1 = 100; lv5.x2 = 650; lv5.y2 =550; lv5.width = lv5.x2 - lv5.x1; lv5.height = lv5.y2 - lv5.y1;

    lv6.x1 = 400; lv6.y1 = 550; lv6.x2 = 400; lv6.y2 = 200; lv6.width = lv6.x2 - lv6.x1; lv6.height = lv6.y2 - lv6.y1;

    lv7.x1 = 350; lv7.y1 = 200; lv7.x2 = 350; lv7.y2 = 500; lv7.width = lv7.x2 - lv7.x1; lv7.height = lv7.y2 - lv7.y1;

    lv8.x1 = 250; lv8.y1 = 500; lv8.x2 = 250; lv8.y2 = 600; lv8.width = lv8.x2 - lv8.x1; lv8.height = lv8.y2 - lv8.y1;

    //Meta
    meta.x1 = 700; meta.y1 = 0; meta.x2 = 700; meta.y2 = 100; meta.width = meta.x2 - meta.x1; meta.height = meta.y2 - meta.y1;

    //Cuadrado
    rectX = 50;
    rectY = 540;
    rectW = 30;
    rectH = 30;
    rectV = 120;

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
            if (event.key.keysym.sym == SDLK_SPACE && teclaEspacio == 0)
            {
                teclaEspacio = 1;
                empezar = 1;
            }
            if (event.key.keysym.sym == SDLK_UP && empezar != 0)
            {
                empezar = 2;
            }
            if (event.key.keysym.sym == SDLK_DOWN && empezar != 0)
            {
                empezar = 3;
            }
            if (event.key.keysym.sym == SDLK_RIGHT && empezar != 0)
            {
                empezar = 4;
            }
            break;
        }
    }

    //Movimiento cuadrado
    if (empezar == 1)
    {
        rectX += (rectV * delta_time);
    }
    if (teclaEspacio == 1 && empezar == 2)
    {
        rectY -= (rectV * delta_time);
    }
    if (teclaEspacio == 1 && empezar == 3)
    {
        rectY += (rectV * delta_time);
    }
    if (teclaEspacio == 1 && empezar == 4)
    {
        rectX += (rectV * delta_time);
    }

    //Detectar la meta
    if (rectX > (meta.x1 + 10) && rectY > meta.y1 && rectY < (meta.y2 - rectH) )
    {
        empezar = 0;
    }

    //Colisiones
    //horizontales
    //lh1
    if (rectX >= lh1.x1 && rectX <= lh1.x2 && rectY <= lh1.y1 )
    {
        rectX = 50;
        rectY = 540;
        empezar = 0;
        teclaEspacio = 0;
    }
    //lh2
    if (rectX >= lh2.x1 && rectX <= lh2.x2 && rectY <= lh2.y1)
    {
        rectX = 50;
        rectY = 540;
        empezar = 0;
        teclaEspacio = 0;
    }
    //lh3
    if (rectX >= lh3.x1 && rectX <= lh3.x2 && rectY <= lh3.y1)
    {
        rectX = 50;
        rectY = 540;
        empezar = 0;
        teclaEspacio = 0;
    }
    //lh4
    if ((rectX + rectW) >= lh4.x1 && rectX <= lh4.x2 && rectY <= lh4.y1)
    {
        rectX = 50;
        rectY = 540;
        empezar = 0;
        teclaEspacio = 0;
    }
    //lh5
    if ((rectX + rectW) >= lh5.x1 && rectX <= lh5.x2 && (rectY + rectH) >= lh5.y1)
    {
        rectX = 50;
        rectY = 540;
        empezar = 0;
        teclaEspacio = 0;
    }
    //lh6
    if ((rectX + rectW) >= lh6.x1 && rectX <= lh6.x2 && (rectY + rectH) >= lh6.y1)
    {
        rectX = 50;
        rectY = 540;
        empezar = 0;
        teclaEspacio = 0;
    }
    //lh7
    if ((rectX + rectW) >= lh7.x1 && rectX <= lh7.x2 && (rectY + rectH) >= lh7.y1)
    {
        rectX = 50;
        rectY = 540;
        empezar = 0;
        teclaEspacio = 0;
    }
    //lh8
    if ((rectX + rectW) >= lh8.x1 && rectX <= lh8.x2 && (rectY + rectH) >= lh8.y1)
    {
        rectX = 50;
        rectY = 540;
        empezar = 0;
        teclaEspacio = 0;
    }
    //verticales
    //lv1
    /*if (rectY <= lv1.y1 && rectY >= lv1.y2 && rectX <= lv1.x1)
    {
        rectX = 50;
        rectY = 540;
        empezar = 0;
        teclaEspacio = 0;
    }*/
    ////lv2
    //if (rectY <= lv2.y1 && rectY >= lv2.y2 && rectX <= lv2.x1)
    //{
    //    rectX = 50;
    //    rectY = 540;
    //    empezar = 0;
    //    teclaEspacio = 0;
    //}
    ////lv3
    //if (rectY >= lv3.y1 && rectY <= lv3.y2 && (rectX + rectW) >= lv3.x1)
    //{
    //    rectX = 50;
    //    rectY = 540;
    //    empezar = 0;
    //    teclaEspacio = 0;
    //}
    ////lv4
    //if (rectY <= lv4.y1 && rectY >= lv4.y2 && rectX <= lv4.x1)
    //{
    //    rectX = 50;
    //    rectY = 540;
    //    empezar = 0;
    //    teclaEspacio = 0;
    //}
    ////lv5
    //if (rectY >= lv5.y1 && rectY <= lv5.y2 && (rectX + rectW) >= lv5.x1)
    //{
    //    rectX = 50;
    //    rectY = 540;
    //    empezar = 0;
    //    teclaEspacio = 0;
    //}
    ////lv6
    //if (rectY <= lv6.y1 && rectY >= lv6.y2 && rectX <= lv6.x1)
    //{
    //    rectX = 50;
    //    rectY = 540;
    //    empezar = 0;
    //    teclaEspacio = 0;
    //}
    ////lv7
    //if (rectY >= lv7.y1 && rectY <= lv7.y2 && (rectX + rectW) >= lv7.x1)
    //{
    //    rectX = 50;
    //    rectY = 540;
    //    empezar = 0;
    //    teclaEspacio = 0;
    //}
    ////lv8
    //if (rectY >= lv8.y1 && rectY <= lv8.y2 && (rectX + rectW) >= lv8.x1)
    //{
    //    rectX = 50;
    //    rectY = 540;
    //    empezar = 0;
    //    teclaEspacio = 0;
    //}

    //Colisiones con la ventana
    //Rect�ngulo
    //if (rectX < 0)
    //{
    //    rectX = 0; //para que no pase del borde izquierdo
    //    rectV = -rectV; // para que se mueva en la direcci�n opuesta
    //}
    //if (rectX + rectW > WINDOW_WIDTH)
    //{
    //    rectX = WINDOW_WIDTH - rectW; //para que no pase del borde derecho
    //    rectV = -rectV;
    //}
    //if (rectY < 0)
    //{
    //    rectY = 0; //para que no pase del borde superior
    //    rectV = -rectV; // para que se mueva en la direcci�n opuesta
    //}
    //if (rectY + rectH > WINDOW_HEIGHT)
    //{
    //    rectY = WINDOW_HEIGHT - rectH;
    //    rectV = -rectV;
    //}
}

void render(void)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // (R, G, B, alpha) para definir el color a usar en lo pr�ximo a dibujar
    SDL_RenderClear(renderer);

    //Dibujo pista
    SDL_SetRenderDrawColor(renderer, 0, 100, 200, 255);
    SDL_RenderDrawLine(renderer, lh1.x1, lh1.y1, lh1.x2, lh1.y2); //(renderer, x1, y1, x2, y2)
    SDL_RenderDrawLine(renderer, lh2.x1, lh2.y1, lh2.x2, lh2.y2);
    SDL_RenderDrawLine(renderer, lh3.x1, lh3.y1, lh3.x2, lh3.y2);
    SDL_RenderDrawLine(renderer, lh4.x1, lh4.y1, lh4.x2, lh4.y2);
    SDL_RenderDrawLine(renderer, lh5.x1, lh5.y1, lh5.x2, lh5.y2);
    SDL_RenderDrawLine(renderer, lh6.x1, lh6.y1, lh6.x2, lh6.y2);
    SDL_RenderDrawLine(renderer, lh7.x1, lh7.y1, lh7.x2, lh7.y2);
    SDL_RenderDrawLine(renderer, lh8.x1, lh8.y1, lh8.x2, lh8.y2);
    SDL_RenderDrawLine(renderer, lv1.x1, lv1.y1, lv1.x2, lv1.y2);
    SDL_RenderDrawLine(renderer, lv2.x1, lv2.y1, lv2.x2, lv2.y2);
    SDL_RenderDrawLine(renderer, lv3.x1, lv3.y1, lv3.x2, lv3.y2);
    SDL_RenderDrawLine(renderer, lv4.x1, lv4.y1, lv4.x2, lv4.y2);
    SDL_RenderDrawLine(renderer, lv5.x1, lv5.y1, lv5.x2, lv5.y2);
    SDL_RenderDrawLine(renderer, lv6.x1, lv6.y1, lv6.x2, lv6.y2);
    SDL_RenderDrawLine(renderer, lv7.x1, lv7.y1, lv7.x2, lv7.y2);
    SDL_RenderDrawLine(renderer, lv8.x1, lv8.y1, lv8.x2, lv8.y2);
    //Dibujo meta
    SDL_SetRenderDrawColor(renderer, 50, 200, 100, 255);
    SDL_RenderDrawLine(renderer, meta.x1, meta.y1, meta.x2, meta.y2);
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