#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Window.h"

#include <string>
#include <iostream>

#include <string>

class Text
{
private:
	TextRenderer textRender;
public:
	int x, y;
	Text(glm::vec2 position, std::string fontPath, Window window) : x(position.x), y(position.y)
	{
		textRender.SetUp(window.GetWidth(), window.GetHeight(), fontPath);
	}

	void Draw(glm::vec4 color, float scale, std::string text, Window window)
	{
		textRender.Draw(text, glm::vec2(x, y), scale, color);
	}
};