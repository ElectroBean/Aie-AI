#include "SeekState.h"
#include "IdleState.h"


SeekState::SeekState(glm::vec2* target, float maxSpeed)
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
	glm::vec2 dir = *target - agent->position;
	dir = glm::normalize(dir);
	dir *= maxSpeed;

	agent->velocity = dir;

	if (glm::distance(agent->position, *target) > 250.0f)
		sm->changeState(agent, new IdleState(target, maxSpeed));
}
