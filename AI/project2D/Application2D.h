#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Audio.h"
#include <vector>
#include <iostream>
#include "Agent.h"
#include "KeyboardController.h"
#include "FollowMouse.h"
#include "Graph.h"
#include <vector>
#include "PathFind.h"

class StateManager;

class Application2D : public aie::Application {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Texture*		m_texture;
	aie::Texture*		m_shipTexture;
	

	float m_cameraX, m_cameraY;
	std::vector<Agent*>	m_agent;
	StateManager* FSM;
	StateManager* FSM2;
	Graph* graph;
	Graph::node* node1;
	Graph::node* node2;
	std::vector<Vector3> path;
};