#pragma once
#include "DrawComponent.h"
#include "GameObject.h"
#include "tigl.h"
#include <iostream>
/*
	Draws a cube on the screen with the given
	radius and color. This class has no pointers
	so no destructors/copy assignments are needed.
*/
class Cube : public DrawComponent
{
private:
	std::vector<tigl::Vertex> verts;
public:
	Cube(float size, glm::vec4 color);
	void draw();
};

