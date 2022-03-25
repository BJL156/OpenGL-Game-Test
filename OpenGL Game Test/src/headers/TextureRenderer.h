#pragma once

#include <GLAD/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Texture.h"
#include "Shader.h"

#include "stb_image.h"

#include <iostream>

std::vector<Texture> texturesV;

class TextureRenderer
{
public:
    unsigned int VBO, VAO, EBO;
    int index = 0;

    void Init()
    {
        float vertices[] = {
            0.0f, 1.0f,     0.0f, 1.0f,
            1.0f, 0.0f,     1.0f, 0.0f,
            0.0f, 0.0f,     0.0f, 0.0f,

            0.0f, 1.0f,     0.0f, 1.0f,
            1.0f, 1.0f,     1.0f, 1.0f,
            1.0f, 0.0f,     1.0f, 0.0f
        };

        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glBindVertexArray(VAO);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);


        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    }

    void LoadTexture(const char* filePath, const char* textureName)
    {
        index++;
        texturesV.push_back(Texture());
        texturesV[texturesV.size() - 1].SetMeUpUwU(filePath, textureName, texturesV.size() - 1);
        std::cout << "size: " << texturesV.size() << std::endl;
        std::cout << "index: " << index << std::endl;
        std::cout << "-------------------" << std::endl;
    }

    int GetTexture(const char* textureName)
    {
        for (int i = 0; i < texturesV.size(); i++)
        {
            if (texturesV[i].name == textureName)
                return i;
        }
    }

    void Draw(glm::vec2 position, glm::vec2 size, glm::vec4 color, int textureUnit, GLFWwindow* window, Shader textureShader)
    {
        textureShader.Use();

        glm::mat4 model = glm::mat4(1.0f);
        glm::mat4 projection = glm::mat4(1.0f);

        model = glm::translate(model, glm::vec3(position, 0.0f));
        model = glm::scale(model, glm::vec3(size, 0.0f));

        int width, height;
        glfwGetWindowSize(window, &width, &height);

        projection = glm::ortho(0.0f, (float)width, (float)height, 0.0f, -1.0f, 1.0f);

        textureShader.SetMat4("model", model);
        textureShader.SetMat4("projection", projection);

        textureShader.SetVec4("spriteColor", glm::vec4(color.x / 255.0f, color.y / 255.0f, color.z / 255.0f, color.w / 255.0f));


        
        texturesV[textureUnit].Bind();

        glUniform1i(glGetUniformLocation(textureShader.ID, "image"), textureUnit);

        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 6);
        glBindVertexArray(0);
    }

    void Destory()
    {
        glDeleteBuffers(1, &VBO);
        glDeleteVertexArrays(1, &VAO);
    }
};