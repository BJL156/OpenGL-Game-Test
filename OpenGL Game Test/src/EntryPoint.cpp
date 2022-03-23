#include "Game.h"

Window gameWindow = Window(860, 600, "OpenGL Game Test");

void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{

}

void CursorPositionCallback(GLFWwindow* window, double x, double y)
{
	gameWindow.cursorX = x;
	gameWindow.cursorY = y;
}

int main()
{
	glfwSetKeyCallback(gameWindow.GetWindow(), KeyCallback);
	glfwSetCursorPosCallback(gameWindow.GetWindow(), CursorPositionCallback);

	OpenGL2DEngine::Game game(gameWindow);


	game.Start();
	while (!gameWindow.WindowShouldClose())
	{
		// update user input
		game.cursorX = gameWindow.GetCursorX();
		game.cursorY = gameWindow.GetCursorY();

		// update
		gameWindow.Update();
		game.Update();
	}
	gameWindow.Destory();
}