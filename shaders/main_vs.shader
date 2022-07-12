#version 410

layout(location = 0) in vec2 aPos;
layout(location = 1) in vec2 aUV;

out vec2 UV;

void main()
{
	gl_Position = vec4(aPos, 0.0, 1.0);

	UV = aUV;
}