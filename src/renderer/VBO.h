#pragma once

#include <vector>

class VBO
{
public:
	GLuint m_ID;
	
	VBO(void* vertices, size_t size, GLenum usage = 0x88E4);
	~VBO();

	/* Sets data to the buffer */
	void Data(void* data, GLuint size, GLenum usage);

	/* Bind VBO */
	void Bind();

	/* Unbinds VBO */
	void Unbind();

	/* Deletes VBO */
	void Delete();
};

