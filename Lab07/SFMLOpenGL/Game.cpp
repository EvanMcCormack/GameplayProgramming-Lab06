#include <Game.h>

bool updatable = false;

//gpp::Vector3 v3;

Game::Game() : window(VideoMode(800, 600), "OpenGL Cube"),
start{
	{ 1.0f, 1.0f, -1.0f },
	{ -1.0f,1.0f,-1.0f },
	{ -1.0f, -1.0f, -1.0f },
	{ 1.0f,-1.0f,-1.0f },
	{ 1.0f,1.0f,1.0f },
	{ -1.0f,1.0f,1.0f },
	{ -1.0f,-1.0f,1.0f },
	{ 1.0f,-1.0f,1.0f }
}
{
	index = glGenLists(1);
	for (int i = 0; i < 8; i++)
	{
		vectors[i] = start[i];
	}
}

Game::~Game(){}

void Game::run()
{

	initialize();

	Event event;

	while (isRunning){

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
			if (sf::Keyboard::Z == event.key.code)
			{
				rotationZ += 0.05;
				if (rotationZ > 360)
				{
					rotationZ -= 360.0;
				}
			}
			if (sf::Keyboard::Y == event.key.code)
			{
				rotationY += 0.05;
				if (rotationY > 360)
				{
					rotationY -= 360.0;
				}
			}
			if (sf::Keyboard::X == event.key.code)
			{
				rotationX += 0.05;
				if (rotationX > 360)
				{
					rotationX -= 360.0;
				}
			}
			if (sf::Keyboard::Up == event.key.code)
			{
				m_displace.y += 0.05;
			}
			if (sf::Keyboard::Down == event.key.code)
			{
				m_displace.y -= 0.05;
			}
			if (sf::Keyboard::Left == event.key.code)
			{
				m_displace.x -= 0.05;
			}
			if (sf::Keyboard::Right == event.key.code)
			{
				m_displace.x += 0.05;
			}
			if (sf::Keyboard::S == event.key.code)
			{
				scale += 0.05;
			}
			if (sf::Keyboard::D == event.key.code)
			{
				scale -= 0.05;
			}
		}
		update();
		draw();
	}

}

void Game::initialize()
{

	isRunning = true;

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);

	// glNewList(index, GL_COMPILE);
	// Creates a new Display List
	// Initalizes and Compiled to GPU
	// https://www.opengl.org/sdk/docs/man2/xhtml/glNewList.xml
	
}

void Game::update()
{
	elapsed = clock.getElapsedTime();

	if (elapsed.asSeconds() >= 1.0f)
	{
		clock.restart();

		if (!updatable)
		{
			updatable = true;
		}
		else
			updatable = false;
	}
	if (updatable)
	{

	}

	for (int i = 0; i < 8; i++)
	{
		vectors[i] = MyMatrix3::rotationY(rotationY) * start[i];
		vectors[i] = MyMatrix3::rotationX(rotationX) * vectors[i];
		vectors[i] = MyMatrix3::rotationZ(rotationZ) * vectors[i];
		vectors[i] = MyMatrix3::scale(scale) * vectors[i];
		vectors[i] += m_displace;
	}
	cout << "Update up" << endl;
}

void Game::draw()
{
	cout << "Drawing" << endl;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	cout << "Drawing Cube " << endl;
	newBox();
	//glLoadIdentity();
	//glRotatef(rotationAngle, 0, 0, 1); // Rotates the camera on Y Axis

	glCallList(1);

	window.display();

}

void Game::newBox()
{
	glDeleteLists(1, 1);

	glNewList(index, GL_COMPILE);
	glBegin(GL_QUADS);
	{
		//Front Face
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(vectors[0].x, vectors[0].y, vectors[0].z);
		glVertex3f(vectors[1].x, vectors[1].y, vectors[1].z);
		glVertex3f(vectors[2].x, vectors[2].y, vectors[2].z);
		glVertex3f(vectors[3].x, vectors[3].y, vectors[3].z);

		//Back Face
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(vectors[4].x, vectors[4].y, vectors[4].z);
		glVertex3f(vectors[5].x, vectors[5].y, vectors[5].z);
		glVertex3f(vectors[6].x, vectors[6].y, vectors[6].z);
		glVertex3f(vectors[7].x, vectors[7].y, vectors[7].z);

		//Complete the faces of the Cube
		//Top
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(vectors[0].x, vectors[0].y, vectors[0].z);
		glVertex3f(vectors[1].x, vectors[1].y, vectors[1].z);
		glVertex3f(vectors[5].x, vectors[5].y, vectors[5].z);
		glVertex3f(vectors[4].x, vectors[4].y, vectors[4].z);
		//Left
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f(vectors[1].x, vectors[1].y, vectors[1].z);
		glVertex3f(vectors[2].x, vectors[2].y, vectors[2].z);
		glVertex3f(vectors[6].x, vectors[6].y, vectors[6].z);
		glVertex3f(vectors[5].x, vectors[5].y, vectors[5].z);
		//Right
		glColor3f(1.0f, 0.0f, 1.0f);
		glVertex3f(vectors[0].x, vectors[0].y, vectors[0].z);
		glVertex3f(vectors[3].x, vectors[3].y, vectors[3].z);
		glVertex3f(vectors[7].x, vectors[7].y, vectors[7].z);
		glVertex3f(vectors[4].x, vectors[4].y, vectors[4].z);
		//Bottom
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex3f(vectors[2].x, vectors[2].y, vectors[2].z);
		glVertex3f(vectors[3].x, vectors[3].y, vectors[3].z);
		glVertex3f(vectors[7].x, vectors[7].y, vectors[7].z);
		glVertex3f(vectors[6].x, vectors[6].y, vectors[6].z);

	}
	glEnd();
	glEndList();
}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

