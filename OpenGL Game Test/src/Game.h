#pragma once

#include "Window.h"
#include "Shader.h"
#include "Rect.h"

namespace OpenGL2D
{
	class Game
	{
	public:
		Window window;
		Shader shader;

		Game(Window windowW, Shader ShaderS) : window(windowW), shader(ShaderS)
		{

		}

		void Start();

		void Update();
	};
}