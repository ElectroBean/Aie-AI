#pragma once
#include "State.h"
class PursueState :
	public State
{
public:
	PursueState();
	~PursueState();

	void onEnter(Agent* agent);
	void onExit(Agent* agent);
	void update(float deltaTime, Agent* agent, StateManager* sm);

private:
	Agent* target;
	float maxSpeed;
};

