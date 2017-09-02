#pragma once
#include <glew\glew.h>

class CSprite
{
	float _x;
	float _y;
	int _width;
	int _height;
	GLuint _vobID;
public:
	CSprite();
	~CSprite();

	void init(float x, float y, int width, int height);
	void draw();
};

