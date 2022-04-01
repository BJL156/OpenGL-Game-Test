﻿#include "headers/OpenGLGameTest.h"

#include <sstream>

// remove console
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

int main()
{
	Window window(860, 600, "OpenGL C++ Game");
	window.FillColor(glm::vec4(50.0f, 75.0f, 100.0f, 255.0f));

	Text text(glm::vec2(10.0f, 10.0f), "res/fonts/Orbitron/Orbitron-VariableFont_wght.ttf", window);

	// game loop
	while (!window.WindowShouldClose())
	{
		window.Update();

		std::stringstream texta;
		texta << "fps: " << window.GetFrameRate();

		// render text
		text.Draw(glm::vec4(255.0f, 255.0f, 255.0f, 255.0f), 0.5f, texta.str(), window);
	}
	window.Destory();
}
