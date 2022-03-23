#pragma once

#include "Window.h"

namespace Input
{
	bool IsKeyPressed(Window window, int keycode)
	{
		if (glfwGetKey(window.GetWindow(), keycode))
			return true;
		return false;
	}

	bool IsMouseButtonPressed(Window window, int mouseCode)
	{
		if (glfwGetMouseButton(window.GetWindow(), mouseCode))
			return true;
		return false;
	}

	double GetCursorX(Window window)
	{
		double x;
		glfwGetCursorPos(window.GetWindow(), &x, NULL);
		return x;
	}

	double GetCursorY(Window window)
	{
		double y;
		glfwGetCursorPos(window.GetWindow(), NULL, &y);
		return y;
	}
}