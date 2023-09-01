#include "TestApp.h"
#include <lenny/gui/Utils.h>
#include <lenny/tools/Utils.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/matrix_decompose.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <lenny/gui/Guizmo.h>
#include <lenny/gui/ImGui.h>
#include <lenny/gui/Shaders.h>
#include <iostream>
#include <stb_image.h>
#include <string>




namespace lenny {

TestApp::TestApp() : gui::Application("TestApp") {
    //Setup scene
    const auto [width, height] = getCurrentWindowSize();
    scenes.emplace_back(std::make_shared<gui::Scene>("Scene-1", width, height));
    scenes.back()->f_drawScene = [&](bool mode) -> void { drawScene(mode); };
    scenes.back()->f_mouseButtonCallback = [&](double xPos, double yPos, Ray ray, int button, int action) -> void {
        mouseButtonCallback(xPos, yPos, ray, button, action);
    };
    scenes.back()->f_fileDropCallback = [&](int count, const char** fileNames) -> void { fileDropCallback(count, fileNames); };
}

void TestApp::drawScene(bool mode) {
    if (!drawModels)
        return;
    std::optional<Eigen::Vector3d> modelColor = std::nullopt;
    if (!showMaterials)
        modelColor = rendererColor.segment(0, 3);
    if (changeScenery == false)
    {
        if (play) {
            radian += 0.005f;
        }
            if (radian >= PI)
                radian = -PI;
            models[models.size() - 2].mesh.draw(models[models.size() - 2].position, models[models.size() - 2].orientation, models[models.size() - 2].scale,
                                                modelColor, rendererColor[3]);
            float x = 15.0f * glm::cos(radian) + models[models.size() - 2].position.x();
            float z = 15.0f * glm::sin(radian) + models[models.size() - 2].position.z();
            models[models.size() - 1].orientation = Eigen::QuaternionD(tools::utils::rotY(radian));
            models[models.size() - 1].position = Eigen::Vector3d(x, models[models.size() - 2].position.y(), z);
        
        if (mode) {
            models[models.size() - 1].mesh.draw(models[models.size() - 1].position, models[models.size() - 1].orientation, models[models.size() - 1].scale,
                                                modelColor, rendererColor[3], true);
        }
        //for (int i = 0; i < models.size(); i++)  //(const AppModel& model : models)
        //{
        //    if (i == models.size() - 1) {
        //        float x = 15.0f * glm::cos(radian) + models[i - 1].position.x();
        //        float z = 15.0f * glm::sin(radian) + models[i - 1].position.z();

        //        models[i].orientation = Eigen::QuaternionD(tools::utils::rotY(radian));
        //        models[i].position = Eigen::Vector3d(x, models[i - 1].position.y(), z);
        //        if (mode)
        //            models[i].mesh.draw(models[i].position, models[i].orientation, models[i].scale, modelColor, rendererColor[3], true);
        //    } else {
        //        models[i].mesh.draw(models[i].position, models[i].orientation, models[i].scale, modelColor, rendererColor[3]);
        //    }
        //}
    }
    else
    {
        models[selectedObject].mesh.draw(models[selectedObject].position, models[selectedObject].orientation, models[selectedObject].scale, modelColor,
                                         rendererColor[3],
                                         false, true);
    //    int height = scenes.back()->getWindowSize()[1];
    //    int width = scenes.back()->getWindowSize()[0];
    //    unsigned char* pixelData = new unsigned char[width * height * 4];  // RGBA data

    //    // After the rendering loop, read the pixel data from the framebuffer
    //    glReadPixels(0, 0, width, height, GL_RGBA, GL_UNSIGNED_BYTE, pixelData);

    //    // Loop through the pixel data to find the black pixel
    //    for (int y = 0; y < height; y++) {
    //        for (int x = 0; x < width; x++) {
    //            int pixelIndex = (y * width + x) * 4;  // Each pixel has 4 bytes (RGBA)
    //            unsigned char r = pixelData[pixelIndex];
    //            unsigned char g = pixelData[pixelIndex + 1];
    //            unsigned char b = pixelData[pixelIndex + 2];
    //            // Check if the pixel is black (or close to black)
    //            if (r == 0 && g == 0 && b == 0) {
    //                printf("Found black pixel at (%d, %d)\n", x, y);
    //                // If you only want to find the first black pixel, you can return or break here
    //            }
    //        }
    //    }
    //    delete[] pixelData;
    }
    
}

void TestApp::drawGui() {
    ImGui::Begin("Menu");
    ImGui::Checkbox("Show Materials", &showMaterials);
    ImGui::Checkbox("Draw Models", &drawModels);
    ImGui::Checkbox("Change Scenery", &changeScenery);
    static int currentOption = 0;
    static float refractionRatio = 1;
    
    if (changeScenery == true)
    {   
        ImGui::Text("Choose Background:");
        if (ImGui::RadioButton("Sea", currentSelection == imagePath[0])) {
           currentSelection = imagePath[0];
        }

        if (ImGui::RadioButton("Outter Building", currentSelection == imagePath[1])) {
           currentSelection = imagePath[1];
        }

        if (ImGui::RadioButton("Solid", currentSelection == imagePath[2])) {
           currentSelection = imagePath[2];
        }

        if (ImGui::RadioButton("Horizontal Flip", currentSelection == imagePath[3])) {
           currentSelection = imagePath[3];
        }
        
        if (ImGui::RadioButton("White", currentSelection == imagePath[4])) {
           currentSelection = imagePath[4];
        }

        ImGui::Text("Choose object:");
        if (ImGui::RadioButton("Pyramid", selectedObject == 0)) {
           selectedObject = 0;
        }
        

        if (ImGui::RadioButton("Cube", selectedObject == 1)) {
           selectedObject = 1;
        }

        if (ImGui::RadioButton("Tire", selectedObject == 2)) {
           selectedObject = 2;
        }

        if (ImGui::RadioButton("Sphere", selectedObject == 3)) {
           selectedObject = 3;
        }

        
        

        static const char* options[] = {"Reflaction", "Refraction"};
        
        bool value_changed = ImGui::Combo("Choose a mode", &currentOption, options, 2);
        if (currentOption == 1)
        {
            ImGui::SliderFloat("ratio", &refractionRatio, 0, 5);
        }
        models[selectedObject].mesh.changeScenery(currentOption, refractionRatio);
    }
    else
    {
        ImGui::Checkbox("Play", &play);
    }
    scenes.back()->changeScene(changeScenery, currentSelection);
    if (!showMaterials)
        ImGui::ColorPicker4("Renderer Color", rendererColor);

    ImGui::End();
}

void TestApp::drawGuizmo() {
    if (selectedModel)
        gui::Guizmo::useWidget(selectedModel->position, selectedModel->orientation, selectedModel->scale);
}

void TestApp::mouseButtonCallback(double xPos, double yPos, Ray ray, int button, int action) {
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        selectedModel = nullptr;
        for (AppModel& model : models) {
            const auto hitInfo = model.mesh.hitByRay(model.position, model.orientation, model.scale, ray);
            if (hitInfo.has_value()) {
                selectedModel = &model;
                break;
            }
        }
    }
}

void TestApp::fileDropCallback(int count, const char** fileNames) {
    models.emplace_back(fileNames[count - 1], Eigen::Vector3d::Zero(), Eigen::QuaternionD::Identity(), 1.0);
}

}  // namespace lenny
