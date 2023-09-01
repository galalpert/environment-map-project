#pragma once

#include <lenny/gui/Application.h>
#include <lenny/gui/Model.h>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

namespace lenny {

class TestApp : public gui::Application {
public:
    TestApp();
    ~TestApp() = default;

    //--- Drawing
    void drawScene(bool mode);
    void drawGui() override;
    void drawGuizmo() override;

    //--- Interaction
    void mouseButtonCallback(double xPos, double yPos, Ray ray, int button, int action);
    void fileDropCallback(int count, const char** fileNames);

public:
    Eigen::Vector4d rendererColor = Eigen::Vector4d(0.75, 0.75, 0.75, 1.0);
    bool showMaterials = true;
    bool changeScenery = false;
    bool drawModels = true;
    std::vector<std::string> imagePath = {"sea", "outter_building", "solid", "planet", "white"};
    std::string currentSelection = imagePath[0];

    struct AppModel {
        AppModel(const std::string& filePath, const Eigen::Vector3d& position, const Eigen::QuaternionD& orientation, const double& scale)
            : mesh(filePath), position(position), orientation(orientation), scale(scale * Eigen::Vector3d::Ones()) {}

        gui::Model mesh;
        Eigen::Vector3d position;
        Eigen::QuaternionD orientation;
        Eigen::Vector3d scale;
    };
    std::vector<AppModel> models = {
        /* AppModel(LENNY_GUI_TESTAPP_FOLDER "/config/yumi/Base.obj", Eigen::Vector3d(-1.0, 0.5, 0.0),
                 Eigen::QuaternionD(tools::utils::rotY(-PI / 2.0) * tools::utils::rotX(-PI / 2.0)), 1.0),
        AppModel(LENNY_GUI_TESTAPP_FOLDER "/config/gripper/Gripper.obj", Eigen::Vector3d(-0.5, 0.5, 0.0), Eigen::QuaternionD::Identity(), 3.0),
        AppModel(LENNY_GUI_TESTAPP_FOLDER "/config/nao/12211_Robot_l2.obj", Eigen::Vector3d(0.0, 0.5, 0.0), Eigen::QuaternionD(tools::utils::rotX(-PI / 2.0)),
                 0.03),
        AppModel(LENNY_GUI_TESTAPP_FOLDER "/config/widowx/Base.stl", Eigen::Vector3d(0.5, 0.5, 0.0), Eigen::QuaternionD(tools::utils::rotX(-PI / 2.0)), 0.003),
        AppModel(LENNY_GUI_TESTAPP_FOLDER "/config/spot/Body.dae", Eigen::Vector3d(1.0, 0.5, 0.0), Eigen::QuaternionD::Identity(), 1.0)*/

        //AppModel(LENNY_GUI_TESTAPP_FOLDER "/config/star2/uploads_files_4052472_Stylized+Planets.obj", Eigen::Vector3d(-1.0, 0.5, 0.0),
                 //Eigen::QuaternionD(tools::utils::rotY(-PI / 2.0) * tools::utils::rotX(-PI / 2.0)), 1.0),
        AppModel(LENNY_GUI_TESTAPP_FOLDER "/config/Pyramid/pyramid2.obj", Eigen::Vector3d(0.0, 0.5, 0.0), Eigen::QuaternionD(tools::utils::rotY(PI)), 0.0001),
        AppModel(LENNY_GUI_TESTAPP_FOLDER "/config/cube/cube.obj", Eigen::Vector3d(0.0, 0.5, 0.0), Eigen::QuaternionD(tools::utils::rotX(-PI / 2.0)),
                 1.0),
        AppModel(LENNY_GUI_TESTAPP_FOLDER "/config/Tire/tire.obj", Eigen::Vector3d(0.0, 0.5, 0.0), Eigen::QuaternionD(tools::utils::rotX(-PI / 2.0)),
                 0.01),
        AppModel(LENNY_GUI_TESTAPP_FOLDER "/config/star2/EarthOrb.obj", Eigen::Vector3d(0.0, 0.5, 0.0), Eigen::QuaternionD(tools::utils::rotX(-PI / 2.0)),
                 10.0),
        AppModel(LENNY_GUI_TESTAPP_FOLDER "/config/spaceship/UFO.obj", Eigen::Vector3d(-1.0, 0.5, 0.0),
                 Eigen::QuaternionD(tools::utils::rotY(-PI / 2.0)), 1.0)
    };
    AppModel* selectedModel = nullptr;
    float radian = 0;
    int selectedObject = 0;
    bool play = true;
};


}  // namespace lenny