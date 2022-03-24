#include "headers/OpenGLGameTest.h"

int main()
{
	Window window = Window(860, 600, "OpenGL Game Test");


	Rect r1(glm::vec2(100.0f, 100.0f), glm::vec2(100.0f, 100.0f));

	while (!window.WindowShouldClose())
	{
		window.Update();

		r1.Draw(glm::vec4(0.0f, 0.0f, 255.0f, 255.0f), window);

	}
	window.Destory();
}