#version 460 core

in vec3 Normal;
in vec3 FragPos;
in vec2 texCoord;
in vec4 clipSpace;

out vec4 FragColor;

uniform vec3 cameraPosition;

uniform samplerCube skybox;
uniform sampler2D reflectionTexture;

void main()
{
    vec3 viewDir = normalize(cameraPosition - FragPos);
    vec3 norm = normalize(Normal);
    vec3 R = reflect(viewDir,norm);

    vec2 ndc = (clipSpace.xy/clipSpace.w) / 2.0 + 0.5;
    vec2 reflectTexCoord = vec2(ndc.x, ndc.y);

    vec4 skyboxColor = vec4(texture(skybox, R).rgb, 1.0);
    vec4 reflectColor = texture(reflectionTexture, R.xy);
    FragColor = mix(reflectColor, vec4(0,0,0,1), 0.2);
}
