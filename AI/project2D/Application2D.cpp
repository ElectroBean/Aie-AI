#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "StateManager.h"
#include "SeekState.h"
#include "PatrolState.h"
#include <time.h>
#include "ArriveState.h"
#include "WanderState.h"

Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() {

	srand((unsigned int)time(NULL));
	m_2dRenderer = new aie::Renderer2D();

	m_texture = new aie::Texture("./textures/numbered_grid.tga");
	m_shipTexture = new aie::Texture("./textures/ship.png");

	float winHeight = getWindowHeight();
	float winWidth = getWindowWidth();
	graph = new Graph(37, 21, winHeight);
	//path = graph->aStarSearch(graph->nodes[20], graph->nodes[210]);

	m_cameraX = 0;
	m_cameraY = 0;
	m_agent.push_back(new Agent(Vector3(100, 200, 0), new aie::Texture("./textures/car.png")));
	m_agent.push_back(new Agent(Vector3(1280 / 2, 720 / 2, 0), new aie::Texture("./textures/ship.png")));
	m_agent.push_back(new Agent(Vector3(500, 500, 0), new aie::Texture("./textures/car.png")));

	FSM = new StateManager();
	FSM2 = new StateManager();
	m_agent[0]->AddBehaviours(new FollowMouse());
	m_agent[1]->AddBehaviours(FSM);
	m_agent[2]->AddBehaviours(FSM2);
	
	FSM->changeState(m_agent[1], new WanderState(m_agent[0], 100.f, 0.01f, 100.0f, 100.0f, m_agent[0]));
	

	return true;
}

void Application2D::shutdown() {

	delete m_texture;
	delete FSM;
	delete m_shipTexture;
	delete m_2dRenderer;
	for (int i = 0; i < m_agent.size(); i++)
	{
		delete m_agent[i];
	}
}

void Application2D::update(float deltaTime) {


	// input example
	aie::Input* input = aie::Input::getInstance();

	///////////////////////////////
	//
	//	update agents
	//
	///////////////////////////////
	for (auto agent : m_agent)
	{
		agent->update(deltaTime);
	}

	///////////////////////////////
	//
	//	key inputs
	//
	///////////////////////////////
	if (input->wasMouseButtonPressed(1))
	{
		int x = 0; 
		int y = 0;
		input->getMouseXY(&x, &y);
		node1 = graph->findNode(Vector3(x, y, 0), 10);
	}
	if (input->wasMouseButtonPressed(0))
	{
		int x = 0;
		int y = 0;
		input->getMouseXY(&x, &y);
		node2 = graph->findNode(Vector3(x, y, 0), 10);
	}
	if (input->wasKeyPressed(aie::INPUT_KEY_SPACE))
	{
		for (auto n : graph->nodes)
		{
			n->highlighted = false;
			n->visited = false;
			for (auto e : n->connections)
			{
				e->highlighted = false;
			}
		}
		path = graph->aStarSearch(node1, node2);
		FSM2->changeState(m_agent[2], new PathFind(m_agent[2], path, 150));
	}
	if (input->isKeyDown(aie::INPUT_KEY_LEFT_SHIFT))
	{
		int x = 0;
		int y = 0;
		input->getMouseXY(&x, &y);
		Graph::node* node = graph->findNode(Vector3(x, y, 0), 10);
		if(node != nullptr)
		node->traversable = false;
	}
	



	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// set the camera position before we begin rendering
	m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);

	// begin drawing sprites
	m_2dRenderer->begin();

	graph->Draw(m_2dRenderer);


	for (auto agent : m_agent)
	{
		agent->Draw(m_2dRenderer);
	}
	//m_2dRenderer->drawSprite(m_shipTexture, m_agent[0]->GlobalTransform.position.x, m_agent[0]->GlobalTransform.position.y, 32, 32, 0, 0);
	//m_2dRenderer->drawSprite(m_shipTexture, m_agent[1]->GlobalTransform.position.x, m_agent[1]->GlobalTransform.position.y, 32, 32, 0, 0);
	// done drawing sprites
	m_2dRenderer->end();
}