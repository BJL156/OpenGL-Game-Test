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

	bool IsColliding(Rect otherRect)
	{
		if (x + width > otherRect.x && x < otherRect.x + otherRect.width && y + height > otherRect.y && y < otherRect.y + otherRect.height)
			return true;
		return false;
	}

	void Draw(glm::vec4 color, Window window)
	{
		window.renderer.Draw(glm::vec2(x, y), glm::vec2(width, height), color, window.GetWindow(), window.shader);
	}
};