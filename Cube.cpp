#include "Cube.h"

#include "Cube.h"

Cube::Cube(float radius, glm::vec4 color)
{
	//Front
	this->verts.push_back(tigl::Vertex::PC(glm::vec3(-radius, -radius, radius), color));
	this->verts.push_back(tigl::Vertex::PC(glm::vec3(radius, -radius, radius), color));
	this->verts.push_back(tigl::Vertex::PC(glm::vec3(radius, radius, radius), color));
	this->verts.push_back(tigl::Vertex::PC(glm::vec3(-radius, radius, radius), color));
	//Right
	this->verts.push_back(tigl::Vertex::PC(glm::vec3(radius, -radius, radius), color));
	this->verts.push_back(tigl::Vertex::PC(glm::vec3(radius, -radius, -radius), color));
	this->verts.push_back(tigl::Vertex::PC(glm::vec3(radius, radius, -radius), color));
	this->verts.push_back(tigl::Vertex::PC(glm::vec3(radius, radius, radius), color));
	//Top
	this->verts.push_back(tigl::Vertex::PC(glm::vec3(-radius, radius, radius), color));
	this->verts.push_back(tigl::Vertex::PC(glm::vec3(radius, radius, radius), color));
	this->verts.push_back(tigl::Vertex::PC(glm::vec3(radius, radius, -radius), color));
	this->verts.push_back(tigl::Vertex::PC(glm::vec3(-radius, radius, -radius), color));
	//Rear
	this->verts.push_back(tigl::Vertex::PC(glm::vec3(-radius, -radius, -radius), color));
	this->verts.push_back(tigl::Vertex::PC(glm::vec3(radius, -radius, -radius), color));
	this->verts.push_back(tigl::Vertex::PC(glm::vec3(radius, radius, -radius), color));
	this->verts.push_back(tigl::Vertex::PC(glm::vec3(-radius, radius, -radius), color));
	//Left
	this->verts.push_back(tigl::Vertex::PC(glm::vec3(-radius, -radius, radius), color));
	this->verts.push_back(tigl::Vertex::PC(glm::vec3(-radius, -radius, -radius), color));
	this->verts.push_back(tigl::Vertex::PC(glm::vec3(-radius, radius, -radius), color));
	this->verts.push_back(tigl::Vertex::PC(glm::vec3(-radius, radius, radius), color));
	//Bottom
	this->verts.push_back(tigl::Vertex::PC(glm::vec3(-radius, -radius, -radius), color));
	this->verts.push_back(tigl::Vertex::PC(glm::vec3(radius, -radius, radius), color));
	this->verts.push_back(tigl::Vertex::PC(glm::vec3(radius, -radius, -radius), color));
	this->verts.push_back(tigl::Vertex::PC(glm::vec3(-radius, -radius, -radius), color));
}

void Cube::draw()
{
	tigl::begin(GL_QUADS);
	tigl::shader->enableTexture(false);
	tigl::shader->enableColor(true);
	tigl::drawVertices(GL_QUADS, this->verts);
	tigl::end();
}