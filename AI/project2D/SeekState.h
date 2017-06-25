#pragma once
#include "State.h"
#include <glm\glm.hpp>
#include "StateManager.h"

class SeekState :
	public State
{
public:
	SeekState(glm::vec2* target, float maxSpeed);
	~SeekState();

	void onEnter(Agent* agent);
	void onExit(Agent* agent);
	void update(float deltaTime, Agent* agent, StateManager* sm);

private:
	glm::vec2* target;
	float maxSpeed;
};

