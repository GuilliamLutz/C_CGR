#pragma once

class GameObject;

class Component
{

public:
	GameObject* gameObject;
	Component();
	virtual ~Component() = 0;

	virtual void update(float deltaTime) {};

	inline void setGameObject(GameObject* gameObject) { this->gameObject = gameObject; }
};

