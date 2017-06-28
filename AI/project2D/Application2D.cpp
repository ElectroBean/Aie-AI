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

	m_cameraX = 0;
	m_cameraY = 0;
	m_agent.push_back(new Agent(Vector3(100, 200, 0)));
	//m_agent.push_back(new Agent(Vector3(1280 - 32, 720 - 32, 0)));
	m_agent.push_back(new Agent(Vector3(1280 / 2, 720/ 2, 0)));

	FSM = new StateManager();
	m_agent[0]->AddBehaviours(new FollowMouse());
	m_agent[1]->AddBehaviours(FSM);
	FSM->changeState(m_agent[1], new WanderState(m_agent[0], 100.f, 0.01f, 100.0f, 100.0f));

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

	for (auto agent : m_agent)
	{
		agent->update(deltaTime);
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

	m_2dRenderer->drawSprite(m_shipTexture, m_agent[0]->GlobalTransform.position.x, m_agent[0]->GlobalTransform.position.y, 32, 32, 0, 0);
	m_2dRenderer->drawSprite(m_shipTexture, m_agent[1]->GlobalTransform.position.x, m_agent[1]->GlobalTransform.position.y, 32, 32, 0, 0);
	// done drawing sprites
	m_2dRenderer->end();
}