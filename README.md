# OpenGL Game Test
This is my test on making a "game engine" and it was created with C++ and modern OpenGL. The game test supports texture rendering and also solid color rendering.

## Front End
Games are written in the `Main.cpp` file. Similar to many game frame works such as, SFML, pygame, raylib and SDL2. The code below is a draws a red square to the window.
```
#include "headers/OpenGLGameTest.h"

int main()
{
	Window window = Window(860, 600, "OpenGL Game Test");


	Rect r1(glm::vec2(0.0f, 0.0f), glm::vec2(100.0f, 100.0f));

	while (!window.WindowShouldClose())
	{
		window.Update();

		r1.Draw(glm::vec4(0.0f, 0.0f, 255.0f, 255.0f), window);

	}
	window.Destory();
}
```

## Creating and Drawing Solid Color Entities
##### Step One
Step one is to create a new instance of the `Rect` class. The constructor look like this: `Rect(glm::vec2 position, glm::vec2 scale)` and also there is no need to include `glm` as it is already included in the header file.
Here is an example:
```
Rect r1(glm::vec2(0.0f, 0.0f), glm::vec2(100.0f, 100.0f));
```

##### Step Two
The next step is to draw the Rect using the method `Draw(glm::vec4 color, Window window, Shader shader)` and this method should be called in the game loop.
```
r1.Draw(glm::vec4(100.0f, 30.0f, 230.0f, 255.0f), window, shader);
```
The output should now have something similar to the follow:
![Rendered_Rect](https://user-images.githubusercontent.com/97370242/159363689-0d99e524-3dda-43ce-91fc-43ad8cd44c15.jpg)

## Creating and Drawing Textured Entities
##### Step One
Step one is to create a new instance of the `TRect` class. The constructor look like this: `TRect(glm::vec2 position, glm::vec2 scale)` and also there is no need to include `glm` as it is already included in the header file.
This is an example:
```
TRect r1(glm::vec2(0.0f, 0.0f), glm::vec2(100.0f, 100.0f));
```

##### Step Two
the next step is to load a texture this can be done by using the `textureRenderer` in the window class (this should not be called in the game loop): `window.textureRenderer.LoadTexture(const char* textureName)`
Example:
```
window.textureRenderer.LoadTexture("res/textures/dirt.jpg", "dirt");
```

##### Step Three
The final step is to draw the Rect using the method `Draw(glm::vec4 color, int textureUnit, Window window)` and the `textureUnit` is found with the method: `window.textureRenderer.GetTexture(const char* textureName)` and this method should be called in the game loop.
```
r1.Draw(glm::vec4(255.0f, 255.0f, 255.0f, 255.0f), window.textureRenderer.GetTexture("dirt"), window);
```
The output should now have something similar to the follow:
![Rendered_Texture](https://user-images.githubusercontent.com/97370242/160214380-abf837e0-5901-453f-b39c-b12d58186d20.jpg)

