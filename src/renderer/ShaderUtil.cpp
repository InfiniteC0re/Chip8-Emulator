#include "stdafx.h"
#include "ShaderUtil.h"
#include <fstream>

ShaderUtil::ShaderUtil()
{
	m_programId = 0;
}

ShaderUtil::~ShaderUtil()
{
	Delete();
}

GLuint ShaderUtil::GetCompiledShader(GLuint shaderType, const std::string& shaderSource)
{
	GLuint shader_id = glCreateShader(shaderType);
	
	if (shader_id == 0)
	{
		fprintf(stderr, "Unable to call glCreateShader\n");
		return NULL;
	}

	const char* c_source = shaderSource.c_str();
	glShaderSource(shader_id, 1, &c_source, nullptr);
	glCompileShader(shader_id);

	GLint compileSuccess = 0;
	glGetShaderiv(shader_id, GL_COMPILE_STATUS, &compileSuccess);

	if (compileSuccess == GL_FALSE)
	{
		GLint logLength;
		glGetShaderiv(shader_id, GL_INFO_LOG_LENGTH, &logLength);
		char* log = (char*)malloc(sizeof(GLchar) * logLength);
		glGetShaderInfoLog(shader_id, logLength, nullptr, log);

		fprintf(stderr, "Unable to compile shader %s\n", c_source);
		fprintf(stderr, "Error: %s\n", log);

		free(log);
	}

	return shader_id;
}

bool ShaderUtil::Load(const std::string& vertexShaderFile, const std::string& fragmentShaderFile)
{
	std::ifstream is_vs(vertexShaderFile);
	const std::string f_vs((std::istreambuf_iterator<char>(is_vs)), std::istreambuf_iterator<char>());
	
	std::ifstream is_fs(fragmentShaderFile);
	const std::string f_fs((std::istreambuf_iterator<char>(is_fs)), std::istreambuf_iterator<char>());
	
	m_programId = glCreateProgram();

	GLuint vs = GetCompiledShader(GL_VERTEX_SHADER, f_vs);
	GLuint fs = GetCompiledShader(GL_FRAGMENT_SHADER, f_fs);
	
	if (vs == NULL || fs == NULL)
	{
		glDeleteShader(vs);
		glDeleteShader(fs);

		return false;
	}

	glAttachShader(m_programId, vs);
	glAttachShader(m_programId, fs);

	glLinkProgram(m_programId);
	glValidateProgram(m_programId);

	return true;
}

void ShaderUtil::Use()
{
	if (m_programId != NULL)
	{
		glUseProgram(m_programId);
	}
	else
	{
		fprintf(stderr, "You should create a program before using it\n");
	}
}

void ShaderUtil::Delete()
{
	if (m_programId != NULL)
	{
		glDeleteProgram(m_programId);
	}
}