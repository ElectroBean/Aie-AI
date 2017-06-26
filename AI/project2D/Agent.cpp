#include "Agent.h"
#include "IBehaviour.h"
#include <random>

Agent::Agent()
{
	
}

Agent::Agent(Vector2 position)
{
	this->position = position;
}


Agent::~Agent()
{
}

void Agent::AddForce(Vector2 a_force)
{
	acceleration = acceleration + a_force;
}

void Agent::update(float deltaTime)
{
	for (auto iter = behaviours.begin(); iter != behaviours.end(); iter++)
	{
		(*iter)->Update(deltaTime, this);
	}

	AddForce(velocity * -1.0f);
	position = position + velocity * deltaTime;
	velocity = velocity + acceleration * deltaTime;

	acceleration = Vector2(0, 0);
}

void Agent::AddBehaviours(IBehaviour * behaviour)
{
	this->behaviours.push_back(behaviour);
}
