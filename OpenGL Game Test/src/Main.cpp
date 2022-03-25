#include "headers/OpenGLGameTest.h"

int main()
{
	Window window(860, 600, "OpenGL Pong");
	window.FillColor(glm::vec4(50.0f, 75.0f, 100.0f, 255.0f));


	// TRect are textured geometry
	TRect r1(glm::vec2(0.0f, 0.0f), glm::vec2(100.0f, 100.0f));
	TRect r3(glm::vec2(100.0f, 100.0f), glm::vec2(100.0f, 100.0f));

	// load textures
	window.textureRenderer.LoadTexture("res/textures/dirt.jpg", "dirt");
	window.textureRenderer.LoadTexture("res/textures/awesomeface.png", "awesomeface");

	// Rect are solid color geometry
	Rect r2(glm::vec2(200.0f, 100.0f), glm::vec2(100.0f, 100.0f));

	while (!window.WindowShouldClose())
	{
		window.Update();
		std::cout << window.GetFrameRate() << std::endl;


		// draw textured entities
		r1.Draw(glm::vec4(255.0f, 255.0f, 255.0f, 255.0f), window.textureRenderer.GetTexture("dirt"), window);
		r3.Draw(glm::vec4(255.0f, 255.0f, 255.0f, 255.0f), window.textureRenderer.GetTexture("awesomeface"), window);

		// draw solid color entities
		r2.Draw(glm::vec4(255.0f, 0.0f, 0.0f, 255.0f), window);
	}
	window.Destory();
}