#pragma once
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <Vector3.h>
#include "MyMatrix3.h"
#include "MyVector3.h"


using namespace std;
using namespace sf;
using namespace gpp;

class Game
{
public:
	Game();
	~Game();
	void run();
private:
	Window window;
	bool isRunning = false;
	void initialize();
	void update();
	void draw();
	void newBox();
	void unload();

	MyVector3 start[8];
	MyVector3 v0{ 1.0f, 1.0f, -1.0f };
	MyVector3 v1{ -1.0f,1.0f,-1.0f };
	MyVector3 v2{ -1.0f, -1.0f, -1.0f };
	MyVector3 v3{ 1.0f,-1.0f,-1.0f };

	MyVector3 v4{ 1.0f,1.0f,1.0f };
	MyVector3 v5{ -1.0f,1.0f,1.0f };
	MyVector3 v6{ -1.0f,-1.0f,1.0f };
	MyVector3 v7{ 1.0f,-1.0f,1.0f };

	MyVector3 vectors[8];

	MyVector3 m_displace{ 0, 0, -6 };

	GLuint index;
	Clock clock;
	Time elapsed;

	float rotationX = 0.0f;
	float rotationY = 0.0f;
	float rotationZ = 0.0f;
	double scale{ 1.0 };
};