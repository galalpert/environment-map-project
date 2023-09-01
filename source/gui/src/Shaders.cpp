#include <lenny/gui/Shaders.h>

namespace lenny::gui {

std::vector<Shader> Shaders::shaderList = {};

Shader* Shaders::activeShader = nullptr;

void Shaders::initialize() {
    shaderList.clear();
    shaderList.emplace_back(LENNY_GUI_OPENGL_FOLDER "/data/shaders/shader.vert", LENNY_GUI_OPENGL_FOLDER "/data/shaders/shader.frag");
    shaderList.emplace_back(LENNY_GUI_OPENGL_FOLDER "/data/shaders/starShader.vert", LENNY_GUI_OPENGL_FOLDER "/data/shaders/starShader.frag");
    shaderList.emplace_back(LENNY_GUI_OPENGL_FOLDER "/data/shaders/shaderReflect.vert", LENNY_GUI_OPENGL_FOLDER "/data/shaders/shaderReflect.frag");
    shaderList.emplace_back(LENNY_GUI_OPENGL_FOLDER "/data/shaders/shaderRefraction.vert", LENNY_GUI_OPENGL_FOLDER "/data/shaders/shaderRefraction.frag");
    setActiveShader(0);
}

void Shaders::update(const Camera& camera, const Light& light) {
    for (Shader shader : shaderList) {
        shader.activate();

        shader.setMat4("cameraProjection", camera.getProjectionMatrix());
        shader.setMat4("cameraView", camera.getViewMatrix());
        shader.setVec3("cameraPosition", camera.getPosition());

        shader.setVec3("lightPosition", light.getPosition());
        shader.setVec3("lightColor", light.getColor());
        shader.setVec3("lightGlow", light.getGlow());
        shader.setFloat("strength.ambient", light.ambientStrength);
        shader.setFloat("strength.diffuse", light.diffuseStrength);
        shader.setFloat("strength.specular", light.specularStrength);
    }
}

void Shaders::setActiveShader(int shader) {
    activeShader = &shaderList[shader];
}

}  // namespace lenny::gui