# OpenGL Game Test
My test on making a actual game with C++ and modern OpenGL.

The game test supports texture renderering (COMING SOON) and also solid color renderering

## Front End
Games are made in the style of Unity.
Game code is written in the `Game.cpp` file location: `OpenGL Game Test\src`
```
#include "Game.h"

namespace OpenGL2DEngine
{
	// gets called once at the start of the game loop
	void Game::Start()
	{

	}

	// gets called every frame
	void Game::Update()
	{

	}
}
```

## Creating Entities
Using `Rect.h` create a new instance of the `Rect` class. the arguments are the position and the scale in the form of a `vec2` there is no need to include `glm` and to make one.
Here is an example:
`Rect r1(glm::vec2(0.0f, 0.0f), glm::vec2(100.0f, 100.0f));`

The next step is to draw the Rect using the method in the Rect called `Draw(glm::vec4 color, Window window, Shader shader)` and it is called in the `Update()` function.
`r1.Draw(glm::vec4(100.0f, 30.0f, 230.0f, 255.0f), window, shader);`
