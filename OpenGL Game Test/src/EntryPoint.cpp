#include "Game.h"

int main()
{
	Window gameWindow = Window(860, 600, "OpenGL Game Test");
	OpenGL2DEngine::Game game(gameWindow);

	game.Start();
	while (!gameWindow.WindowShouldClose())
	{
		gameWindow.Update();
		game.Update();
	}
	gameWindow.Destory();
}