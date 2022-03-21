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

		renderer.Init();
	}

	bool WindowShouldClose() { return glfwWindowShouldClose(m_Window); }
	void SetWindowShouldClose(bool value) { return glfwSetWindowShouldClose(m_Window, value); }

	int GetWidth() { return m_Width; }
	int GetHeight() { return m_Height; }
	GLFWwindow* GetWindow() { return m_Window; }

	void Update(float r, float g, float b, float a, Shader shader)
	{
		shader.Use();
	
		glClearColor(r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		renderer.Draw(glm::vec4(255.0f, 0, 255.0f, 255.0f), m_Window, shader);

		glfwSwapBuffers(m_Window);
		glfwPollEvents();
	}

	void Destory()
	{
		glfwTerminate();
	}
};