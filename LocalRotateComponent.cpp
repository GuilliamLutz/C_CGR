#include "LocalRotateComponent.h"

LocalRotateComponent::LocalRotateComponent(glm::vec3 rotationIncrement)
{
    this->rotationIncrement = rotationIncrement;
}

void LocalRotateComponent::update(float elapsedTime)
{
    this->gameObject->rotation += elapsedTime * rotationIncrement;
}