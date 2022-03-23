# OpenGL Game Test
This is my test on making a "game engine" and it was created with C++ and modern OpenGL. The game test supports texture rendering (COMING SOON) and also solid color rendering.

## Front End
Games are made in the style of the Unity game engine with a `Start()` and `Update()` function.
Game code is written in the `Game.cpp` file. The file location is `OpenGL Game Test\src`
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

## Creating and Drawing Entities
##### Step One
Using `Rect.h` create a new instance of the `Rect` class. The constructor look like this: `Rect(glm::vec2 position, glm::vec2 scale)` and also there is no need to include `glm` as it is already included in the header file.
Here is an example:
```
Rect r1(glm::vec2(0.0f, 0.0f), glm::vec2(100.0f, 100.0f));
```

##### Step Two
The next step is to draw the Rect using the method `Draw(glm::vec4 color, Window window, Shader shader)` and this method should be called in the `Update()` method.
```
r1.Draw(glm::vec4(100.0f, 30.0f, 230.0f, 255.0f), window, shader);
```
The output should now have something similar to the follow:
![Rendered_Rect](https://user-images.githubusercontent.com/97370242/159363689-0d99e524-3dda-43ce-91fc-43ad8cd44c15.jpg)
