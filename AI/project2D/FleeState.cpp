#include "FleeState.h"



FleeState::FleeState(Vector2* target, float maxSpeed)
{
	this->target = target;
	this->maxSpeed = maxSpeed;
}


FleeState::~FleeState()
{
}

void FleeState::onEnter(Agent * agent)
{
}

void FleeState::onExit(Agent * agent)
{
}

void FleeState::update(float deltaTime, Agent * agent, StateManager * sm)
{
	Vector2 dir = agent->position - *target;
	dir.normalise();
	dir = dir * maxSpeed;

	agent->velocity = dir;
}
