#include <stdio.h>
#include <SDL.h>

void setup(void) 
{
	printf("Setup()");
}

void update(void) 
{
	printf("Update()");
}

void render(void) 
{
	printf("Render()");
}

int main(int argc, char* args[]) 
{
	setup();
	update();
	render();
	return 0;
}