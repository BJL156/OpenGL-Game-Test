#pragma once

#include <GLAD/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Shader.h"


class Renderer
{
public:
	unsigned int VBO, VAO;
	void Init()
	{
		float vertices[] = {
			 0.0f, 0.0f,
			 0.0f, 1.0f,
			 1.0f, 1.0f,

			 0.0f, 0.0f,
			 1.0f, 0.0f,
			 1.0f, 1.0f
		};
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);

		glBindVertexArray(VAO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);

		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);

	}

	void SetWireframe(bool value)
	{
		if (value)
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		else glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}

	void Draw(glm::vec2 position, glm::vec2 scale, glm::vec4 color, GLFWwindow* window, Shader shader)
	{
		shader.Use();

		glm::mat4 model = glm::mat4(1.0f);
		glm::mat4 projection = glm::mat4(1.0f);

		model = glm::translate(model, glm::vec3(position, 0.0f));
		model = glm::scale(model, glm::vec3(scale, 0.0f));

		int width, height;
		glfwGetWindowSize(window, &width, &height);

		projection = glm::ortho(0.0f, (float)width, (float)height, 0.0f, -1.0f, 1.0f);

		shader.SetMat4("model", model);
		shader.SetMat4("projection", projection);

		shader.SetVec4("color", glm::vec4(color.x / 255.0f, color.y / 255.0f, color.z / 255.0f, color.w / 255.0f));



		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 9);
		glBindVertexArray(0);
	}

	void Destory()
	{
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
	}
};