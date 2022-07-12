#include "stdafx.h"
#include "Display.h"

struct Vertex
{
	glm::vec2 pos;
	glm::vec2 uv;
};

namespace Plane
{
	static Vertex vertices[] = {
		Vertex { glm::vec2(-1.0f, -1.0f), glm::vec2(0.0f, 0.0f) },
		Vertex { glm::vec2(-1.0f, 1.0f), glm::vec2(0.0f, -1.0f) },
		Vertex { glm::vec2(1.0f, -1.0f), glm::vec2(1.0f, 0.0f) },
		Vertex { glm::vec2(1.0f, 1.0f), glm::vec2(1.0f, -1.0f) },
	};

	static GLushort indices[] = { 0, 1, 2, 3 };
}

Display::Display() :
	m_vbo(Plane::vertices, sizeof(Plane::vertices)),
	m_ebo(Plane::indices, sizeof(Plane::indices))
{
	// initialization 
	Display::Clear();

	// loading and compiling shader
	m_shader.Load("shaders/main_vs.shader", "shaders/main_fs.shader");
	
	// VAO attributes
	m_vao.Bind();
	m_vao.LinkAttrib(&m_vbo, 0, 2, GL_FLOAT, sizeof(Vertex), (void*)offsetof(Vertex, pos));
	m_vao.LinkAttrib(&m_vbo, 1, 2, GL_FLOAT, sizeof(Vertex), (void*)offsetof(Vertex, uv));
	
	// unbinding VAO
	m_vao.Unbind();

	// generating texture 
	glGenTextures(1, &m_texture);
	glActiveTexture(GL_TEXTURE0);

	// binding texture
	glBindTexture(GL_TEXTURE_2D, m_texture);

	// texture parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	// saving data
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, DISPLAY_WIDTH, DISPLAY_HEIGHT, 0, GL_RED, GL_UNSIGNED_BYTE, m_screen);

	// since we only have one mesh we don't have to bind and unbind buffers
	// and the texture every frame, so just binding them once right here
	m_shader.Use();
	m_vao.Bind();
	m_ebo.Bind();
}

void Display::Clear()
{
	memset(m_screen, 0, sizeof(m_screen));
}

void Display::Update()
{
	// updating texture data
	glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, DISPLAY_WIDTH, DISPLAY_HEIGHT, GL_RED, GL_UNSIGNED_BYTE, m_screen);
}

void Display::Render()
{
	// rendering the plane
	glDrawElements(GL_TRIANGLE_STRIP, 4, GL_UNSIGNED_SHORT, 0);
}
