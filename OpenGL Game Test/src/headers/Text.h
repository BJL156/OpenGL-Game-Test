#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Window.h"

#include <string>
#include <iostream>

class Text
{
public:
	int x, y;
	Text(glm::vec2 position) : x(position.x), y(position.y)
	{

	}

	void Draw(glm::vec4 color, float scale, std::string text, Window window)
	{
		window.textRenderer.RenderText(text, glm::vec2(x, y), scale, color);
	}
};