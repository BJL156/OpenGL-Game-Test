#include "Game.h"
#include "Input.h"

#include <iostream>

namespace OpenGL2DEngine
{
	Rect r1(glm::vec2(0.0f, 0.0f), glm::vec2(100.0f, 100.0f));

	// gets called once at the start of the game loop
	void Game::Start()
	{
		window.SetTitle("OpenGL Game");
		window.FillColor(50.0f, 75.0f, 100.0f, 255.0f);
	}

	// gets called every frame
	void Game::Update()
	{
		if (Input::IsKeyPressed(window, GAME_KEY_TAB))
			std::cout << "tab key pressed!" << std::endl;

		if (Input::IsMouseButtonPressed(window, GAME_MOUSE_BUTTON_1))
			std::cout << "left mouse button pressed!" << std::endl;

		r1.Draw(glm::vec4(255.0f, 0.0f, 0.0f, 255.0f), window);
	}
}