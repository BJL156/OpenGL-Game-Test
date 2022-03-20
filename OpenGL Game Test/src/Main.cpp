#include "headers/Window.h"
#include "headers/Shader.h"

int main()
{
	Window gameWindow = Window(860, 600, "OpenGL Game Test");

	Shader shader("res/shaders/vertex.glsl", "res/shaders/fragment.glsl");

	while (!gameWindow.WindowShouldClose())
	{
		shader.Use();
		gameWindow.Update(50.0f, 75.0f, 100.0f, 255.0f, shader);
	}
	gameWindow.Destory();
}