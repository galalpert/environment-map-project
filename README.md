# Final Project Report: OpenGL Environment Mapping
## Project Overview
The primary goal of the project was to implement environment mapping techniques aimed at enhancing the visual realism of the scene.

The secondary goal was to create a sanity check that would validate the correctness of the algorithm. The project consisted of two main components:

 **Spaceship and Earth Interaction:** the spaceship orbits around Earth and serves as a reflective surface for both the surrounding environment and Earth. This component was thoughtfully designed to showcase an object that effectively reflects multiple elements, encompassing both the surrounding area and Earth. To facilitate this demonstration, interactive features like play and stop buttons were introduced, enabling users to observe the reflection on the spaceship more comprehensively.

![readme1](https://github.com/TALHS16/LennyGraphics/assets/101366820/f0d1b8be-891f-405b-9f7c-1e60a91a8206)

**Scenery Customization:** This section of the project allows users to modify the surrounding environment (skybox) and the object subject to reflection/refraction (such as a cube or sphere).
It is important to note that within this part, we conducted the sanity check, which we will expand upon later.

 ![readme2](https://github.com/TALHS16/LennyGraphics/assets/101366820/0e840dc6-52fc-4a4d-b4e1-f59ae94d4220)

 ![readme3](https://github.com/TALHS16/LennyGraphics/assets/101366820/9b533665-f68d-4901-9366-77c313c3315c)

 ![readme4](https://github.com/TALHS16/LennyGraphics/assets/101366820/3b59ec30-e553-4f2e-a81f-562f68acda55)


## Sanity Check

To ensure the accuracy of our environment map reflections, we conducted a sanity check. The aim of this check was to validate the precision of the reflection by confirming the correct placement of a single black pixel on the reflective surface. The process involved several sequential steps:

**Creating the Background:** A skybox was constructed, featuring all-white faces except for the front face, which had one black pixel.

**Placing the Cube:** 	A cube was placed on the background such that the black pixel is reflected on the cube.

**Capturing the Scene:** A screenshot of the entire scene was taken to capture the initial arrangement.

**Implementing Camera Rotation:** we created a button that rotate the camera in 180 degrees and another button that remove the model (because the camera does the rotating around the model).

**Rotating and Capturing:** The camera was rotated using the designated button, and the model was hidden to enable the rotation around the reflective surface.

**Capturing the Rotated Scene:** A second screenshot was captured to document the new configuration after camera rotation.

**Python Script Analysis:** Finally, a Python script was developed to analyze both images. This script located the black pixel in each image and calculated the anticipated position of the reflected pixel. If the pixel's position aligned between the two images, indicating successful reflection, a confirmation message was displayed.
This process demonstrated the effectiveness of our environment mapping techniques, confirming the accuracy and reliability of our reflections. 

![readme5](https://github.com/TALHS16/LennyGraphics/assets/101366820/63e0cfbb-5085-46fc-b967-042f145391e0)

## Achievements
**Environment Mapping Implementation:** Successfully implemented environment mapping techniques, achieving reflective surfaces, and enhancing realism.

**GUI Development:** Created an interactive GUI for users to navigate and interact with the 3D scene effectively.

**Sanity Check and Validation:** Developed a sanity check that validates the accuracy of environment map reflections. Conducted thorough testing and validation processes to ensure precise implementation and realistic visual effects.

**Problem Solving:** Overcame various challenges, such as rendering bugs, shader issues, and corruption problems, demonstrating problem-solving skills.

## Conclusion
The project has successfully combined OpenGL rendering techniques with environment mapping to create an interactive and visually appealing GUI. Despite encountering challenges, we managed to overcome them and achieve the project's goals. The developed features, including reflection, refraction, and a sanity check.

## More Videos Of The Project:



https://github.com/galalpert/environment-map-project/assets/101366820/92badff6-6bd8-41f0-b2b5-449e130f70b2




https://github.com/galalpert/environment-map-project/assets/101366820/6c3ae15e-f2a5-46f4-aa44-6b022b87cf19




https://github.com/galalpert/environment-map-project/assets/101366820/973d2366-b8a3-48e9-a58d-ec86a232403a


