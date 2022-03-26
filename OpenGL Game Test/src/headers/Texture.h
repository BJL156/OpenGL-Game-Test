#pragma once

#include <GLAD/glad.h>
#include "stb_image.h"

#include <iostream>
#include <vector>
#include <string>

int amount = 0;

class Texture
{
public:
    unsigned int texture;
    int position;
    const char* name;
    //int position = 2;
	void SetUp(const char* filePath, const char* Name, int Position)
	{
        name = Name;
        position = Position;
        std::cout << "position: " << position << std::endl;
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        int width, height, nrChannels;
        unsigned char* data = stbi_load(filePath, &width, &height, &nrChannels, 0);

        // find if image has an alpha channel
        std::string filePathS = filePath;
        bool alpha;
        std::cout << filePathS << std::endl;
        if (filePathS.find(".png") != std::string::npos)
        {
            alpha = true;
        }
        else
        {
            alpha = false;
        }
        std::cout << "alpha: " << alpha << std::endl;

        if (data)
        {
            if (alpha)
            {
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
                glGenerateMipmap(GL_TEXTURE_2D);
            }
            else
            {
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
                glGenerateMipmap(GL_TEXTURE_2D);
            }
            std::cout << "TEXTURE SUCCEEDED TO LOAD" << std::endl;
        }
        else
            std::cout << "TEXTURE FAILED TO LOAD" << std::endl;
        stbi_image_free(data);
	}

    void Bind()
    {
        glActiveTexture(GL_TEXTURE0 + position);
        glBindTexture(GL_TEXTURE_2D, texture);
    }
};