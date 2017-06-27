#include "FleeState.h"



FleeState::FleeState(Matrix3* target, float maxSpeed)
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
	Vector3 dir = agent->GlobalTransform.position - target->position;
	dir.normalise();
	dir = dir * maxSpeed;

	agent->velocity = dir;
}
