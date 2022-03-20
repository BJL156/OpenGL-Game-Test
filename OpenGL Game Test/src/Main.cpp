#include "headers/Window.h"

int main()
{
	Window gameWindow = Window(860, 600, "OpenGL Game Test");

	while (!gameWindow.WindowShouldClose())
	{
		gameWindow.Update(50.0f, 75.0f, 100.0f, 255.0f);
	}
	gameWindow.Destory();
}