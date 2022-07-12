#pragma once
#include <renderer/VAO.h>
#include <renderer/VBO.h>
#include <renderer/EBO.h>
#include <renderer/ShaderUtil.h>

#define SPRITE_WIDTH 8

#define DISPLAY_WIDTH 64
#define DISPLAY_HEIGHT 32
#define DISPLAY_SIZE (DISPLAY_WIDTH * DISPLAY_HEIGHT)

class Display
{
public:
	Display();
	Display(const Display&) = delete;
	~Display() = default;

	/* Cleans the screen */
	void Clear();

	/* Returns screen */
	inline uint8_t* GetScreen() { return m_screen; };

	/* Updates texture */
	void Update();

	/* Render display */
	void Render();

private:
	uint8_t m_screen[DISPLAY_SIZE];

	VAO m_vao;
	VBO m_vbo;
	EBO m_ebo;
	ShaderUtil m_shader;
	GLuint m_texture;
};

