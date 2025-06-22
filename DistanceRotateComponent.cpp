#include "DistanceRotateComponent.h"

DistanceRotateComponent::DistanceRotateComponent(float distance, float speed) {
	this->distance = distance;
	this->speed = speed;
}

void DistanceRotateComponent::update(float deltaTime) {
	this->time += deltaTime;
	this->gameObject->position.x = sin(this->time * speed) * distance;
	this->gameObject->position.z = cos(this->time * speed) * distance;
}