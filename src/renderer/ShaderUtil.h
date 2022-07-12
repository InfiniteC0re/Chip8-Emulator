#pragma once
#include <string>

class ShaderUtil
{
private:
	GLuint GetCompiledShader(GLuint shaderType, const std::string& shaderSource);

public:
	ShaderUtil();
	~ShaderUtil();

	// Load a vertex shader and a fragment shader from file
	bool Load(const std::string& vertexShaderFile, const std::string& fragmentShaderFile);
	
	// Use the program
	void Use();

	// Delete the program
	void Delete();

	GLuint m_programId;
};

