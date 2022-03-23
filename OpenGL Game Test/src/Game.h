#pragma once

#include "Window.h"
#include "Shader.h"
#include "Rect.h"

#include "KeyCodes.h"
#include "MouseCodes.h"

namespace OpenGL2DEngine
{
	class Game
	{
	public:
		double cursorX, cursorY;

		Window window;
		Shader shader;

		Game(Window windowW) : window(windowW)
		{
			shader = windowW.shader;
		}

		void Start();

		void Update();
	};
}