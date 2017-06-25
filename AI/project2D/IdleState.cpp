#include "IdleState.h"
#include "SeekState.h"


IdleState::IdleState(glm::vec2* target, float maxSpeed)
{
	this->target = target;
	this->maxSpeed = maxSpeed;
	directionX = false;
	directionY = false;
}

IdleState::~IdleState()
{
}

void IdleState::onEnter(Agent * agent)
{
}

void IdleState::onExit(Agent * agent)
{
}

void IdleState::update(float deltaTime, Agent * agent, StateManager * sm)
{
	if (!directionX)
	{
		if (agent->position.y >= 720 - 32)
		{
			agent->AddForce(glm::vec2(-100, 0));
		}

	}

	else if (directionX)
	{
		if (agent->position.y <= 0 + 32)
		{
			agent->AddForce(glm::vec2(100, 0));
		}

	}
	else {}

	if (!directionY)
	{
		if (agent->position.x <= 0 + 32)
		{
			agent->AddForce(glm::vec2(0, -100));
		}

	}
	else if (directionY)
	{
		if (agent->position.x >= 1280 - 32)
		{
			agent->AddForce(glm::vec2(0, 100));
		}

	}
	else {}

	if ((agent->position.x <= (0 + 32)))
	{
		directionX = true;
		directionY = false;
		std::cout << "change direction" << std::endl;
	}

	if ((agent->position.x >= (1280 - 32)) && agent->position.y <= 0 + 32)
	{
		directionX = false;
		directionY = true;
		std::cout << "change direction" << std::endl;
	}

	if (agent->position.y < 720 - 32 && agent->position.y > 0 + 32
		&& agent->position.x > 0 + 32 && agent->position.x < 1280 - 32)
	{
		directionX = false;
		directionY = true;
		agent->AddForce(glm::vec2(0, 100));
	}


	if (agent->position.x < 0 + 32)
		agent->position.x = 0 + 32;
	if (agent->position.x > 1280 - 32)
		agent->position.x = 1280 - 32;
	if (agent->position.y < 0 + 32)
		agent->position.y = 0 + 32;
	if (agent->position.y > 720 - 32)
		agent->position.y = 720 - 32;

	else if (glm::distance(agent->position, *target) < 250.0f)
		sm->changeState(agent, new SeekState(target, maxSpeed));
}

