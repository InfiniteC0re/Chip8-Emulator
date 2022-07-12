#version 410

in vec2 UV;

out vec4 color;

uniform sampler2D tex0;

void main()
{
	if (texture(tex0, UV).r > 0)
	{
		color = vec4(0.98, 0., 0.247, 1.0);
	}
	else
	{
		color = vec4(0.063, 0.271, 0.278, 1.0);
	}
}