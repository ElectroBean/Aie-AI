#include "FleeState.h"



FleeState::FleeState(Agent* target, float maxSpeed)
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
	Vector3 dir = agent->GlobalTransform.position - target->GlobalTransform.position;
	dir.normalise();
	dir = dir * maxSpeed;

	agent->velocity = dir;

	if (Vector3::distance(agent->GlobalTransform.position, target->GlobalTransform.position))
	{
		sm->changeState(agent, new WanderState(target, 100.f, 0.01f, 100.0f, 100.0f, target));
	}
}
