#version 430 core

layout (location = 0) out vec4 color;

in vec2 TexCoord;

layout(binding = 0) uniform sampler2D text;

void main()
{
    color = vec4(texture2D(text, TexCoord).rgb,1);
}