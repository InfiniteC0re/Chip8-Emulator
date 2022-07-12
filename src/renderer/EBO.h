#pragma once

class EBO
{
public:
	GLuint m_ID;

	EBO(GLushort* indices, GLsizeiptr size);

	~EBO();

	void Bind();

	void Unbind();

	void Delete();
};

