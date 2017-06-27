#include "WanderState.h"



WanderState::WanderState(Agent* agent, float wanderRadius, float wanderDistance, float jitterAmount, float maxSpeed)
{
	this->wanderDistance = wanderDistance;
	this->wanderRadius = wanderRadius;
	this->jitterAmount = jitterAmount;
	this->maxSpeed = maxSpeed;
	previousTarget = agent->GlobalTransform;
}


WanderState::~WanderState()
{
}

void WanderState::onEnter(Agent * agent)
{

}

void WanderState::onExit(Agent * agent)
{

}

void WanderState::update(float deltaTime, Agent * agent, StateManager * sm)
{
	
}
