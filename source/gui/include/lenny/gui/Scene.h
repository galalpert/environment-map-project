#pragma once

#include <lenny/gui/Camera.h>
#include <lenny/gui/Ground.h>
#include <lenny/gui/Light.h>
#include <lenny/gui/Shaders.h>
#include <lenny/tools/Typedefs.h>

#include <lenny/gui/CubeMap.h>

#include <array>
#include <functional>


namespace lenny::gui {

class Scene {
public:
    LENNY_GENERAGE_TYPEDEFS(Scene)
    Scene(const std::string& description, const int& width, const int& height);
    ~Scene();

    //--- Drawing
    void draw();
    void drawGui();

    //--- Callbacks
    void resizeWindowCallback(int width, int height);
    void keyboardKeyCallback(int key, int action);
    void mouseButtonCallback(double xPos, double yPos, Ray ray, int button, int action);
    void mouseMoveCallback(double xPos, double yPos, Ray ray);
    void mouseScrollCallback(double xOffset, double yOffset);
    void fileDropCallback(int count, const char** fileNames);
    void changeScene(bool changeScene,std::string pathImage);

    //--- Helpers
    const Ray getRayFromScreenCoordinates(double xPos, double yPos) const;
    void copyCallbacksFromOtherScene(const Scene::CSPtr otherScene);
    void sync(const Scene::CSPtr otherScene);
    bool saveScreenshotToFile(const std::string& filePath) const;
    void LoadSkyBox();
    uint getFBO() {
        return FBO;
    }
    uint getTextureFBO() {
        return textureFBO;
    }
    uint getDepthFBO() {
        return depthFBO;
    }
    void createFrameBuffer();
    void createTextureAttachment(int width, int height);
    void createDepthTextureAttachment(int width, int height);
    void createDepthBufferAttachment(int width, int height);
    void bindFrameBuffer();
    void unbindCurrentFrameBuffer();
    void initialiseReflectionFrameBuffer();
    void cleanUp();


public:
    //--- Functions
    std::function<void(bool)> f_drawScene;
    std::function<void(int, int)> f_keyboardKeyCallback;
    std::function<void(double, double, Ray, int, int)> f_mouseButtonCallback;
    std::function<void(double, double, Ray)> f_mouseMoveCallback;
    std::function<void(double, double)> f_mouseScrollCallback;
    std::function<void(int, const char**)> f_fileDropCallback;

    const std::string description;
    Camera camera;

    std::array<float, 2> getWindowSize();

    std::array<double, 4> clearColor = {1.0, 1.0, 1.0, 1.0};
    Light light;
    Ground ground;

    bool showGround = false;
    bool showOrigin = false;

private:
    std::string currentPath;
    std::array<float, 2> windowPos = {0.f, 0.f}, windowSize = {100.f, 100.f};
    bool blockCallbacks = false;
    uint frameBuffer, texture, renderBuffer;
    int textureWidth, textureHeight;
    Shader skyboxShader;
    CubeMap myCube;
    int cubemapTexture;
    uint cubeVAO;
    uint FBO;
    uint textureFBO;
    uint depthFBO;
    uint depthBuffer;
    bool whichScene;

};

}  // namespace lenny::gui