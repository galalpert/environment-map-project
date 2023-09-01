#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <lenny/gui/CubeMap.h>
#include <iostream>
#include <stb_image.h>

namespace lenny::gui {
 CubeMap::CubeMap() {
    setSkyboxFaces("space");

    planetFaces = {LENNY_GUI_OPENGL_FOLDER "/data/images/right_planet.jpg", LENNY_GUI_OPENGL_FOLDER "/data/images/left_planet.jpg",
                   LENNY_GUI_OPENGL_FOLDER "/data/images/top_planet.jpg",   LENNY_GUI_OPENGL_FOLDER "/data/images/bottom_planet.jpg",
                   LENNY_GUI_OPENGL_FOLDER "/data/images/front_planet.jpg", LENNY_GUI_OPENGL_FOLDER "/data/images/back_planet.jpg"};
    }

    int CubeMap::loadCubemap() {
        unsigned int textureID = 0;
        glGenTextures(1, &textureID);
        glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);

        int width, height, nrChannels;
        const std::vector<std::string>& faces = (isSkybox) ? skyboxFaces : planetFaces;
        for (unsigned int i = 0; i < faces.size(); i++) {
            unsigned char* data = stbi_load(faces[i].c_str(), &width, &height, &nrChannels, 0);
            if (data) {
                glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
                stbi_image_free(data);
            } else {
                std::cout << "Cubemap tex failed to load at path: " << faces[i] << std::endl;
                stbi_image_free(data);
            }
        }
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

        return textureID;
    }

    void CubeMap::setIsSkyBox(bool isSky) {   
        isSkybox = isSky;
        }
    void CubeMap::setSkyboxFaces(std::string skyboxFolder)
    {
        skyboxFaces = {LENNY_GUI_OPENGL_FOLDER "/data/images/" + skyboxFolder + "/right.jpg",
                       LENNY_GUI_OPENGL_FOLDER "/data/images/" + skyboxFolder + "/left.jpg ",
                       LENNY_GUI_OPENGL_FOLDER "/data/images/" + skyboxFolder + "/top.jpg",
                       LENNY_GUI_OPENGL_FOLDER "/data/images/" + skyboxFolder + "/bottom.jpg",
                       LENNY_GUI_OPENGL_FOLDER "/data/images/" + skyboxFolder + "/front.jpg",
                       LENNY_GUI_OPENGL_FOLDER "/data/images/" + skyboxFolder + "/back.jpg"};

    }
    }  // namespace lenny::gui
