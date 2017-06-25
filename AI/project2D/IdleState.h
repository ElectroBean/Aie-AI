#pragma once
#include "State.h"
class IdleState :
	public State
{
public:
	IdleState(glm::vec2* target, float maxSpeed);
	void onEnter(Agent* agent);
	void onExit(Agent* agent);
	void update(float deltaTime, Agent* agent, StateManager* sm);
	~IdleState();

private: 
	glm::vec2* target;
	float maxSpeed;
	glm::vec2* searchPosition;
	bool directionX;
	bool directionY;
};

