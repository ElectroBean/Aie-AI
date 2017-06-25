#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "StateManager.h"
#include "SeekState.h"
#include "IdleState.h"

Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() {

	m_2dRenderer = new aie::Renderer2D();

	m_texture = new aie::Texture("./textures/numbered_grid.tga");
	m_shipTexture = new aie::Texture("./textures/ship.png");

	m_cameraX = 0;
	m_cameraY = 0;
	m_agent.push_back(new Agent(glm::vec2(200, 200)));
	m_agent.push_back(new Agent(glm::vec2(1280 - 32, 720 - 32)));

	FSM = new StateManager();
	m_agent[0]->AddBehaviours(new FollowMouse());
	m_agent[1]->AddBehaviours(FSM);
	FSM->changeState(m_agent[1], new IdleState(&m_agent[0]->position, 50.f));

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

	m_2dRenderer->drawSprite(m_shipTexture, m_agent[0]->position.x, m_agent[0]->position.y, 32, 32, 0, 0);
	m_2dRenderer->drawSprite(m_shipTexture, m_agent[1]->position.x, m_agent[1]->position.y, 32, 32, 0, 0);
	// done drawing sprites
	m_2dRenderer->end();
}