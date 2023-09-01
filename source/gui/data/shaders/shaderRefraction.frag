#version 460 core
out vec4 FragColor;

in vec3 Normal;
in vec3 Position;

uniform vec3 cameraPosition;
uniform samplerCube skybox;
uniform float ratio;

void main()
{             
    //float ratio = 1.52 / 1.50;
    vec3 I = normalize(Position - cameraPosition);
    vec3 R = refract(I, normalize(Normal), ratio);
    FragColor = vec4(texture(skybox, R).rgb, 1.0);
}