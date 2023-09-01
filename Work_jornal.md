# lenny-gui-opengl
Graphical User Interface for lenny repositories based on OpenGL

## Dependencies Installation Ubuntu
- OpenGL: `sudo apt-get install libgl1-mesa-dev`
- GLFW dependencies: `sudo apt-get install libxrandr-dev libxinerama-dev libxcursor-dev libxi-dev`

# environment maps project

# Work jornal:
total work hours: 110 hours

## Week 1:
Started repo. Stared learning the base code, had issues running and compiling the basic code.Spent 8 hours.

## Week 2:
succeeded runing the testApp and started learning about cubeMaps for the environment maps. Implemented the skybox algorithm. 8 hours total.

## Week 3:
No progress due to Passover holiday

## Week 4:
finished environment maps implementation 5 hours. Added new model and backround for the concept and tested it 3 hours. total 8 hours.

https://user-images.githubusercontent.com/101366820/233074946-68608662-3ce9-487b-b9f0-f372fbd65421.mp4

![image](https://user-images.githubusercontent.com/101366820/233074711-7ae1b23a-a9fe-49d1-95fb-5faa200bfa49.png)

## Week 5:
we planed how to create sainty checks by upgrading the project idea, 4 hours. rest of the week we had holidays.

## Week 6:
implemented having only the spaceship reflective to the background, 6 hours.
we plan to give the star texture and make the spaceship reflective to it as well.
![‏‏לכידה](https://user-images.githubusercontent.com/101366820/235668254-e7f8e5ea-15e5-4162-b3f8-0b0517ff69cf.PNG)
## week 7:
we started implementing the cubemap on the star but it didnt work yet so we found a star with texture for now. 8 hours.

## week 8:
we started implementing the reflection of the star onto the spaceship but we have a but that doesnt render the objects, still need to fix it. 8 hours.

## week 9
we fixed the bug of the reflection. now the spaceship is reflective to the star and the sky. 8 hours.


https://github.com/TALHS16/LennyGraphics/assets/100534541/0b88f196-db11-4cad-b594-87325fc5caac


## week 10
we implemented a test to check our implementations - the spaceship is now orbit the planet and reflect it and the skybox. 8 hours.



https://github.com/TALHS16/LennyGraphics/assets/100534541/69706738-2185-44c2-ba0d-9fcbf7207a4a


## week 11+ 12
exams, did not work on the project.

## week 13
we searched for a new way to check the validitiy of the enviroment map. 
Our idea is to reflect and refrate our enviroment map on a sphere. when use refration on ratio 1, the image we will not see the edge
of the sphere therefore we see perfectly the object we look at. 6 hours.

## week 14
we had issues pull the project from the master, fixed after 1 hour.
To start our implementation we need to seperate the first sanity check from our new idea, 1 hour.
We implemented the reflation and refration algorithm, we had a bug when we tried to add new shaders, we though it was the build so we tried to build theproject again.
total of 10 hours.

## week 15
We realize the file was coruptted so we deleted the file and created it again.
we created a GUI to switch between the first sanity check to the new one that has new backgrounds and a reflation/ refration with ratio option for display.
total 8 hours.

https://github.com/TALHS16/LennyGraphics/assets/101366820/2935fadc-4d08-4254-808d-7f8b59635462

## week 16
we extented the second sanity check by adding multiple choice of objects. to the first sanity check we added the option
to stop the spaceship from moving to absorbe the reflection better. we checked that changing the light setting affect the reflation. 5 hours.


https://github.com/TALHS16/LennyGraphics/assets/100534541/060a9b41-6aaf-4c1c-8997-90e0bb45588c



https://github.com/TALHS16/LennyGraphics/assets/100534541/1cf31600-8ceb-4619-aa53-ba7c55552b4e

We tried another sanity check by coloring each face of the sky box with a solid color and then we can see that every pixel on the cube is colored with the right color. 1 hour 

https://github.com/TALHS16/LennyGraphics/assets/100534541/94d35698-aa0c-4b4a-8f40-9304823e31b6



we tried another sanity check by take 3 photos of the sea (left,top,front) and we copied them such that the right face will be like the left face but we did an horizontal flip of the left image. we expected that in reflect mode the cube will be assimilated in the background. 2 hours

https://github.com/TALHS16/LennyGraphics/assets/100534541/439a7c94-826c-416e-b208-feb432130dca

total 8 hours.

## week 17
After talking to our professor he told us to create white background with 1 black pixel. We thought how to check if the black pixel is correctly reflected:
1. we create the skybox
2. we placed the cube on the background such that the black pixel is reflected on the cube
3. we took a screenshot on the scene
4. we created a button that rotate the camera in 180 degrees and another button that remove the model (because the camera do the rotating around the model)
5. we rotate the camera and hide the model
6. we took the second screenshot
7. we created a python script to find the black pixel in both images and calculate the expected location of the reflected pixel if the pixel is in the same position we will see a massage (like in the image below)
total 12 hours
![WhatsApp Image 2023-08-02 at 19 28 05](https://github.com/TALHS16/LennyGraphics/assets/100534541/0849766f-2787-412c-87fa-1ce522abd68b)

![image](https://github.com/TALHS16/LennyGraphics/assets/100534541/5d8e43f3-8470-479e-a335-05705578dd3a)


