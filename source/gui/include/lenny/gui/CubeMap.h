#pragma once

#include <vector>
#include <string>
namespace lenny::gui {
    class CubeMap {
     public:
        CubeMap();
        int loadCubemap();
        void setIsSkyBox(bool isSky);
        void setSkyboxFaces(std::string skyboxFolder);

    private:
        std::vector<std::string> skyboxFaces;  // Images for the skybox
        std::vector<std::string> planetFaces;  // Images for the planet's cubemap
        bool isSkybox = true;
    };
}  // namespace lenny::gui
