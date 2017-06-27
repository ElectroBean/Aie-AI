#include "ArriveState.h"



ArriveState::ArriveState(Matrix3* target, float maxSpeed, float slowDistance)
{
	this->target = target;
	this->maxSpeed = maxSpeed;
	this->slowDistance = slowDistance;
}


ArriveState::~ArriveState()
{

}

void ArriveState::onEnter(Agent * agent)
{
}

void ArriveState::onExit(Agent * agent)
{
}

void ArriveState::update(float deltaTime, Agent * agent, StateManager * sm)
{
	Vector3 dir = target->position - agent->GlobalTransform.position;
	dir.normalise();

	float speedMult = Vector3::distance(target->position, agent->GlobalTransform.position);
	float speedMult2 = speedMult / slowDistance;

	if (speedMult2 > 1)
		speedMult2 = 1;
	else if (speedMult2 < 0)
		speedMult2 = 0;

	agent->velocity = agent->velocity + dir * deltaTime * speedMult2;
}
