#include "RelativeLock.h"
#include <iostream>
RelativeLock::RelativeLock(float distance, float height, FpsCam* parent) {
	this->distance = distance;
	this->parent = parent;
	this->height = height;
}

void RelativeLock::update(float deltaTime) {
	this->gameObject->position.x = -this->parent->position.x + glm::degrees(sin(this->parent->rotation.y)) * distance;
	this->gameObject->position.z = -this->parent->position.z -glm::degrees(cos(this->parent->rotation.y)) * distance;
	this->gameObject->position.y = this->height;
	this->gameObject->rotation.y = -this->parent->rotation.y;
}