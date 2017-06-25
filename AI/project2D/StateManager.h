#pragma once
#include "IBehaviour.h"

class State;

class StateManager :
	public IBehaviour
{
public:
	StateManager();
	~StateManager();

	virtual void Update(float deltaTime, Agent* agent);
	void changeState(Agent* agent, State* state);

	State* getCurrentState();
	State* getPreviousState();

private:
	State* currentState;
	State* previousState;
};

