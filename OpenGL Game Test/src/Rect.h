#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Window.h"


class Rect
{
public:
	int x, y;
	int width, height;
	Rect(glm::vec2 position, glm::vec2 scale) : x(position.x), y(position.y), width(scale.x), height(scale.y)
	{

	}

	void Draw(glm::vec4 color, Window window, Shader shader)
	{
		window.renderer.Draw(color, window.GetWindow(), shader);
	}
};