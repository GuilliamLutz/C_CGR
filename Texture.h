#pragma once

#include <gl/glew.h>
#include <string>
/*
	This class loads and binds a texture. Because it
	needs a destructor to free the texture from open gl
	it also needs the two copy things.
*/
class Texture
{
	GLuint id = -1;
public:
	Texture(const std::string& fileName);
	~Texture();
	Texture(const Texture& other)
	{
		id = other.id;
	}
	Texture& operator=(const Texture& other)
	{
		if (this != &other)
		{
			id = other.id;
		}
		return *this;
	}
	void bind();
};