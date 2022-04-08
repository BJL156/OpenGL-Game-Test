#include "headers/OpenGLGameTest.h"

#include <sstream>

// remove console
//#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

int main()
{
	Window window(860, 600, "OpenGL C++ Game");
	window.FillColor(glm::vec4(50.0f, 75.0f, 100.0f, 255.0f));

	Text text(glm::vec2(10.0f, 10.0f), "res/fonts/Orbitron/Orbitron-VariableFont_wght.ttf", window);

	window.soundEngine.Play("res/audio/LupusNocte.mp3", true);
	window.soundEngine.SetVolume(1.0f);


	// load textures
	window.LoadTexture("res/textures/dirt.jpg", "dirt");
	window.LoadTexture("res/textures/character.png", "character");


	// create entities
	TRect tRect(glm::vec2(0.0f, 0.0f), glm::vec2(window.GetTextureWidth("dirt"), window.GetTextureHeight("dirt")));

	// game loop
	while (!window.WindowShouldClose())
	{
		window.Update();

		std::stringstream fpsText;
		fpsText << "fps: " << window.GetFrameRate();


		// render entities
		tRect.Draw(glm::vec4(255.0f, 255.0f, 255.0f, 255.0f), window.GetTextureUnit("dirt"), window);

		// render text
		text.Draw(glm::vec4(255.0f, 255.0f, 255.0f, 255.0f), 0.5f, fpsText.str(), window);
	}
	window.Destroy();
}
