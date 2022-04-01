#pragma once

#include <GLAD/glad.h>
#include <GLFW/glfw3.h>

#include "TextureRenderer.h"
#include "Renderer.h"
#include "TextRenderer.h"

#include <iostream>

#include <windows.h>

class Window
{
private:
	int m_Width, m_Height;
	const char* m_Title;
	GLFWwindow* m_Window;

	float prevTime = glfwGetTime();
	int frames = 0;
	int frameRate;
public:
	Renderer renderer;
	TextureRenderer textureRenderer;

	Shader shader;
	Shader textureShader;


	double cursorX, cursorY;
	Window(int width, int height, const char* title) : m_Width(width), m_Height(height), m_Title(title)
	{
		glfwInit();

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		glfwWindowHint(GLFW_RESIZABLE, false);
		glfwWindowHint(GLFW_SAMPLES, 4);

		m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
		if (m_Window == NULL)
			std::cout << "FAILED TO CREATE WINDOW" << std::endl;
		glfwMakeContextCurrent(m_Window);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
			std::cout << "GLAD FAILED TO INITIALIZE" << std::endl;
		
		shader.SetUp("res/shaders/vertex.glsl", "res/shaders/fragment.glsl");
		textureShader.SetUp("res/shaders/vertexTexture.glsl", "res/shaders/fragmentTexture.glsl");

		renderer.Init();
		textureRenderer.Init();

		glEnable(GL_MULTISAMPLE);
	}

	bool WindowShouldClose() { return glfwWindowShouldClose(m_Window); }
	void SetWindowShouldClose(bool value) { return glfwSetWindowShouldClose(m_Window, value); }

	// get functions
	GLFWwindow* GetWindow() { return m_Window; }
	int GetWidth() { return m_Width; }
	int GetHeight() { return m_Height; }

	int GetFrameRate() { return frameRate; }
	float GetTime() { return glfwGetTime(); }

	// set functions
	void FillColor(glm::vec4 color) { glClearColor(color.x / 255.0f, color.y / 255.0f, color.z / 255.0f, color.w / 255.0f); }
	void SetWireframe(bool value) { renderer.SetWireframe(value); }
	void SetTitle(const char* title) { glfwSetWindowTitle(m_Window, title); }


	// texture
	void LoadTexture(const char* filePath, const char* textureName) { textureRenderer.LoadTexture(filePath, textureName); }
	int GetTextureUnit(const char* textureName) { return textureRenderer.GetTextureUnit(textureName); }

	int GetTextureWidth(const char* textureName) { return textureRenderer.GetTextureWidth(textureName); }
	int GetTextureHeight(const char* textureName) { return textureRenderer.GetTextureHeight(textureName); }


	void CloseConsole() { FreeConsole(); }

	void Update()
	{
		// calculate frame rate
		if (glfwGetTime() - prevTime >= 0.25f)
		{
			frames *= 4;
			
			frameRate = frames;

			frames = 0;
			prevTime = glfwGetTime();
		}
		frames++;

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