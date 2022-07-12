#include "stdafx.h"
#include "EBO.h"

EBO::EBO(GLushort* indices, GLsizeiptr size)
{
	glGenBuffers(1, &m_ID);

	Bind();
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
	Unbind();
}

EBO::~EBO()
{
	Delete();
}

void EBO::Bind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
}

void EBO::Unbind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void EBO::Delete()
{
	glDeleteBuffers(1, &m_ID);
}
