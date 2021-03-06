#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;

out VS_OUT {
    vec3 FragPos;
    vec3 Normal;
} vs_out;

layout (std140) uniform CameraMatrixs{
	mat4 view;
	mat4 projection;
};
uniform mat4 model;

uniform bool invertedNormals;

void main()
{
    vec4 worldPos = model * vec4(aPos, 1.0);
    vs_out.FragPos = worldPos.xyz;
    
    mat3 normalMatrix = transpose(inverse(mat3(model)));
    vs_out.Normal = normalize(normalMatrix * (invertedNormals ? -aNormal : aNormal));

    gl_Position = projection * view * worldPos;
}