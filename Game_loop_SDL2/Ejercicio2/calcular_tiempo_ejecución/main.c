#include <stdio.h>
#include <SDL.h>

float antesUpdate;
float entreUR;
float despuesRender;

void setup(void)
{
	printf("Se ejecuta setup\n");
}

void update(void)
{
	printf("Se ejecuta update()\n");
}

void render(void)
{
	printf("se ejecuta render()\n");
}

int main(int argc, char* args[])
{
	setup();
	

	for (int i = 1; i <= 20; i++) 
	{
		antesUpdate = SDL_GetTicks();
		printf("Tiempo antes de Update: %f\n", antesUpdate);
		update();
		entreUR = SDL_GetTicks();
		printf("Tiempo entre Update y Render: %f\n", entreUR);
		render();
		despuesRender = SDL_GetTicks();
		printf("Tiempo después de Render: %f\n", despuesRender);
	}

	return 0;
}