#include "Galaxy.h"


std::vector<GameObject*> Galaxy::Generate(std::vector<GameObject*> gameObjects) {
	
	//Add sun
	//Add cube(s)
	GameObject* cube = new GameObject();
	cube->addComponent(new Cube(10.0f, glm::vec4(1, 0.5f, 0, 1.0f)));
	cube->addComponent(new DistanceRotateComponent(300.0f, 1.0f));
	cube->addComponent(new LocalRotateComponent(glm::vec3(0.0f, -5.0f, 0.0f)));
	gameObjects.push_back(cube);


	//Add planet(s)

	//sun
	GameObject* sun = new GameObject();
	sun->scale = glm::vec3(250, 250, 250);
	sun->addComponent(new GraphicModel("models/sun/sun.obj"));
	//sun->addComponent(new LocalRotateComponent(glm::vec3(5.0f, 0.0f, 0.0f)));
	sun->addComponent(new DistanceRotateComponent(0.0f, 0.40f));
	gameObjects.push_back(sun);

	//mercury
	GameObject* mercury = new GameObject();
	mercury->scale = glm::vec3(20, 20, 20);
	mercury->addComponent(new GraphicModel("models/mercury/mercury.obj"));
	mercury->addComponent(new DistanceRotateComponent(570.0f, 0.50f));
	gameObjects.push_back(mercury);

	//venus
	GameObject* venus = new GameObject();
	venus->scale = glm::vec3(5, 5, 5);
	venus->addComponent(new GraphicModel("models/venus/venus.obj"));
	venus->addComponent(new DistanceRotateComponent(650.0f, 0.60f));
	gameObjects.push_back(venus);

	//earth
	GameObject* earth = new GameObject();
	earth->scale = glm::vec3(50, 50, 50);
	earth->addComponent(new GraphicModel("models/earth/earth.obj"));
	earth->addComponent(new DistanceRotateComponent(750.0f, 0.75f));
	gameObjects.push_back(earth);

	//mars
	GameObject* mars = new GameObject();
	mars->scale = glm::vec3(28, 28, 28);
	mars->addComponent(new GraphicModel("models/mars/mars.obj"));
	mars->addComponent(new DistanceRotateComponent(850.0f, 0.85f));
	gameObjects.push_back(mars);

	//jupiter
	GameObject* jupiter = new GameObject();
	jupiter->scale = glm::vec3(500, 500, 500);
	jupiter->addComponent(new GraphicModel("models/jupiter/jupiter.obj"));
	jupiter->addComponent(new DistanceRotateComponent(1000.0f, 1.0f));
	gameObjects.push_back(jupiter);

	//saturn
	GameObject* saturn = new GameObject();
	saturn->scale = glm::vec3(400, 400, 400);
	saturn->addComponent(new GraphicModel("models/saturn/saturnus.obj"));
	saturn->addComponent(new DistanceRotateComponent(1200.0f, 1.3f));
	gameObjects.push_back(saturn);

	//uranus
	GameObject* uranus = new GameObject();
	uranus->scale = glm::vec3(200, 200, 200);
	uranus->addComponent(new GraphicModel("models/uranus/uranus.obj"));
	uranus->addComponent(new DistanceRotateComponent(1300.0f, 1.5f));
	gameObjects.push_back(uranus);

	//neptune
	GameObject* neptune = new GameObject();
	neptune->scale = glm::vec3(200, 200, 200);
	neptune->addComponent(new GraphicModel("models/neptun/neptun.obj"));
	neptune->addComponent(new DistanceRotateComponent(1400.0f, 2.0f));
	gameObjects.push_back(neptune);

	
	return gameObjects;
}
