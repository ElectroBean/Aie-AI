#include "Agent.h"
#include "IBehaviour.h"


Agent::Agent()
{
}

Agent::Agent(glm::vec2 position)
{
	this->position = position;
}


Agent::~Agent()
{
}

void Agent::AddForce(glm::vec2 a_force)
{
	acceleration += a_force;
}

void Agent::update(float deltaTime)
{
	for (auto iter = behaviours.begin(); iter != behaviours.end(); iter++)
	{
		(*iter)->Update(deltaTime, this);
	}

	AddForce(velocity * -1.0f);
	position += velocity * deltaTime;
	velocity += acceleration * deltaTime;

	acceleration = glm::vec2(0, 0);

}

void Agent::AddBehaviours(IBehaviour * behaviour)
{
	this->behaviours.push_back(behaviour);
}
