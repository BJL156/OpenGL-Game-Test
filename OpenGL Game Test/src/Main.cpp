#include "headers/OpenGLGameTest.h"

int main()
{
	Window window(860, 600, "OpenGL Pong");
	window.FillColor(glm::vec4(50.0f, 75.0f, 100.0f, 255.0f));


	Rect p1(glm::vec2(10.0f, window.GetHeight() / 2 - 125.0f / 2), glm::vec2(15.0f, 125.0f));
	Rect p2(glm::vec2(window.GetWidth() - 15.0f - 10.0f, window.GetHeight() / 2 - 125.0f / 2), glm::vec2(15.0f, 125.0f));

	Rect ball(glm::vec2(window.GetWidth() / 2 - 15.0f / 2, window.GetHeight() / 2 - 15.0f / 2), glm::vec2(15.0f, 15.0f));
	float ballSpeedX = 5.0f;
	float ballSpeedY = 5.0f;

	while (!window.WindowShouldClose())
	{
		window.Update();

		const float playerSpeed = 10.0f;

		// player one movement
		if (Input::IsKeyPressed(window, GAME_KEY_W))
			p1.y -= playerSpeed;
		if (Input::IsKeyPressed(window, GAME_KEY_S))
			p1.y += playerSpeed;

		// player two movement
		if (Input::IsKeyPressed(window, GAME_KEY_UP))
			p2.y -= playerSpeed;
		if (Input::IsKeyPressed(window, GAME_KEY_DOWN))
			p2.y += playerSpeed;

		// ball logic
		ball.x -= ballSpeedX;
		ball.y -= ballSpeedY;

		if (p1.IsColliding(ball) || p2.IsColliding(ball))
			ballSpeedX *= -1;

		if (ball.y < 0 || ball.y + ball.height > window.GetHeight())
			ballSpeedY *= -1;

		// draw entities
		p1.Draw(glm::vec4(255.0f, 255.0f, 255.0f, 255.0f), window);
		p2.Draw(glm::vec4(255.0f, 255.0f, 255.0f, 255.0f), window);

		ball.Draw(glm::vec4(255.0f, 255.0f, 255.0f, 255.0f), window);
	}
	window.Destory();
}