#pragma once

class VBO;

class VAO
{
public:
	GLuint m_ID;

	VAO();
	~VAO();

	void LinkAttrib(VBO* vbo, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset);

	void Bind();

	void Unbind();

	void Delete();
};

