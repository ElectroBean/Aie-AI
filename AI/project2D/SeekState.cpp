#include "SeekState.h"
#include "IdleState.h"


SeekState::SeekState(Vector2* target, float maxSpeed)
{
	this->target = target;
	this->maxSpeed = maxSpeed;
}


SeekState::~SeekState()
{
}

void SeekState::onEnter(Agent * agent)
{

}

void SeekState::onExit(Agent * agent)
{

}

void SeekState::update(float deltaTime, Agent * agent, StateManager * sm)
{
	Vector2 dir = *target - agent->position;
	dir.normalise();
	dir = dir * maxSpeed;

	agent->velocity = dir;

	if (Vector2::distance(agent->position, *target) > 250.0f)
		//change states if the distance between agent and target is above 250 units
		sm->changeState(agent, new IdleState(target, maxSpeed));
}
