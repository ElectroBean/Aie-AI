#include "PatrolState.h"
#include "SeekState.h"
#include "FleeState.h"

PatrolState::PatrolState(Agent* target, float maxSpeed)
{
	this->target = target;
	this->maxSpeed = maxSpeed;
	directionX = false;
	directionY = false;
}

PatrolState::~PatrolState()
{
}

void PatrolState::onEnter(Agent * agent)
{
}

void PatrolState::onExit(Agent * agent)
{
}

void PatrolState::update(float deltaTime, Agent * agent, StateManager * sm)
{
	



	if (!directionX)
	{
		if (agent->GlobalTransform.position.y >= 720 - 32)
		{
			agent->AddForce(Vector3(-100, 0, 0));
		}

	}

	else if (directionX)
	{
		if (agent->GlobalTransform.position.y <= 0 + 32)
		{
			agent->AddForce(Vector3(100, 0, 0));
		}

	}
	else {}

	if (!directionY)
	{
		if (agent->GlobalTransform.position.x <= 0 + 32)
		{
			agent->AddForce(Vector3(0, -100, 0));
		}

	}
	else if (directionY)
	{
		if (agent->GlobalTransform.position.x >= 1280 - 32)
		{
			agent->AddForce(Vector3(0, 100, 0));
		}

	}
	else {}

	if ((agent->GlobalTransform.position.x <= (0 + 32)))
	{
		directionX = true;
		directionY = false;
	}

	if ((agent->GlobalTransform.position.x >= (1280 - 32))
		&& agent->GlobalTransform.position.y <= 0 + 32)
	{
		directionX = false;
		directionY = true;
	}

	if (agent->GlobalTransform.position.y < 720 - 32 && agent->GlobalTransform.position.y > 0 + 32
		&& agent->GlobalTransform.position.x > 0 + 32 && agent->GlobalTransform.position.x < 1280 - 32)
	{
		directionX = false;
		directionY = true;
		agent->AddForce(Vector3(0, 100, 0));
	}
	//target = 

	if (agent->GlobalTransform.position.x < 0 + 32)
		agent->GlobalTransform.position.x = 0 + 32;
	if (agent->GlobalTransform.position.x > 1280 - 32)
		agent->GlobalTransform.position.x = 1280 - 32;
	if (agent->GlobalTransform.position.y < 0 + 32)
		agent->GlobalTransform.position.y = 0 + 32;
	if (agent->GlobalTransform.position.y > 720 - 32)
		agent->GlobalTransform.position.y = 720 - 32;

	Vector3 Distance = agent->GlobalTransform.position - target->GlobalTransform.position;
	
	if (Distance.magnitude() < 250.0f)
		sm->changeState(agent, new SeekState(target, maxSpeed));
}

