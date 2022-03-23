#include "Game.h"

#include <iostream>

namespace OpenGL2DEngine
{
	// set up entities
	Rect r1(glm::vec2(0.0f, 0.0f), glm::vec2(100.0f, 100.0f));
	Rect r2(glm::vec2(300.0f, 300.0f), glm::vec2(100.0f, 100.0f));

	glm::vec4 r1Color;

	// gets called once at the start of the game loop
	void Game::Start()
	{
		r1Color = glm::vec4(120.0f, 30.0f, 230.0f, 255.0f);
	}

	// gets called every frame
	void Game::Update()
	{
		// fill the window with a blue color
		window.FillColor(50.0f, 75.0f, 100.0f, 255.0f);

		// check if r1 is colliding with r2
		if (r1.IsColliding(r2))
		{
			// change color to a green
			r1Color = glm::vec4(70.0f, 200.0f, 120.0f, 255.0f);
			std::cout << "colliding" << std::endl;
		}
		else
		{
			// change back to the original color
			r1Color = glm::vec4(120.0f, 30.0f, 230.0f, 255.0f);
		}

		// move entity one the the cursors position
		r1.x = cursorX - r1.width / 2;
		r1.y = cursorY - r1.height / 2;

		// drawing the entities (drawing r2 then r1 to let r1 be on top)
		r2.Draw(glm::vec4(120.0f, 30.0f, 230.0f, 255.0f), window);
		r1.Draw(r1Color, window);
	}
}