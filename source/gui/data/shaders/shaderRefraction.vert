#version 460 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoords;

out vec3 Normal;
out vec3 Position;

uniform mat4 modelPose;
uniform mat4 cameraView;
uniform mat4 cameraProjection;

void main()
{
    Normal = mat3(transpose(inverse(modelPose))) * aNormal;
    Position = vec3(modelPose * vec4(aPos, 1.0));
    gl_Position = cameraProjection * cameraView * vec4(Position, 1.0);
}  