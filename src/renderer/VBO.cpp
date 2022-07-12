#include "stdafx.h"
#include "VBO.h"

VBO::VBO(void* vertices, size_t size, GLenum usage)
{
	glGenBuffers(1, &m_ID);
	Data(vertices, size, usage);
}

VBO::~VBO()
{
	Delete();
}

void VBO::Data(void* data, GLuint size, GLenum usage)
{
	Bind();
	glBufferData(GL_ARRAY_BUFFER, size, data, usage);
	Unbind();
}

void VBO::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, m_ID);
}

void VBO::Unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO::Delete()
{
	glDeleteBuffers(1, &m_ID);
}
