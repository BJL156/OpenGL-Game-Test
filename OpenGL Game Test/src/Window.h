#pragma once

#include <GLAD/glad.h>
#include <GLFW/glfw3.h>

#include "Renderer.h"

#include <iostream>

class Window
{
private:
	int m_Width, m_Height;
	const char* m_Title;
	GLFWwindow* m_Window;
public:
	Renderer renderer;
	Shader shader;
	double cursorX, cursorY;
	Window(int width, int height, const char* title) : m_Width(width), m_Height(height), m_Title(title)
	{
		glfwInit();

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		glfwWindowHint(GLFW_RESIZABLE, false);

		m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
		if (m_Window == NULL)
			std::cout << "FAILED TO CREATE WINDOW" << std::endl;
		glfwMakeContextCurrent(m_Window);


		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
			std::cout << "GLAD FAILED TO INITIALIZE" << std::endl;

		shader.SetUp("res/shaders/vertex.glsl", "res/shaders/fragment.glsl");

		renderer.Init();
	}

	bool WindowShouldClose() { return glfwWindowShouldClose(m_Window); }
	void SetWindowShouldClose(bool value) { return glfwSetWindowShouldClose(m_Window, value); }

	int GetWidth() { return m_Width; }
	int GetHeight() { return m_Height; }
	GLFWwindow* GetWindow() { return m_Window; }

	void FillColor(float r, float g, float b, float a)
	{
		glClearColor(r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f);
	}

	void SetWireframe(bool value)
	{
		renderer.SetWireframe(value);
	}

	void SetTitle(const char* title)
	{
		glfwSetWindowTitle(m_Window, title);
	}

	void Update()
	{
		shader.Use();
		glfwSwapBuffers(m_Window);

		glClear(GL_COLOR_BUFFER_BIT);

		glfwPollEvents();
	}

	void Destory()
	{
		shader.Destory();
		renderer.Destory();
		glfwTerminate();
	}
};