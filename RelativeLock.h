#pragma once
#include "Component.h"
#include "GameObject.h"
#include "FpsCam.h"
#include "glm/glm.hpp"

class RelativeLock : public Component
{
private:
	float distance, height;
	FpsCam* parent;
public:
	RelativeLock(float distance, float height, FpsCam* parent);
	void update(float deltaTime) override;
};

