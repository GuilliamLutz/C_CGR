#pragma once
#include <vector>
#include "GameObject.h"
#include "Cube.h"
#include "LocalRotateComponent.h"
#include "DistanceRotateComponent.h"

#include "GraphicModel.h"
class Galaxy
{
public:
	std::vector<GameObject*> Generate(std::vector<GameObject*> gameObjects);
};

