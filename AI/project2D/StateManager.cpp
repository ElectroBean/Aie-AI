#include "StateManager.h"
#include "State.h"


StateManager::StateManager()
{
	currentState = nullptr;
	previousState = nullptr;
}


StateManager::~StateManager()
{
}

void StateManager::Update(float deltaTime, Agent* agent)
{
	if (currentState != nullptr)
		currentState->update(deltaTime, agent, this);
}

void StateManager::changeState(Agent * agent, State * state)
{
	if (currentState != nullptr)
		currentState->onExit(agent);

	if (state != nullptr)
		state->onEnter(agent);

	previousState = currentState;
	currentState = state;
}

State * StateManager::getCurrentState()
{
	return currentState;
}

State * StateManager::getPreviousState()
{
	return previousState;
}
