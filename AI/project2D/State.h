#pragma once
#include "Agent.h"

class StateManager;
class State
{
public:
	State();
	~State();
	virtual void onEnter(Agent* agent);
	virtual void onExit(Agent* agent);
	virtual void update(float deltaTime, Agent* agent, StateManager* manager);
};

