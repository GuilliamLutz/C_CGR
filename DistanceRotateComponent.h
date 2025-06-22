#pragma once
#include "Component.h"
#include "GameObject.h"

class DistanceRotateComponent : public Component
{
private:
	float distance, speed;
	float time = 0;
public:
	DistanceRotateComponent(float distance, float speed);
	void update(float deltaTime) override;
};

