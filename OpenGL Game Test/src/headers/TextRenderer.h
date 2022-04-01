#include <ft2build.h>
#include FT_FREETYPE_H

#include "Shader.h"

#include <iostream>
#include <string>
#include <map>

struct Character {
    unsigned int TextureID;
    glm::ivec2 Size;
    glm::ivec2 Bearing;
    unsigned int Advance;
};

std::map<GLchar, Character> Characters;

class TextRenderer
{
public:
    unsigned int VBO, VAO;
    Shader shader;
    glm::mat4 model = glm::mat4(1.0);

    float windowWidth, windowHeight;
	void SetUp(float WindowWidth, float WindowHeight, std::string &fontPath)
	{
        windowWidth = WindowWidth;
        windowHeight = WindowHeight;
		shader.SetUp("res/shaders/vertexText.glsl", "res/shaders/fragmentText.glsl");
		glm::mat4 projection = glm::ortho(0.0f, windowWidth, windowHeight, 0.0f);

        model = glm::rotate(model, glm::radians(180.0f), glm::vec3(1.0f, 0.0f, 0.0f));

		shader.Use();
        shader.SetMat4("model", model);
        shader.SetMat4("projection", projection);

        FT_Library ft;
        if (FT_Init_FreeType(&ft))
            std::cout << "FREETYPE FAILED TO INITIALIZE" << std::endl;

        std::string font_name = fontPath;

        FT_Face face;
        if (FT_New_Face(ft, font_name.c_str(), 0, &face))
            std::cout << "FAILED TO LOAD FONT" << std::endl;
        else {
            FT_Set_Pixel_Sizes(face, 0, 48);

            glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

            for (unsigned char c = 0; c < 128; c++)
            {
                if (FT_Load_Char(face, c, FT_LOAD_RENDER))
                {
                    std::cout << "FAILED TO LOAD GLPYH" << std::endl;
                    continue;
                }

                unsigned int texture;
                glGenTextures(1, &texture);
                glBindTexture(GL_TEXTURE_2D, texture);
                glTexImage2D(
                    GL_TEXTURE_2D,
                    0,
                    GL_RED,
                    face->glyph->bitmap.width,
                    face->glyph->bitmap.rows,
                    0,
                    GL_RED,
                    GL_UNSIGNED_BYTE,
                    face->glyph->bitmap.buffer
                );
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
                Character character = {
                    texture,
                    glm::ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
                    glm::ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top),
                    static_cast<unsigned int>(face->glyph->advance.x)
                };
                Characters.insert(std::pair<char, Character>(c, character));
            }
            glBindTexture(GL_TEXTURE_2D, 0);
        }
        FT_Done_Face(face);
        FT_Done_FreeType(ft);


        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 6 * 4, NULL, GL_DYNAMIC_DRAW);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), 0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
	}

    void Draw(std::string text, glm::vec2 position, float scale, glm::vec4 color)
    {
        shader.Use();
        shader.SetVec4("textColor", color);
        glActiveTexture(GL_TEXTURE0);
        glBindVertexArray(VAO);

        std::string::const_iterator c;
        for (c = text.begin(); c != text.end(); c++)
        {
            Character ch = Characters[*c];

            float w = ch.Size.x * scale;
            float h = ch.Size.y * scale;
            float xpos = position.x + ch.Bearing.x * scale;
            float ypos = -position.y - 32 * scale - (ch.Size.y - ch.Bearing.y) * scale;

            float vertices[6][4] = {
                { xpos,     ypos + h,   0.0f, 0.0f },
                { xpos,     ypos,       0.0f, 1.0f },
                { xpos + w, ypos,       1.0f, 1.0f },

                { xpos,     ypos + h,   0.0f, 0.0f },
                { xpos + w, ypos,       1.0f, 1.0f },
                { xpos + w, ypos + h,   1.0f, 0.0f }
            };
            glBindTexture(GL_TEXTURE_2D, ch.TextureID);
            glBindBuffer(GL_ARRAY_BUFFER, VBO);
            glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);

            glBindBuffer(GL_ARRAY_BUFFER, 0);
            glDrawArrays(GL_TRIANGLES, 0, 6);
            position.x += (ch.Advance >> 6) * scale;
        }
        glBindVertexArray(0);
        glBindTexture(GL_TEXTURE_2D, 0);
    }
};