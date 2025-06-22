#pragma once
#include "Component.h"
#include "GameObject.h"
#include "glm/glm.hpp"

class LocalRotateComponent : public Component
{
private:
    glm::vec3 rotationIncrement;
public:
    LocalRotateComponent(glm::vec3 rotationIncrement);
    void update(float deltaTime) override;
};