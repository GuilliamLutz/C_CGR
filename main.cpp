#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "tigl.h"
#include <glm/gtc/matrix_transform.hpp>
#include "GameObject.h"
#include "Galaxy.h"
#include "FpsCam.h"
#include "GraphicModel.h"
#include "RelativeLock.h"
using tigl::Vertex;

#pragma comment(lib, "glfw3.lib")
#pragma comment(lib, "glew32s.lib")
#pragma comment(lib, "opengl32.lib")

FpsCam* cam;
GLFWwindow* window;
std::vector<GameObject*> gameObjects;
float lastTimestamp;

void init();
void update();
void draw();

int main(void)
{
    if (!glfwInit())
        throw "Could not initialize glwf";
    window = glfwCreateWindow(1200, 800, "Cool 3D graphics project!", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        throw "Could not initialize glwf";
    }
    glfwMakeContextCurrent(window);

    tigl::init();

    init();

	while (!glfwWindowShouldClose(window))
	{
		update();
		draw();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();


    return 0;
}


void init()
{

	
    glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        if (key == GLFW_KEY_ESCAPE)
            glfwSetWindowShouldClose(window, true);
    });
    glEnable(GL_DEPTH_TEST);
    cam = new FpsCam(window); // delete bij creeeren geld voor alle news

    Galaxy galaxy = Galaxy(); //feedback =galaxy override weghalen
    gameObjects = galaxy.Generate(gameObjects);

    GameObject* spaceship = new GameObject();
    spaceship->addComponent(new GraphicModel("models/ship/shipA_OBJ.obj"));
    spaceship->addComponent(new RelativeLock(0.75f, 1.5f, cam));
    gameObjects.push_back(spaceship);

    ////Fog settings
    tigl::shader->enableFog(true);
    tigl::shader->setFogLinear(1, 10000);

    //lighting settings
    tigl::shader->enableLighting(true);
    tigl::shader->setLightCount(1);

    tigl::shader->setLightDirectional(0, false);
    tigl::shader->setLightPosition(0, glm::vec3(0, 375, 0));
    tigl::shader->setLightAmbient(0, glm::vec3(0.1f, 0.1f, 0.15f));
    tigl::shader->setLightDiffuse(0, glm::vec3(0.8f, 0.8f, 0.8f));
    tigl::shader->setLightSpecular(0, glm::vec3(0, 0, 0));
    tigl::shader->setShinyness(32.0f);
}


void update()
{
    float time = glfwGetTime();
    float deltaTime = time - lastTimestamp;
    lastTimestamp = time;
    cam->update(window);

    for (auto& obj : gameObjects) {
        obj->update(deltaTime);
    }
}

void draw()
{
    glClearColor(0.3f, 0.4f, 0.6f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    int viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);
    glm::mat4 projection = glm::perspective(glm::radians(100.0f), viewport[2] / (float)viewport[3], 0.01f, 10000.0f);

    tigl::shader->setProjectionMatrix(projection);
    tigl::shader->setViewMatrix(cam->getMatrix());
    tigl::shader->setModelMatrix(glm::mat4(1.0f));

    for (auto& obj : gameObjects) {
        obj->draw();
    }
}